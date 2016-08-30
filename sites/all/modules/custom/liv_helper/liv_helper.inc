<?php
class livHelper{

    static function ordinalSuffix($number){
        $ends = array('th','st','nd','rd','th','th','th','th','th','th');
        if (($number %100) >= 11 && ($number%100) <= 13)
            $abbreviation = $number. '<sup>th</sup>';
        else
            $abbreviation = $number. '<sup>'.$ends[$number % 10].'</sup>';
        return $abbreviation;
    }
    static function machineNameToWordsUpper($name){
        $pieces = explode('-',$name);
        foreach($pieces as $key => $piece){
            $pieces[$key] = ucwords($piece);
        }
        $category = implode(' ',$pieces);
        return $category;
    }
}