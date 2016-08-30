<?php

class MigrateCitySync extends Migration{
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->source = new MigrateSourceCensusAPI(
        'https://api.census.gov/data/2014/acs5/profile?get=NAME,'.
        'DP05_0001E,DP05_0002E,DP05_0003E,'. // Total Population Sex and Age
        'DP05_0032E,DP05_0033E,DP05_0034E,DP05_0039E,DP05_0047E,DP05_0052E,DP05_0066E,'. // Race
        'DP04_0045E,DP04_0046E,DP04_0088E,DP03_0062E,'. // Homes
        'DP02_0092E,DP02_0111E,DP02_0112E,DP02_0113E,DP02_0090E,'. //Language
        'DP03_0019E,DP03_0020E,DP03_0021E,DP03_0022E,DP03_0023E,DP03_0024E,DP03_0025E,'.//commute
        'DP03_0004E,DP03_0005E,DP03_0006E,'. //Employment
        'DP02_0052E,DP02_0053E,DP02_0054E,DP02_0055E,DP02_0056E,DP02_0057E,DP02_0058E,DP02_0059E,DP02_0061E,DP02_0062E,DP02_0063E,DP02_0064E,DP02_0065E,DP02_0066PE,DP02_0067PE'.
        '&for=place:*&in=state:*&key=3d9521af9c510f2beea74ce6f3b599b38bc50de9');
    $this->destination = new MigrateDestinationNode('city');

    $this->map = new MigrateSQLMap($this->machineName,array(
        'stateplace' => array('type' => 'int','unsigned' => TRUE,'not null' => true)
    ), MigrateDestinationNode::getKeySchema());
    $this->addFieldMapping('nid','nid');
    $this->addFieldMapping('title', 'NAME');
    $this->addFieldMapping('field_place_id', 'placeCode');
    $this->addFieldMapping('field_fips', 'placeCode');
    $this->addFieldMapping('field_liv_fips', 'livfips');
    $this->addFieldMapping('field_population','DP05_0001E');//Civilian population 18 years and over
    $this->addFieldMapping('field_state', 'state')->sourceMigration('StateSync');
    $this->addFieldMapping('field_census_name', 'censusname');
    /* GEO */
    $this->addFieldMapping('field_geo','geom');
    $this->addFieldMapping('field_geo:input_format')->defaultValue('lat/lon');
    $this->addFieldMapping('field_geo:geo_type')->defaultValue('point');
    $this->addFieldMapping('field_geo:lat','lat');
    $this->addFieldMapping('field_geo:lon','long');
    /* Sex and Age */
    $this->addFieldMapping('field_sex_male','DP05_0002E');
    $this->addFieldMapping('field_sex_female','DP05_0003E');
    /* ethnicity */
    $this->addFieldMapping('field_ethnicity_hispanic','DP05_0066E');
    $this->addFieldMapping('field_ethnicity_white','DP05_0032E');
    $this->addFieldMapping('field_ethnicity_black','DP05_0033E');
    $this->addFieldMapping('field_ethnicity_indian','DP05_0034E');
    $this->addFieldMapping('field_ethnicity_asian','DP05_0039E');
    $this->addFieldMapping('field_ethnicity_hawaiian','DP05_0047E');
    $this->addFieldMapping('field_ethnicity_other','DP05_0052E');
    /* Housing */
    $this->addFieldMapping('field_housing_own','DP04_0045E');
    $this->addFieldMapping('field_housing_rent','DP04_0046E');
    $this->addFieldMapping('field_median_home_price','DP04_0088E');
    $this->addFieldMapping('field_median_household_income','DP03_0062E');
    /* language */
    $this->addFieldMapping('field_foreign_born','DP02_0092E');//foreign born
    $this->addFieldMapping('field_english_only','DP02_0111E');// English only
    $this->addFieldMapping('field_language_other','DP02_0112E');// Language other than English
    $this->addFieldMapping('field_poor_english','DP02_0113E');//Speak English less than "very well"
    $this->addFieldMapping('field_different_state','DP02_0090E');// Different state
    /* Commute */
    $this->addFieldMapping('field_drove_alone','DP03_0019E');//' Car, truck, or van -- drove alone
    $this->addFieldMapping('field_carpooled','DP03_0020E'); //' Car, truck, or van -- carpooled
    $this->addFieldMapping('field_public','DP03_0021E'); //'Public transportation (excluding taxicab)
    $this->addFieldMapping('field_walked','DP03_0022E'); //' Walked
    $this->addFieldMapping('field_commute_other','DP03_0023E'); //'Other means
    $this->addFieldMapping('field_worked_home','DP03_0024E'); //' Worked at home
    $this->addFieldMapping('field_avg_commute','DP03_0025E')->callbacks(array($this,'cleanAVG'));// Mean travel time to work in minutes');
    /* Employment */
    $this->addFieldMapping('field_employed', 'DP03_0004E');
    $this->addFieldMapping('field_unemployed', 'DP03_0005E');
    $this->addFieldMapping('field_employed_armed_forces', 'DP03_0006E	');
    /* Education */
    $this->addFieldMapping('field_education_enrollment_total','DP02_0052E');
    $this->addFieldMapping('field_education_enrollment_prek','DP02_0053E');
    $this->addFieldMapping('field_education_enrollment_kinde','DP02_0054E');
    $this->addFieldMapping('field_education_enrollment_eleme','DP02_0055E');
    $this->addFieldMapping('field_education_enrollment_high','DP02_0056E');
    $this->addFieldMapping('field_education_enrollment_colle','DP02_0057E');
    $this->addFieldMapping('field_education_attainment_total','DP02_0058E');
    $this->addFieldMapping('field_education_less_than_9th','DP02_0059E');
    $this->addFieldMapping('field_education_high_school','DP02_0061E');
    $this->addFieldMapping('field_education_college','DP02_0062E');
    $this->addFieldMapping('field_education_degree_associate','DP02_0063E');
    $this->addFieldMapping('field_education_degree_bachelors','DP02_0064E');//B06009_004E some college,63 associates,64 bachelors
    $this->addFieldMapping('field_education_post_grad','DP02_0065E');
    $this->addFieldMapping('field_education_percent_high_sch','DP02_0066PE');
    $this->addFieldMapping('field_education_percent_bachelor','DP02_0067PE');
    $this->addFieldMapping('pathauto','1');
  }
  function cleanAVG($val){
    if($val == 'N' || $val == '-'){
      return NULL;
    }
    return $val;
  }

}