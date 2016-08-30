
<div class="about-us-hero" <?php if (isset($node->field_image_single['und'])) { ?> style="background: url('<?php echo file_create_url($node->field_image_single['und'][0]['uri']); ?>');" <?php } ?>>
  <ul class="breadcrumbs padded clearfix no-mobile"><li><a href="/">Livability.com</a></li><li><span>Company</span></li></ul>
  <div class="about-us-hero-content">
    <img src="/sites/all/themes/liv/images/city-icon.png" alt="City Icon">
    <h1><?php print $node->field_headline['und'][0]['value']; ?></h1>
  </div>
</div>
<?php if (isset($node->field_deck['und'])) { ?>
  <div class="summary-generic">
    <p><?php print $node->field_deck['und'][0]['value']; ?></p>
  </div>
<?php } ?>
<div class="city-banner">
  <img src="/sites/all/themes/liv/images/cityscape-wide.png" /> 
</div>
<?php if (isset($node->field_stats['und'])) { ?>
	<div class="facts-stats shadow-inset-tb bg-diag section">
		<div class="map-bg"></div>
		<h2>Facts and Stats</h2>
		<ul class="clearfix infograph">
		<?php foreach($node->field_stats['und'] as $statcoll) {
			$stat = entity_load('field_collection_item', array($statcoll['value'])); ?>
			<li class="one-q">
				<h4><?php print $stat[$statcoll['value']]->field_stat['und'][0]['value']; ?></h4>
				<span class="medium-value"><?php print number_format($stat[$statcoll['value']]->field_stat_value['und'][0]['value'], 0, ".", ","); ?></span>
				<span class="fill-bar"></span>
				<span class="change">
					<i class="icon-arrow-up green"></i>
					<?php print $stat[$statcoll['value']]->field_stat_description['und'][0]['value']; ?>
				</span>
			</li>
		<?php } ?>
		</ul>
	</div>
<?php }  ?>
<?php if (isset($node->field_leadership_team['und'])) { ?>
	<div class="leadership section clearfix" id="leadership">
		<h2>Leadership Team</h2>
		<ul class="leaders">
			<?php foreach($node->field_leadership_team['und'] as $team) { ?>
				<li class="one-q">
					<?php $link = 'user/'.$team['target_id'];
					$stuff = '<span class="center-bg circle"'; 
					if (isset($team['entity']->field_author_photo['und'])) { $stuff .= 'style="background-image: url(\'' . file_create_url($team['entity']->field_author_photo['und'][0]['uri']) . '\')"'; }
					$stuff .= '></span>';
					$stuff .= '<span class="name">' . $team['entity']->name .'</span>';
					if (isset($team['entity']->field_professional_title['und'])) { 
						$stuff .= '<span class="title">' . $team['entity']->field_professional_title['und'][0]['value'] . '</span>';
					}
					print l($stuff, $link, array('html' => TRUE));
					?>
				</li>
			<?php } ?>
		</ul>
	</div>
<?php } ?>
<?php if (isset($node->field_liv_partners['und'])) { ?>
	<div class="partners section grey-bg shadow-inset-tb clearfix" id="partners">
		<h2>Partners</h2>
		<ul>
			<?php foreach($node->field_liv_partners['und'] as $partnercoll) { 
				$partner = entity_load('field_collection_item', array($partnercoll['value'])); ?>
				<li>
					<?php $img = file_create_url($partner[$partnercoll['value']]->field_image_single['und'][0]['uri']);
					 if (isset($partner[$partnercoll['value']]->field_link['und'])) {
						print l('<img src="'.$img.'" />', $partner[$partnercoll['value']]->field_link['und'][0]['url'], array('html' => TRUE));
					} 
					else {
						print '<img src="'.$img.'" />';
					} ?>
				</li>
			<?php } ?>
		</ul>
	</div>
<?php } ?>
<?php if (isset($node->field_description['und'])) { ?>
	<div class="about section">
		<h2>About Journal Communications</h2>
		<?php print $node->field_description['und'][0]['value']; ?>
		<ul class="logos clearfix">
			<li class="one-q">
				<a href="http://www.jnlcom.com" target="_blank"><img src="/sites/all/themes/liv/images/logos/journal-communications.png" alt="Journal Communications Logo" /></a>
			</li>
			<li class="one-q">
				<a href="http://www.livability.com" target="_blank"><img src="/sites/all/themes/liv/images/logos/livability-about.jpg" alt="Livability Logo" /></a>
			</li>
			<li class="one-q">
				<a href="http://www.businessclimate.com" target="_blank"><img src="/sites/all/themes/liv/images/logos/business-climate.png" alt="Business Climate Logo" /></a>
			</li>
			<li class="one-q">
				<a href="http://www.farmflavor.com" target="_blank"><img src="/sites/all/themes/liv/images/logos/farm-flavor.png" alt="Farm Flavor Logo" /></a>
			</li>
		</ul>
	</div>
<?php } ?>
