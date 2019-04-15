<?php
require_once(dirname(__FILE__)."/../include/common.inc.php");
require_once(DEDEINC."/channelunit.class.php");
//文档ID
$id = intval($aid);

//获得附加表信息
$row = $dsql->GetOne("Select ch.addtable,arc.mid From `#@__arctiny` arc left join `#@__channeltype` ch on ch.id=arc.channel where arc.id='$id' ");

if(empty($row['addtable']))
{
	exit("-1");
}

//更新文档页数。为1时才更新
$dsql->ExecuteNoneQuery("update `{$row['addtable']}` set pagenumber = $pagenumber where aid = '$id' and pagenumber = 1");

exit("0");
?>