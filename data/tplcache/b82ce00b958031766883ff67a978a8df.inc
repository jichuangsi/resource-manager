<field:filetype islist='1' itemname='文件类型' type='text' isnull='true' default='' rename='' />
<field:language islist='1' itemname='语言' type='text' isnull='true' default='' rename='' />
<field:softtype islist='1' itemname='软件类型' type='text' isnull='true' default='' rename='' />
<field:accredit islist='1' itemname='授权方式' type='text' isnull='true' default='' rename='' />
<field:os islist='1' itemname='操作系统' type='text' isnull='true' default='' rename='' />
<field:softrank  islist='1' itemname='软件等级' type='int' isnull='true' default='3' rename='' function='GetRankStar(@me)' notsend='1'/>
<field:officialUrl  itemname='官方网址' type='text' isnull='true' default='' rename='' />
<field:officialDemo itemname='演示网址' type='text' isnull='true' default='' rename='' />
<field:softsize  itemname='软件大小' type='text' isnull='true' default='' rename='' />
<field:softlinks  itemname='软件地址' type='softlinks' isnull='true' default='' rename='' />
<field:introduce  itemname='详细介绍' type='htmltext' isnull='trnue' default='' rename='' />
<field:daccess islist='1' itemname='下载级别' type='int' isnull='true' default='0' rename='' function='' notsend='1'/>
<field:needmoney islist='1' itemname='需要金币' type='int' isnull='true' default='0' rename='' function='' notsend='1' />
<field:onlineviewurl itemname="在线阅读文档路径" autofield="1" notsend="0" type="text" isnull="true" islist="0" default=""  maxlength="250" page="">
</field:onlineviewurl>
<field:pagenumber itemname="文档页数" autofield="1" notsend="0" type="int" isnull="true" islist="0" default="1"  maxlength="250" page="">
</field:pagenumber>

<field:pagenumber2 itemname="免费阅读的文档页数" autofield="1" notsend="0" type="int" isnull="true" islist="0" default="0"  maxlength="250" page="">
</field:pagenumber2>

<field:wwk itemname="是否生成swf文件" autofield="1" notsend="0" type="int" isnull="true" islist="0" default="0"  maxlength="250" page="">
</field:wwk>

<field:wwk2 itemname="是否更新了可免费页数" autofield="1" notsend="0" type="int" isnull="true" islist="0" default="0"  maxlength="250" page="">
</field:wwk2>
