[field:global runphp='yes' name=autoindex]
          $a="
          <li class='r1'><span class='top10'>";
            $b="</span>";
            $c="
          <li><span class='top10'>";
            if (@me % 2 == 1) @me = $a.@me.$b;
            else @me = $c.@me.$b;
            [/field:global] <a title="[field:title/]" href="[field:arcurl/]">[field:title/]</a> </li>