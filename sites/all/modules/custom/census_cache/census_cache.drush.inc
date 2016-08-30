<?php

function census_cache_drush_command()
{
    $migration_options = array('all' => 'rebuild full cache');
    $items['census-cache-rebuild'] = array(
        'description' => 'Rebuild census cache',
        'options' => $migration_options,
        // We will bootstrap to login from within the command callback.
        'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
        'arguments' => array(
            'scope' => 'Either use all or a specific type of cache to update(WIP).',
        ),

        'drupal dependencies' => array('census_cache'),
        'aliases' => array('ccr'),
    );
    return $items;
}

function drush_census_cache_rebuild($arg = 'all'){

  $node_census_fields = array(
  'DP04_0088E' => 'Median Home Price',
  'DP05_0065E' => 'Calculate percentage of pop against this',
  'DP05_0001E' => 'Total Pop',
  'DP02_0001E' => 'Total households',
  'DP05_0072E' => 'Ethnicity White',
  'DP05_0073E' => 'Ethnicity Black',
  'DP05_0075E' => 'Ethnicity Asian',
  'DP05_0077E' => 'Other 1',
  'DP05_0078E' => 'Other 2',
  'DP05_0079E' => 'Other 3',
  'DP05_0080E' => 'Other 4',
  'DP05_0074E' => 'Ethnicity Indian',
  'DP05_0076E' => 'Ethnicity Hawaiian',
  'DP05_0066E' => 'Enthnicity Hispanic',
  'DP02_0092E' => 'Foreign 1',
  'DP02_0086E' => 'Foreign 2',
  'DP05_0004E' => 'Age 1',
  'DP05_0005E' => 'Age 1',
  'DP05_0006E' => 'Age 1',
  'DP05_0007E' => 'Age 1',
  'DP05_0008E' => 'Age 1',
  'DP05_0009E' => 'Age 1',
  'DP05_0010E' => 'Age 1',
  'DP05_0011E' => 'Age 1',
  'DP05_0012E' => 'Age 1',
  'DP05_0013E' => 'Age 1',
  'DP05_0014E' => 'Age 1',
  'DP05_0015E' => 'Age 1',
  'DP05_0016E' => 'Age 1',
  'DP05_0017E' => 'Median Age',
  'DP05_0002E' => 'Male age 1',
  'DP05_0001E' => 'Male age 2',
  'DP05_0022E' => 'Kids 2',
  'DP05_0025E' => 'Seniors',
  'DP02_0004E' => 'Married 1',
  'DP02_0005E' => 'Married with children',
  'DP02_0011E' => 'Living alone',
  'DP03_0062E' => 'Median Household income',
  'DP03_0088E' => 'Per capita income',
  'DP03_0123PE' => 'families below poverty line',
  'DP03_0129PE' => 'Children below poverty line',
  'DP03_0059E' => 'High income 1',
  'DP03_0060E' => 'High Income 2',
  'DP03_0061E' => 'High Income 3',
  'DP03_0051E' => 'Income Divisor',
  'DP03_0052E' => 'Low income 1',
  'DP03_0053E' => 'Low Income 2',
  'DP03_0054E' => 'Low income 3',
  'DP03_0055E' => 'Low Income 4',
  'DP02_0007E' => 'Single fathers',
  'DP02_0009E' => 'Single mothers',
  );

  $city_add_fields = array(
  //added fields from city node import
  'DP02_0100E' => 'Foreign Born',
  'DP02_0111E' => 'English Only',
  'DP02_0112E' => 'Language Other',
  'DP02_0113E' => 'Poor English',
  //commute fields from city node import
  'DP03_0019E' => 'Drove Alone',
  'DP03_0020E' => 'Carpooled',
  'DP03_0021E' => 'Public Transportation',
  'DP03_0022E' => 'Walked',
  'DP03_0023E' => 'Other Means',
  'DP03_0024E' => 'Worked at home',
  //The following apparently should be run through a clean averaging function, as per the migration
  //'DP03_0025E' => 'Average Commute',
  'DP02_0090E' => 'Different State',
  //employment fields
  'DP03_0004E' => 'Employed',
  'DP03_0005E' => 'Unemployed',
  'DP03_0006E' => 'Employed Armed Forces',
  //Education
  'DP02_0053E' => 'Education Enrollment Pre-k',
  'DP02_0054E' => 'Education Enrollemtn Kinde',
  'DP02_0055E' => 'Education Enrollment Elem',
  'DP02_0056E' => 'Education Enrollment High',
  'DP02_0057E' => 'Education Enrollment Colle',
  //attainment totals
  'DP02_0058E' => 'Attainment Total',
  'DP02_0059E' => 'Education Less Than 9th',
  'DP02_0060E' => 'Education Some High School',
  'DP02_0061E' => 'Education High School',
  'DP02_0062E' => 'Education Some College',
  'DP02_0063E' => 'Education Degree Associate',
  'DP02_0064E' => 'Education Degree Bachelors',
  'DP02_0065E' => 'Education Post Grad',
  'DP02_0066PE' => 'Education Percent High School',
  'DP02_0067PE' => 'Education Percent Bachelor',
  );

    if($arg == 'all' || $arg == 'real-estate') {
        $fields = array(
		//'NAME' => 'name',
		'DP04_0006E' => 'UNITS IN STRUCTURE!!Total housing units',
		'DP04_0016E' => 'YEAR STRUCTURE BUILT!!Total housing units',
		'DP04_0017E' => 'YEAR STRUCTURE BUILT!!Built 2010 or later',
		'DP04_0018E' => 'YEAR STRUCTURE BUILT!!Built 2000 to 2009',
		'DP04_0019E' => 'YEAR STRUCTURE BUILT!!Built 1990 to 1999',
		'DP04_0020E' => 'YEAR STRUCTURE BUILT!!Built 1980 to 1989',
		'DP04_0021E' => 'YEAR STRUCTURE BUILT!!Built 1970 to 1979',
		'DP04_0022E' => 'YEAR STRUCTURE BUILT!!Built 1960 to 1969',
		'DP04_0023E' => 'YEAR STRUCTURE BUILT!!Built 1950 to 1959',
		'DP04_0024E' => 'YEAR STRUCTURE BUILT!!Built 1940 to 1949',
		'DP04_0025E' => 'YEAR STRUCTURE BUILT!!Built 1939 or earlier',
		'DP04_0037E' => 'BEDROOMS!!Total housing units',
		'DP04_0041E' => 'BEDROOMS!!3 bedrooms',
		'DP04_0042E' => 'BEDROOMS!!4 bedrooms',
		'DP04_0043E' => 'BEDROOMS!!5 or more bedrooms',
		'DP04_0045E' => 'HOUSING TENURE!!Occupied housing units!!Owner-occupied',
		'DP04_0046E' => 'HOUSING TENURE!!Occupied housing units!!Renter-occupied',
		'DP04_0049E' => 'YEAR HOUSEHOLDER MOVED INTO UNIT!!Occupied housing units',
		'DP04_0050E' => 'YEAR HOUSEHOLDER MOVED INTO UNIT!!Occupied housing units!!Moved in 2010 or later',
		'DP04_0051E' => 'YEAR HOUSEHOLDER MOVED INTO UNIT!!Occupied housing units!!Moved in 2000 to 2009',
		'DP04_0052E' => 'YEAR HOUSEHOLDER MOVED INTO UNIT!!Occupied housing units!!Moved in 1990 to 1999',
		'DP04_0079E' => 'VALUE!!Owner-occupied units',
		'DP04_0080E' => 'VALUE!!Owner-occupied units!!Less than $50,000',
		'DP04_0081E' => 'VALUE!!Owner-occupied units!!$50,000 to $99,999',
		'DP04_0082E' => 'VALUE!!Owner-occupied units!!$100,000 to $149,999',
		'DP04_0083E' => 'VALUE!!Owner-occupied units!!$150,000 to $199,999',
		'DP04_0084E' => 'VALUE!!Owner-occupied units!!$200,000 to $299,999',
		'DP04_0085E' => 'VALUE!!Owner-occupied units!!$300,000 to $499,999',
		'DP04_0086E' => 'VALUE!!Owner-occupied units!!$500,000 to $999,999',
		'DP04_0087E' => 'VALUE!!Owner-occupied units!!$1,000,000 or more',
		'DP04_0088E' => 'VALUE!!Owner-occupied units!!Median (dollars)',
		'DP04_0089E' => 'MORTGAGE STATUS!!Owner-occupied units',
		'DP04_0090E' => 'MORTGAGE STATUS!!Owner-occupied units!!Housing units with a mortgage',
		'DP04_0091E' => 'MORTGAGE STATUS!!Owner-occupied units!!Housing units without a mortgage',
		'DP04_0100E' => 'SELECTED MONTHLY OWNER COSTS (SMOC)!!Housing units with a mortgage!!Median (dollars)',
		'DP04_0107E' => 'SELECTED MONTHLY OWNER COSTS (SMOC)!!Housing units without a mortgage!!Median (dollars)',
		'DP04_0108E' => 'SELECTED MONTHLY OWNER COSTS AS A PERCENTAGE OF HOUSEHOLD INCOME (SMOCAPI)!!Housing units with a mortgage (excluding units where SMOCAPI cannot be computed)',
		'DP04_0109E' => 'SELECTED MONTHLY OWNER COSTS AS A PERCENTAGE OF HOUSEHOLD INCOME (SMOCAPI)!!Housing units with a mortgage (excluding units where SMOCAPI cannot be computed)!!Less than 20.0 percent',
		'DP04_0110E' => 'SELECTED MONTHLY OWNER COSTS AS A PERCENTAGE OF HOUSEHOLD INCOME (SMOCAPI)!!Housing units with a mortgage (excluding units where SMOCAPI cannot be computed)!!20.0 to 24.9 percent',
		'DP04_0111E' => 'SELECTED MONTHLY OWNER COSTS AS A PERCENTAGE OF HOUSEHOLD INCOME (SMOCAPI)!!Housing units with a mortgage (excluding units where SMOCAPI cannot be computed)!!25.0 to 29.9 percent',
		'DP04_0132E' => 'GROSS RENT!!Occupied units paying rent!!Median (dollars)',
		'DP04_0134E' => 'GROSS RENT AS A PERCENTAGE OF HOUSEHOLD INCOME (GRAPI)!!Occupied units paying rent (excluding units where GRAPI cannot be computed)',
		'DP04_0135E' => 'GROSS RENT AS A PERCENTAGE OF HOUSEHOLD INCOME (GRAPI)!!Occupied units paying rent (excluding units where GRAPI cannot be computed)!!Less than 15.0 percent',
		'DP04_0136E' => 'GROSS RENT AS A PERCENTAGE OF HOUSEHOLD INCOME (GRAPI)!!Occupied units paying rent (excluding units where GRAPI cannot be computed)!!15.0 to 19.9 percent',
		'DP04_0137E' => 'GROSS RENT AS A PERCENTAGE OF HOUSEHOLD INCOME (GRAPI)!!Occupied units paying rent (excluding units where GRAPI cannot be computed)!!20.0 to 24.9 percent',
		'DP04_0138E' => 'GROSS RENT AS A PERCENTAGE OF HOUSEHOLD INCOME (GRAPI)!!Occupied units paying rent (excluding units where GRAPI cannot be computed)!!25.0 to 29.9 percent',
	);
        $api = new censusAPI('real-estate',$fields);
        $api = new censusAPI('real-estate',$fields,'profile','state');
        $api = new censusAPI('real-estate',$fields,'profile','us');
        $api = new censusAPI('real-estate', $fields, 'profile', 'county');
    }
    if($arg == 'real-estate-2' || $arg == 'all'){

		$fields = array(
        	//'NAME' => 'name',
			'B08201_001E' => 'Total:',
			'B08201_007E' => '1-person household:',
			'B08201_013E' => '2-person household:',
			'B08201_019E' => '3-person household:',
			'B08201_025E' => '4-or-more-person household:'
	);

	$api = new censusAPI('real-estate-2',$fields,'');
	}

	if($arg == 'county-data' || $arg == 'all') {

		$fields = $node_census_fields;

		$api = new censusAPI('county-data', $fields, 'profile', 'county');
		$api = new censusAPI('county-data', $fields, 'profile', 'us');
	}

  if($arg == 'metro-data' || $arg == 'all') {

		$fields = $node_census_fields;

		$api = new censusAPI('metro-data', $fields, 'profile', 'metropolitan+statistical+area/micropolitan+statistical+area');
		//$api = new censusAPI('county-data', $fields, 'profile', 'us');
	}

  if($arg == 'city-data' || $arg == 'all') {
    $api = new censusAPI('city-data', $node_census_fields);
    $api = new censusAPI('city-add-data', $city_add_fields);
  }
}
