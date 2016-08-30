<?php

//todo use mode var to alter the slider style - always hero currently
class liv_slider{
    //todo docblock image array structure
    //must have uri,topic,alt
    function __construct($images, $mode = 'hero', $link_text = 'Read More'){
        $this->images = $images;
        $this->mode = $mode;
        $this->link_text = $link_text;
    }
    function __toString(){
        $output = '<div class="page-hero-slider">';
        foreach($this->images as $image){
            //print_r($image);
            $output .= '<div class="rsSlide">';
            $output .= '<span class="hero-image center-bg shadow-inset-lr" '.
                    'style="background-image:url(\''.image_style_url('city_slider', $image['uri']).'\');" '.
                    'alt="'.$image['alt'].'">';
                $output .= '<span class="hero-details">';
                    $output .= '<span class="topic">'.$image['topic'].'</span>';
                    $output .= '<span class="summary">';
                        $output .= '<h2>'.$image['title'].'</h2>';
                        $output .= ' <a href="'.$image['link'].'">' . $this->link_text . '</a>';
                    $output .= '</span>';
                $output .= '</span>';
            $output .= '</span>';
            $output .= '</div>';
        }
        $output .= '</div>';
        return $output;
    }
}