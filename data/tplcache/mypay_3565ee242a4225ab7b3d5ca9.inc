<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>我购买的文章 - 会员中心 -<?php echo $cfg_webname; ?></title>
<link href="templets/style/common.css" rel="stylesheet" type="text/css" />
<link href="templets/style/class.css" rel="stylesheet" type="text/css" />
<link href="templets/style/base.css" rel="stylesheet" type="text/css" />
<script type="text/javascript" src="templets/js/j.js"></script>
<script type="text/javascript" src="templets/js/load.js"></script>
<script type="text/javascript" src="templets/js/leftmenu.js"></script>
<script type="text/javascript" src="templets/js/table_function.js"></script>
<script type="text/javascript">
//获得选中文件的文件名
function GetCheckfolderItem()
{
	var allSel='';
	if(document.form1.deleteid.value) return document.form1.deleteid.value;
	for(i=0;i<document.form1.deleteid.length;i++)
	{
		if(document.form1.deleteid[i].checked)
		{
			if(allSel=='')
			allSel=document.form1.deleteid[i].value;
			else
			allSel=allSel+","+document.form1.deleteid[i].value;
		}
	}
	return allSel;
}

function DoSubmit()
{
	var selid = GetCheckfolderItem();
	if(selid=='') {
		alert("你没选中任何信息！");
		return false;
	}
	if(window.confirm("你确定要删除这些消息么？"))
	{
		location = "mypay.php?dopost=del&ids="+selid;
	}
}
</script>
</head>
<body>
<!--页面头部 begin-->
<?php include(DEDEMEMBER."/templets/head.htm"); ?>
<!--页面头部 end-->
<div id="s_landh">
  <!--页面头部 会员菜单 begin-->
  <?php include(DEDEMEMBER."/templets/top_menu.htm"); ?>
  <!--页面头部 会员菜单 end-->
</div>
<div id="main">
  <div id="content" class="w960 clearfix">
    <div id="mcpmain">
      <div id="appTab">
        <ul>
          <li><a href="buy.php">充值</a></li>
          <li><a href="operation.php">定单</a></li>
          <li class="thisTab"><a href="mypay.php" id="mypay">消费记录</a></li>
          <li><a href="benefit.php" id="benefit">提现</a></li>
          <li><a href="incoming.php" id="incoming">收益记录</a></li>
        </ul>
      </div>
      <div id="mainCp">
        <h3 class="meTitle">我购买的文章</h3>
        <table width="100%" border="0" cellpadding="0" cellspacing="0" class="list">
          <thead>
            <tr>
              <th width="5%"></th>
              <th width="5%">ID</th>
              <th >标题</th>
              <th width="10%">消费金币</th>
              <th width="20%">消费时间</th>
            </tr>
          </thead>
          <form name='form1' action="mypay.php" method="post">
            <input type='hidden' name='dopost' value='del' />
            <tbody>
            
            <?php
$atts = array();
$atts['tagname'] = 'datalist';
$blockValue = $this->refObj->GetArcList($atts,$this->refObj,$fields); 
foreach( $blockValue as $key=>$fields )
{
?>
            <tr>
              <td align="center"><input type="checkbox" name="deleteid" value="<?php echo $fields['aid']; ?>"/></td>
              <td align="center"><?php echo $fields['aid']; ?></td>
              <td><?php
								echo '<a href="../plus/view.php?aid='.str_replace('ARCHIVE', '', $fields['buyid']).'" target="_blank">'.$fields['oldinfo'].'</a>';
					   ?></td>
              <td align="center"><?php echo $fields['money']; ?></td>
              <td align="center"><?php echo GetDateTimeMk($fields['mtime']); ?></td>
            </tr>
            <?php
}
?>
            <tr>
              <td colspan="6"><button id="checkedClick" type="button" class="greenBtn1">全选</button>
                <button type="button" onclick="DoSubmit()" class="greenBtn3">删除选中</button></td>
            </tr>
            </tbody>
            
          </form>
          <tfoot>
            <tr>
              <td colspan="7"><div class="pageList">
                <?php
$atts = array();
$atts['tagname'] = 'pagelist';
$atts['listsize'] = '5';
 echo $this->refObj->GetPageList($atts,$this->refObj,$fields); 
?>
</td>
            </tr>
          </tfoot>
        </table>
      </div>
      <!--主操作区域 -->
    </div>
  </div>
  <?php include(DEDEMEMBER."/templets/foot.htm"); ?>
</div>
</body>
</html>