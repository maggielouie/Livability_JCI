<?php
class context_reaction_clear_region extends context_reaction {

	function editor_form($context) {
	}

	function options_form($context) {
		$values = $this->fetch_from_context($context);
		$form = array();
		foreach (list_themes() as $theme) {
			if ($theme->status) {
				$regions = system_region_list($theme->name);
				$default = isset($values[$theme->name]) ? $values[$theme->name]['clear'] : array();

				$form[$theme->name] = array(
					'#type' => 'fieldset',
					'#title' => "Clear Blocks from {$theme->name} Theme Regions",
					'#collapsible' => TRUE,
					'#collapsed' => !array_reduce($default, create_function('$a, $b', 'return $a || $b;')),
				);
				$form[$theme->name]['clear'] = array(
					'#type' => 'checkboxes',
					'#title' => t("Clear the following"),
					'#options' => $regions,
					'#default_value' => $default,
				);
			}
		}
		return $form;
	}
	
	function execute(&$page) {
		global $theme;
		$context = $this->get_contexts();
		foreach ($this->get_contexts() as $k => $v) { 
			if (isset($v->reactions[$this->plugin][$theme])) {
				$regions = $v->reactions[$this->plugin][$theme]['clear'];
				foreach ($regions as $region => $clear) {
					if ($clear === $region && isset($page[$region])) {
						if (isset($page[$region]['system_main'])) {
						  $page[$region] = array('system_main' => $page[$region]['system_main']);
						  $page[$region]['system_main']['#weight'] = 0;
						  $page[$region]['system_main']['#block']->weight = 0;
						}
						else {
							$page[$region] = array();
						}
					}
				}
			foreach($context as $k => $v) {
							foreach($v->reactions as $pluginname => $stuff) {
								if ($pluginname == 'block') {
									$blockplugin = context_get_plugin('reaction', $pluginname);
									if ($blockplugin) { 
										$blockplugin->execute($page);
									}
								}
							}
						}
			}
		}
	}
}
