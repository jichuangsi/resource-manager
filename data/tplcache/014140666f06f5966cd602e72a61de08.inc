[field:global runphp='yes' name=autoindex]
          $a="
          <li class='r1'><span class='top10'>";
            $b="</span>";
            $c="
          <li><span class='top10'>";
            if (@me % 2 == 1) @me = $a.@me.$b;
            else @me = $c.@me.$b;
            [/field:global]
    <a href='[field:global name="cfg_cmspath"/]/member/index.php?uid=[field:userid/]' class='topName' target='_blank'>[field:uname/]</a> <span class='all'>[field:docnumber function="null2zero(@me)"/]</span> <span class='red'>[field:scores/]</span></li>