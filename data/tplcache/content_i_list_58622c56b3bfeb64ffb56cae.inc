<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?><html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>文档管理</title>
<link rel="stylesheet" type="text/css" href="img/base.css">
<script language="javascript" src="../include/dedeajax2.js"></script>
<script language="javascript" src="js/ieemu.js"></script>
<script language="javascript" src="js/context_menu.js"></script>
<script language="javascript" src="js/main.js"></script>
<script language="javascript" src="js/list.js"></script>

<script type="text/javascript" src="js/lhgdialog/lhgcore.min.js"></script>
<script type="text/javascript" src="js/lhgdialog/lhgdialog.js"></script>

<script type="text/javascript">
function flexpaperviewer( aid )
{
    var dlg = new J.ui.dialog({ id: 'paperviewer', title: '文档预览及缩略图提取', page: 'flexpaperviewer.php?aid='+aid, btns: false, width: 770, height: 580 });
    dlg.ShowDialog();
} 
</script>
</head>
<body leftmargin="8" topmargin="8" background='img/allbg.gif' onLoad="ContextMenu.intializeContextMenu()">

<table width="98%" border="0" align="center" cellpadding="0" cellspacing="1" bgcolor="#D1DDAA">
 <tr>
 <td align="center" height="28" background="img/newlinebg3.gif">
	<input type='button' class="coolbg np" onClick="location='catalog_do.php?channelid=<?php echo $GLOBALS['channelid']; ?>&cid=<?php echo $GLOBALS['cid']; ?>&dopost=addArchives';" value='添加文档' />
	<?php if($adminid == $mid){ ?>
	<input type='button' class="coolbg np" onClick="location='content_i_list.php?cid=<?php echo $GLOBALS['cid']; ?>&mid=0';" value='全部文档' />
	<?php
}
else{
?>
	<input type='button' class="coolbg np" onClick="location='content_i_list.php?cid=<?php echo $GLOBALS['cid']; ?>&mid=<?php echo $cuserLogin->getUserID(); ?>';" value='我的文档' />
	<?php }  echo $GLOBALS['CheckUserSend']; ?>
 <input type='button' class="coolbg np" onClick="location='catalog_main.php';" value='栏目管理' />
 <input type='button' class="coolbg np" name='bb1' onClick="location='makehtml_list.php?cid=<?php echo $GLOBALS['cid']; ?>';" value='更新列表' />
 <input type='button' class="coolbg np" name='bb2' onClick="location='makehtml_archives.php?cid=<?php echo $GLOBALS['cid']; ?>';" value='更新文档' />
 <input type='button' class="coolbg np" name='bb1' onClick="location='recycling.php?cid=<?php echo $GLOBALS['cid']; ?>';" value='文章回收站' />
 </td>
 </tr>
</table>

<table width='98%'border='0' cellpadding='2' cellspacing='1' bgcolor='#CBD8AC' align='center' style="margin-top:8px;">
<tr bgcolor='#EEF4EA' height='26'>
	<td background='img/wbg.gif' colspan='7'>
		§<?php echo $GLOBALS['positionname']; ?>文档列表 &nbsp;(使用鼠标右键进行常用操作)
	</td>
</tr>
<tr bgcolor="#ffffff" align="center">
	<td width="13%">文档图片</td>
	<td width="35%">文档标题</td>
	<td width="12%">类目</td>
	<td width="11%">权限</td>
	<td width="10%">发布人</td>
	<td width="10%">HTML</td>
	<td  width="9%">点击</td>
</tr>
</table>

<form name="form2">
<?php
$atts = array();
$atts['tagname'] = 'datalist';
$blockValue = $this->refObj->GetArcList($atts,$this->refObj,$fields); 
foreach( $blockValue as $key=>$fields )
{
?>
<table width="98%" border="0" cellpadding="1" cellspacing="1"
	class='ilist'
	bgcolor="<?php  echo GetColor('#FAFAF1','#FFFFFF');
  ?>
"  align='center' style="margin-top:8px;">
	<tr>
	<td width="13%" align='center'>
		<img src="<?php echo CheckPic($fields['litpic']); ?>" width="80" height="60" alt="文档图片" border="0" style="cursor:pointer;" onClick="flexpaperviewer(<?php echo $fields['id']; ?>);">
	</td>
	<td width="35%">
		<input name="arcID" type="checkbox" id="arcID" value="<?php echo $fields['id']; ?>" class="np" />
		<img src='img/trun.gif' title="编辑属性" alt="编辑属性" onClick="QuickEdit(<?php echo $fields['id']; ?>, event, this);" style='cursor:pointer' border='0' width='16' height='16' />
		<a href="archives_do.php?aid=<?php echo $fields['id']; ?>&dopost=editArchives"
			oncontextmenu="ShowMenu(event,this,<?php echo $fields['id']; ?>,'<?php echo str_replace('\'', '', $fields['title']); ?>')">
		<b><?php echo $fields['title'];  echo IsCommendArchives($fields['flag']); ?></b>
		</a>
		<br/>
　　发布时间：<?php echo GetDateTimeMk($fields['senddate']); ?>
	</td>
	<td width="12%" height="26" align="center">
		<?php echo $fields['typename']; ?>
		<br />
		ID: <?php echo $fields['id']; ?>
	</td>
	<td width="11%" align="center"><?php echo GetRankName($fields['arcrank']); ?></td>
	<td width="10%" align="center"><?php echo $fields['adminname']; ?></td>
	<td width="10%" align="center"><?php echo IsHtmlArchives($fields['ismake']); ?></td>
	<td  width="9%" align="center"><?php echo $fields['click']; ?></td>
	</tr>
</table>
<?php
}
?>
</form>

<table width="98%" border="0" cellspacing="1" cellpadding="1" bgcolor='#CBD8AC' align='center' style="margin-top:8px;">
	<tr bgcolor="#FAFAF1">
	<td height="36" colspan="10">
		&nbsp;
		<a href="javascript:selAll()" class="coolbg">全选</a>
		<a href="javascript:noSelAll()" class="coolbg">取消</a>
		<a href="javascript:viewArc(0)" class="coolbg">&nbsp;查看&nbsp;</a>
		<a href="javascript:editArc(0)" class="coolbg">&nbsp;更改&nbsp;</a>
		<a href="javascript:updateArc(0)" class="coolbg">&nbsp;更新&nbsp;</a>
		<a href="javascript:checkArc(0)" class="coolbg">&nbsp;审核&nbsp;</a>
		<a href="javascript:adArc(0)" class="coolbg">&nbsp;推荐&nbsp;</a>
		<a href="javascript:;" onClick="moveArc(event,this,<?php echo (empty($channelid) ? 0 : $channelid); ?>)" class="coolbg">&nbsp;移动&nbsp;</a>
		<a href="javascript:delArc(0)" class="coolbg">&nbsp;删除&nbsp;</a>
		<a href="javascript:;" onClick="cAtts('attsAdd',event,this)" class="coolbg">&nbsp;增加属性&nbsp;</a>
		<a href="javascript:;" onClick="cAtts('attsDel',event,this)" class="coolbg">&nbsp;删除属性&nbsp;</a>
	</td>
	</tr>
	<tr>
	<td height="28" align="center" bgcolor='#EEF4EA'>
		<?php
$atts = array();
$atts['tagname'] = 'pagelist';
$atts['listsize'] = '5';
 echo $this->refObj->GetPageList($atts,$this->refObj,$fields); 
?>

	</td>
</tr>
<form name='form3' action='content_i_list.php' method='get'>
<input type='hidden' name='dopost' value='listArchives' />
<td background='img/wbg.gif' height='28' align='center'>
<table border='0' cellpadding='0' cellspacing='0'>
	<tr>
	<td width='90' align='center'>请选择类目：</td>
	<td width='160'>
	<select name='cid' style='width:150'>
 	<option value='0'>选择分类...</option>
		<?php echo $GLOBALS['optionarr']; ?>
	</select>
	</td>
	<td width='70'>
	关键字：
	</td>
	<td width='160'>
		<input type='text' name='keyword' value='<?php echo $GLOBALS['keyword']; ?>' style='width:150px' />
	</td>
	<td width='110'>
    		<select name='orderby' style='width:80px'>
            <option value='id'>排序...</option>
            <option value='pubdate'>发布时间</option>
            <option value='sortrank'>置顶权值</option>
            <option value='click'>点击量</option>
            <option value='scores'>评论积分</option>
            <option value='lastpost'>最后评论</option>
      	</select>
   </td>
	<td>
		<input name="imageField" type="image" src="img/button_search.gif" width="60" height="22" border="0" class="np" />
 </td>
</tr>
</table>
</td>
</form>
</tr>
</table>

</body>
</html>