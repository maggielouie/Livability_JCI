<?php
/* 
 * Straight ganked from davyvdb's E-mail Marketing Framework module : https://www.drupal.org/project/emf 
 * modifications to remove un-used features
 */
class MCAPI {
    var $version = "1.2";
    var $errorMessage;
    var $errorCode;
    
    /**
     * Cache the information on the API location on the server
     */
    var $apiUrl;
    
    /**
     * Default to a 300 second timeout on server calls
     */
    var $timeout = 300; 
    
    /**
     * Default to a 8K chunk size
     */
    var $chunkSize = 8192;
    
    /**
     * Cache the user api_key so we only have to log in once per client instantiation
     */
    var $api_key;

    /**
     * Cache the user api_key so we only have to log in once per client instantiation
     */
    var $secure = false;
    
    /**
     * Connect to the MailChimp API for a given list. All MCAPI calls require login before functioning
     * 
     * @param string $username_or_apikey Your MailChimp login user name OR apikey - always required
     * @param string $password Your MailChimp login password - only required when username passed instead of API Key
     */
    function MCAPI($username_or_apikey, $password=null, $secure=false) {
        //do more "caching" of the uuid for those people that keep instantiating this...
        $this->secure = $secure;
        $this->apiUrl = parse_url("http://api.mailchimp.com/" . $this->version . "/?output=php");
        if ( isset($GLOBALS["mc_api_key"]) && $GLOBALS["mc_api_key"]!="" ){
            $this->api_key = $GLOBALS["mc_api_key"];
        } elseif( $username_or_apikey && !$password ){
            $this->api_key = $GLOBALS["mc_api_key"] = $username_or_apikey;
        }  else {
            $this->api_key = $this->callServer("login", array("username" => $username_or_apikey, "password" => $password));
            $GLOBALS["mc_api_key"] = $this->api_key;
        }
    }
    function setTimeout($seconds){
        if (is_int($seconds)){
            $this->timeout = $seconds;
            return true;
        }
    }
    function getTimeout(){
        return $this->timeout;
    }
    function useSecure($val){
        if ($val===true){
            $this->secure = true;
        } else {
            $this->secure = false;
        }
    }
    

    /**
     * Subscribe the provided email to a list. By default this sends a confirmation email - you will not see new members until the link contained in it is clicked!
     *
     * @section List Related
     *
     * @example mcapi_listSubscribe.php
     * @example xml-rpc_listSubscribe.php
     *
     * @param string $id the list id to connect to. Get by calling lists()
     * @param string $email_address the email address to subscribe
     * @param array $merge_vars array of merges for the email (FNAME, LNAME, etc.) (see examples below for handling "blank" arrays). Note that a merge field can only hold up to 255 characters. Also, there are 2 "special" keys:
                        string INTERESTS Set Interest Groups by passing a field named "INTERESTS" that contains a comma delimited list of Interest Groups to add. Commas in Interest Group names should be escaped with a backslash. ie, "," =&gt; "\,"
                        string OPTINIP Set the Opt-in IP fields. <em>Abusing this may cause your account to be suspended.</em> We do validate this and it must not be a private IP address.
                        
                        <strong>Handling Field Data Types</strong> - most fields you can just pass a string and all is well. For some, though, that is not the case...
                        Field values should be formatted as follows:
                        string address For the string version of an Address, the fields should be delimited by <strong>2</strong> spaces. Address 2 can be skipped. The Country should be a 2 character ISO-3166-1 code and will default to your default country if not set
                        array address For the array version of an Address, the requirements for Address 2 and Country are the same as with the string version. Then simply pass us an array with the keys <strong>addr1</strong>, <strong>addr2</strong>, <strong>city</strong>, <strong>state</strong>, <strong>zip</strong>, <strong>country</strong> and appropriate values for each
    
                        string date use YYYY-MM-DD to be safe. Generally, though, anything strtotime() understands we'll understand - <a href="http://us2.php.net/strtotime" target="_blank">http://us2.php.net/strtotime</a>
                        string dropdown can be a normal string - we <em>will</em> validate that the value is a valid option
                        string image must be a valid, existing url. we <em>will</em> check its existence
                        string multi_choice can be a normal string - we <em>will</em> validate that the value is a valid option
                        double number pass in a valid number - anything else will turn in to zero (0). Note, this will be rounded to 2 decimal places
                        string phone If your account has the US Phone numbers option set, this <em>must</em> be in the form of NPA-NXX-LINE (404-555-1212). If not, we assume an International number and will simply set the field with what ever number is passed in.
                        string website This is a standard string, but we <em>will</em> verify that it looks like a valid URL
                        
                        
                        
     * @param string $email_type optional - email type preference for the email (html or text, defaults to html)
     * @param boolean $double_optin optional - flag to control whether a double opt-in confirmation message is sent, defaults to true. <em>Abusing this may cause your account to be suspended.</em>
     * @param boolean $update_existing optional - flag to control whether a existing subscribers should be updated instead of throwing and error
     * @param boolean $replace_interests - flag to determine whether we replace the interest groups with the groups provided, or we add the provided groups to the member's interest groups (optional, defaults to true)
     * @param boolean $send_welcome - if your double_optin is false and this is true, we will send your lists Welcome Email if this subscribe succeeds - this will *not* fire if we end up updating an existing subscriber. defaults to false
    
     * @return boolean true on success, false on failure. When using MCAPI.class.php, the value can be tested and error messages pulled from the MCAPI object (see below)
     */
    function listSubscribe($id, $email_address, $merge_vars, $email_type='html', $double_optin=true, $update_existing=false, $replace_interests=true, $send_welcome=false) {
        $params = array();
        $params["id"] = $id;
        $params["email_address"] = $email_address;
        $params["merge_vars"] = $merge_vars;
        $params["email_type"] = $email_type;
        $params["double_optin"] = $double_optin;
        $params["update_existing"] = $update_existing;
        $params["replace_interests"] = $replace_interests;
        $params["send_welcome"] = $send_welcome;
        return $this->callServer("listSubscribe", $params);
    }

    /**
     * Unsubscribe the given email address from the list
     *
     * @section List Related
     * @example mcapi_listUnsubscribe.php
     * @example xml-rpc_listUnsubscribe.php
     *
     * @param string $id the list id to connect to. Get by calling lists()
     * @param string $email_address the email address to unsubscribe
     * @param boolean $delete_member flag to completely delete the member from your list instead of just unsubscribing, default to false
     * @param boolean $send_goodbye flag to send the goodbye email to the email address, defaults to true
     * @param boolean $send_notify flag to send the unsubscribe notification email to the address defined in the list email notification settings, defaults to true
     * @return boolean true on success, false on failure. When using MCAPI.class.php, the value can be tested and error messages pulled from the MCAPI object (see below)
     */
    function listUnsubscribe($id, $email_address, $delete_member=false, $send_goodbye=true, $send_notify=true) {
        $params = array();
        $params["id"] = $id;
        $params["email_address"] = $email_address;
        $params["delete_member"] = $delete_member;
        $params["send_goodbye"] = $send_goodbye;
        $params["send_notify"] = $send_notify;
        return $this->callServer("listUnsubscribe", $params);
    }

    /**
     * Subscribe a batch of email addresses to a list at once
     *
     * @section List Related
     *
     * @example mcapi_listBatchSubscribe.php
     * @example xml-rpc_listBatchSubscribe.php
     *
     * @param string $id the list id to connect to. Get by calling lists()
     * @param array $batch an array of structs for each address to import with two special keys: "EMAIL" for the email address, and "EMAIL_TYPE" for the email type option (html or text) 
     * @param boolean $double_optin flag to control whether to send an opt-in confirmation email - defaults to true
     * @param boolean $update_existing flag to control whether to update members that are already subscribed to the list or to return an error, defaults to false (return error)
     * @param boolean $replace_interests flag to determine whether we replace the interest groups with the updated groups provided, or we add the provided groups to the member's interest groups (optional, defaults to true)
     * @return struct Array of result counts and any errors that occurred
     * @returnf integer success_count Number of email addresses that were succesfully added/updated
     * @returnf integer error_count Number of email addresses that failed during addition/updating
     * @returnf array errors Array of error structs. Each error struct will contain "code", "message", and the full struct that failed
     */
    function listBatchSubscribe($id, $batch, $double_optin=true, $update_existing=false, $replace_interests=true) {
        $params = array();
        $params["id"] = $id;
        $params["batch"] = $batch;
        $params["double_optin"] = $double_optin;
        $params["update_existing"] = $update_existing;
        $params["replace_interests"] = $replace_interests;
        return $this->callServer("listBatchSubscribe", $params);
    }

    /**
     * Unsubscribe a batch of email addresses to a list
     *
     * @section List Related
     * @example mcapi_listBatchUnsubscribe.php
     *
     * @param string $id the list id to connect to. Get by calling lists()
     * @param array $emails array of email addresses to unsubscribe
     * @param boolean $delete_member flag to completely delete the member from your list instead of just unsubscribing, default to false
     * @param boolean $send_goodbye flag to send the goodbye email to the email addresses, defaults to true
     * @param boolean $send_notify flag to send the unsubscribe notification email to the address defined in the list email notification settings, defaults to false
     * @return struct Array of result counts and any errors that occurred
     * @returnf integer success_count Number of email addresses that were succesfully added/updated
     * @returnf integer error_count Number of email addresses that failed during addition/updating
     * @returnf array errors Array of error structs. Each error struct will contain "code", "message", and "email"
     */
    function listBatchUnsubscribe($id, $emails, $delete_member=false, $send_goodbye=true, $send_notify=false) {
        $params = array();
        $params["id"] = $id;
        $params["emails"] = $emails;
        $params["delete_member"] = $delete_member;
        $params["send_goodbye"] = $send_goodbye;
        $params["send_notify"] = $send_notify;
        return $this->callServer("listBatchUnsubscribe", $params);
    }

    /**
     * "Ping" the MailChimp API - a simple method you can call that will return a constant value as long as everything is good. Note
     * than unlike most all of our methods, we don't throw an Exception if we are having issues. You will simply receive a different
     * string back that will explain our view on what is going on.
     *
     * @section Helper
     * @example xml-rpc_ping.php
     *
     * @return string returns "Everything's Chimpy!" if everything is chimpy, otherwise returns an error message
     */
    function ping() {
        $params = array();
        return $this->callServer("ping", $params);
    }

    /**
     * Internal function - proxy method for certain XML-RPC calls | DO NOT CALL
     * @param mixed Method to call, with any parameters to pass along
     * @return mixed the result of the call
     */
    function callMethod() {
        $params = array();
        return $this->callServer("callMethod", $params);
    }
    
    /**
     * Actually connect to the server and call the requested methods, parsing the result
     * You should never have to call this function manually
     */
    function callServer($method, $params) {
    	//Always include the apikey if we are not logging in
    	if($method != "login") {
        	list($key, $dc) = explode("-",$this->api_key,2);
        	if (!$dc) $dc = "us1";
            $host = $dc.".".$this->apiUrl["host"];
    		$params["apikey"] = $this->api_key;
    	} else {
        	$host = $this->apiUrl["host"];
    	}
        $this->errorMessage = "";
        $this->errorCode = "";
        $post_vars = $this->httpBuildQuery($params);
        
        $payload = "POST " . $this->apiUrl["path"] . "?" . $this->apiUrl["query"] . "&method=" . $method . " HTTP/1.0\r\n";
        $payload .= "Host: " . $host . "\r\n";
        $payload .= "User-Agent: MCAPI/" . $this->version ."\r\n";
        $payload .= "Content-type: application/x-www-form-urlencoded\r\n";
        $payload .= "Content-length: " . strlen($post_vars) . "\r\n";
        $payload .= "Connection: close \r\n\r\n";
        $payload .= $post_vars;
        
        ob_start();
        if ($this->secure){
            $sock = fsockopen("ssl://".$host, 443, $errno, $errstr, $this->timeout);
        } else {
            $sock = fsockopen($host, 80, $errno, $errstr, $this->timeout);
        }
        if(!$sock) {
            $this->errorMessage = "Could not connect (ERR $errno: $errstr)";
            $this->errorCode = "-99";
            ob_end_clean();
            return false;
        }
        
        $response = "";
        fwrite($sock, $payload);
        while(!feof($sock)) {
            $response .= fread($sock, $this->chunkSize);
        }
        fclose($sock);
        ob_end_clean();
        
        list($throw, $response) = explode("\r\n\r\n", $response, 2);
        
        if(ini_get("magic_quotes_runtime")) $response = stripslashes($response);
        
        $serial = unserialize($response);
        if($response && $serial === false) {
        	$response = array("error" => "Bad Response.  Got This: " . $response, "code" => "-99");
        } else {
        	$response = $serial;
        }
        if(is_array($response) && isset($response["error"])) {
            $this->errorMessage = $response["error"];
            $this->errorCode = $response["code"];
            return false;
        }
        
        return $response;
    }
    
    /**
     * Re-implement http_build_query for systems that do not already have it
     */
    function httpBuildQuery($params, $key=null) {
        $ret = array();
        
        foreach((array) $params as $name => $val) {
            $name = urlencode($name);
            if($key !== null) {
                $name = $key . "[" . $name . "]";
            }
            
            if(is_array($val) || is_object($val)) {
                $ret[] = $this->httpBuildQuery($val, $name);
            } elseif($val !== null) {
                $ret[] = $name . "=" . urlencode($val);
            }
        }
        
        return implode("&", $ret);
    }
    
   /**
     * Retrieve all of the lists defined for your user account
     *
     * @section List Related
     * @example mcapi_lists.php
     * @example xml-rpc_lists.php
     *
     * @return array list of your Lists and their associated information (see Returned Fields for description)
     * @returnf string id The list id for this list. This will be used for all other list management functions.
     * @returnf integer web_id The list id used in our web app, allows you to create a link directly to it
     * @returnf string name The name of the list.
     * @returnf date date_created The date that this list was created.
     * @returnf integer member_count The number of active members in the given list.
     * @returnf integer unsubscribe_count The number of members who have unsubscribed from the given list.
     * @returnf integer cleaned_count The number of members cleaned from the given list.
     * @returnf boolean email_type_option Whether or not the List supports multiple formats for emails or just HTML
     * @returnf string default_from_name Default From Name for campaigns using this list
     * @returnf string default_from_email Default From Email for campaigns using this list
     * @returnf string default_subject Default Subject Line for campaigns using this list
     * @returnf string default_language Default Language for this list's forms
     */
    function lists() {
        $params = array();
        return $this->callServer("lists", $params);
    }
}

