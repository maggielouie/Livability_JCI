


<div class="cities-nearby widget stay-full">
    <h3>Cities Nearby</h3>
<?php
$c = getCityContext();
$view = views_get_view('nearby_cities');
$view->execute('block');
print '<ul class="nearby-cities">';
$rowCount =1;
foreach($view->result as $row){
    //var_dump($row);
    $nearbyc = city_node_load($row->nid);
    print '<li>';
    print '<a href="/'.
            drupal_get_path_alias('node/'.$row->nid).'">
            <span class="number">'.$rowCount.'</span>'.$nearbyc->title.
            ', '.$nearbyc->state->field_state_code['und'][0]['value'].
            '<i class="icon-arrow-right-circle white"></i>'.
            //number_format($row->field_data_field_geo_geofield_distance,0).' miles'.
        '</a>';
    print '</li>';
    $rowCount++;
}
print '</ul>';
?>
</div>