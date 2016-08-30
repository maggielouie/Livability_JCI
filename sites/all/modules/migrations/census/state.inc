<?php

class MigrateStateSync extends Migration{
    public function __construct($arguments) {
        parent::__construct($arguments);
        $this->source = new MigrateSourceCensusAPI(
          'https://api.census.gov/data/2014/acs5/profile?get=NAME,'.
          'DP05_0001E,'. // Total Population Sex and Age
          'DP05_0032E,DP05_0033E,DP05_0034E,DP05_0039E,DP05_0047E,DP05_0052E,DP05_0066E,'. // Race
          'DP04_0088E,DP03_0062E,'. // Homes
          'DP02_0066PE,DP02_0067PE,'.
          'DP05_0004E,DP05_0005E,DP05_0006E,DP05_0007E,DP05_0008E,DP05_0009E,DP05_0010E,DP05_0011E,DP05_0012E,DP05_0013E,DP05_0014E,DP05_0015E,DP05_0016E,DP05_0017E,DP05_0018E,DP05_0019E,DP05_0020E,DP05_0021E,' . // Age Range
          'DP04_0044E,DP04_0045E,DP04_0046E'.
          '&for=state:*&key=3d9521af9c510f2beea74ce6f3b599b38bc50de9');$this->destination = new MigrateDestinationNode('state');
        $this->map = new MigrateSQLMap($this->machineName,array(
            'state' => array('type' => 'int','unsigned' => TRUE,'not null' => true)
        ), MigrateDestinationNode::getKeySchema());
        $this->addFieldMapping('nid', 'nid');
        $this->addFieldMapping('title', 'NAME');
        $this->addFieldMapping('field_population','DP05_0001E');
        $this->addFieldMapping('field_fips','state');
        $this->addFieldMapping('field_state_code','stateCode');
        /* ethnicity */
        $this->addFieldMapping('field_ethnicity_hispanic','DP05_0066E');
        $this->addFieldMapping('field_ethnicity_white','DP05_0032E');
        $this->addFieldMapping('field_ethnicity_black','DP05_0033E');
        $this->addFieldMapping('field_ethnicity_indian','DP05_0034E');
        $this->addFieldMapping('field_ethnicity_asian','DP05_0039E');
        $this->addFieldMapping('field_ethnicity_hawaiian','DP05_0047E');
        $this->addFieldMapping('field_ethnicity_other','DP05_0052E');
        /* Housing */
        $this->addFieldMapping('field_median_home_price','DP04_0088E');
        $this->addFieldMapping('field_median_household_income','DP03_0062E');

        $this->addFieldMapping('field_age_under_5', 'DP05_0004E');
        $this->addFieldMapping('field_age_5_9', 'DP05_0005E');
        $this->addFieldMapping('field_age_10_14', 'DP05_0006E');
        $this->addFieldMapping('field_age_15_19', 'DP05_0007E');
        $this->addFieldMapping('field_age_20_24', 'DP05_0008E');
        $this->addFieldMapping('field_age_25_34', 'DP05_0009E');
        $this->addFieldMapping('field_age_35_44', 'DP05_0010E');
        $this->addFieldMapping('field_age_45_54', 'DP05_0011E');
        $this->addFieldMapping('field_age_55_59', 'DP05_0012E');
        $this->addFieldMapping('field_age_60_64', 'DP05_0013E');
        $this->addFieldMapping('field_age_65_74', 'DP05_0014E');
        $this->addFieldMapping('field_age_75_84', 'DP05_0015E');
        $this->addFieldMapping('field_age_85_over', 'DP05_0016E');
        $this->addFieldMapping('field_age_median', 'DP05_0017E');
        $this->addFieldMapping('field_age_18_over', 'DP05_0018E');
        $this->addFieldMapping('field_age_21_over', 'DP05_0019E');
        $this->addFieldMapping('field_age_62_over', 'DP05_0020E');
        $this->addFieldMapping('field_age_65_over', 'DP05_0021E');
        $this->addFieldMapping('field_homes_total', 'DP04_0044E');
        $this->addFieldMapping('field_homes_owned', 'DP04_0045E');
        $this->addFieldMapping('field_homes_rent', 'DP04_0046E');

        $this->addFieldMapping('field_education_percent_high_sch','DP02_0066PE');
        $this->addFieldMapping('field_education_percent_bachelor','DP02_0067PE');
        $this->addFieldMapping('pathauto','1');
    }
}