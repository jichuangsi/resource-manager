<div class="list_part">
      <div class="title"><span class="t">{dede:field name='typename'/}</span><span  class="more"><a href="{dede:field name='typeurl'/}" target="_blank">更多>></a></span></div>
      <div class="listContent_new">
        <ul>
          {dede:arclist row=7 titlelen=32 noflag='h' imgwidth=40 imgheight=50 addfields='filetype' channelid=17}
          <li><span class="update">[field:pubdate function="GetDateMk(@me)"/]</span> <a href="[field:arcurl/]" class="[field:filetype/]" target="_blank">[field:title/]</a></li>
          {/dede:arclist}
        </ul>
      </div>
    </div>