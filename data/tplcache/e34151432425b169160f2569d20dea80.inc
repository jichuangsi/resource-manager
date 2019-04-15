<!--文档-->
      <div class='listcon'>
        <div class='listbook'>
          <div class='imgs'>[field:array runphp='yes']@me = (empty(@me['litpic']) ? "" : "<a href='{@me['arcurl']}' class='preview'><img src='{@me['litpic']}' width='70' height='86'/></a>"); [/field:array]</div>
          <!--div class='pasefont'>80 Pages</div-->
        </div>
        <div class='listicon'> <a class="icon pdf"></a> </div>
        <div class='listnrwz'>
          <h1><a href="[field:arcurl/]" class="title">[field:title/]</a></h1>
          <div class='lcont'>[field:description/]...</div>
          <div class='listtips'>
            <ul>
              <li >浏览：[field:click/]<span>|</span></li>
              <li >价格：￥[field:needmoney/]<span>|</span></li>
              <li >下载：[field:click/]<span>|</span></li>
              <li >收藏：[field:click/]<span>|</span></li>
              <li >好评：[field:scores/]<span>|</span></li>
              <li > 上传人:<a>yiditushe</a> </li>
            </ul>
            <p class='date'>[field:pubdate function="GetDateTimeMK(@me)"/]</p>
          </div>
        </div>
        <div class='clear'></div>
      </div>
      <!--文档 end-->