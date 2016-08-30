<span class="highlights">
  <h4>Highlights</h4>
  <ul class="bullet">
  <?php foreach ($items as $delta => $item): ?>
    <li><?php print render($item); ?></li>
  <?php endforeach; ?>
  </ul>
</span>