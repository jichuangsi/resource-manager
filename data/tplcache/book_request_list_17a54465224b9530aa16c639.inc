<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>文档悬赏任务列表 - 会员中心 -<?php echo $cfg_webname; ?></title>
<link href="templets/style/common.css" rel="stylesheet" type="text/css" />
<link href="templets/style/class.css" rel="stylesheet" type="text/css" />
<link href="templets/style/base.css" rel="stylesheet" type="text/css" />
<script type="text/javascript" src="templets/js/j.js"></script>
<script type="text/javascript" src="templets/js/table_function.js"></script>
<script type="text/javascript" src="../include/dedeajax2.js"></script>
<script type="text/javascript" src="templets/js/load.js"></script>
<script type="text/javascript" src="templets/js/leftmenu.js"></script>

<script type="text/javascript" src="<?php echo $cfg_cmspath; ?>/js/jquery-1.3.2.min.js"></script>

<!--弹出窗口 样式-->
<link type="text/css" href="<?php echo $cfg_cmspath; ?>/js/lhgdialog/lhgdialog.css" rel="stylesheet"/>
<script type="text/javascript" src="<?php echo $cfg_cmspath; ?>/js/lhgdialog/lhgcore.min.js"></script>
<script type="text/javascript" src="<?php echo $cfg_cmspath; ?>/js/lhgdialog/lhgdialog.js"></script>


<script type="text/javascript" src="<?php echo $cfg_cmspath; ?>/js/zDialog/zDrag.js"></script>
<script type="text/javascript" src="<?php echo $cfg_cmspath; ?>/js/zDialog/zDialog.js"></script>

<script type="text/javascript">
function respReq(reqid){
  location = "book_request_resp.php?reqid="+reqid;
}
function viewResp(reqid){
  //tb_show('投稿记录','book_request_resp_list.php?TB_iframe=true&height=400&width=950');
  //var dlg = new J.ui.dialog({ id: 'paperviewer', title: '文档的投稿记录', page: 'book_request_resp_list.php?reqid='+reqid, btns: false, width: 850, height: 560 });
  //dlg.ShowDialog();
  //Dialog.open({URL:'book_request_resp_list.php?reqid='+reqid});
  	var diag = new Dialog();
	diag.Width = 900;
	diag.Height = 560;
	diag.Title = "悬赏任务投稿记录";
	diag.URL = 'book_request_resp_list.php?reqid='+reqid;
	diag.show();
	
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
          <li class="thisTab"><a href="book_request.php"><span>悬赏任务列表</span></a></li>
          <li><a href="book_request_add.php"><span>发布任务悬赏</span></a></li>
        </ul>
      </div>
      <ul class="tabSub">
        <li <?php echo ($ftype==0)? "class='thisTab'" : "";?>><a href="book_request.php?ftype=0"><span>全部任务列表</span></a></li>
        <li <?php echo ($ftype==1)? "class='thisTab'" : "";?>><a href="book_request.php?ftype=1"><span>我发布的任务</span></a></li>
      </ul>
      <form name='form1' action="book_request.php" method="post">
        <div id="mainCp">
          <h3 class="meTitle">
            <?php if($ftype == '0') echo '全部任务列表'; if($ftype == '1') echo '我发布的任务';?>
            (<?php echo $dlist->totalResult;?>) </h3>
          <ul class="listStyle3">
          <table width="100%" border="0" cellpadding="0" cellspacing="0" class="list">
              <thead>
                <tr>
                  <th width="40%">文档标题</th>
                  <th width="10%">悬赏积分 </th>
                  <!--th width="10%">备注 </th-->
                  <th width="10%">有效日期 </th>
                  <th width="10%">发布者 </th>
                  <th width="15%">发布时间</th>
                  <th width="15%">操作</th>
                </tr>
              </thead>
              <tbody>
            <?php
$atts = array();
$atts['tagname'] = 'datalist';
$blockValue = $this->refObj->GetArcList($atts,$this->refObj,$fields); 
foreach( $blockValue as $key=>$fields )
{
?>
              <tr>
                <td align="left" class="tabTitle"><?php echo $fields['doctitle']; ?></td>
                <td align="center" style="color:#F00; font-weight:bold;"><?php echo $fields['score']; ?></td>
                <!--td align="left"><?php echo $fields['remark']; ?></td-->
                <td align="center"><?php echo GetDateMk($fields['validate']);?></td>
                <td align="center"><?php echo $fields['uname']; ?></td>
                <td align="center"><?php echo $fields['addtime']; ?></td>
                <td align="center" class="doPost">
                <?php
                  if($fields['mid'] == $cfg_ml->M_ID){//任务发布者=当前用户
                ?>
                   <a href="javascript:viewResp(<?php echo $fields['id']?>);">选稿<?php echo "(".$fields['respnum'].")" ?></a>
                <?php
                  }
                  else
                  {
                ?>
                   <a href="javascript:respReq(<?php echo $fields['id']?>);">投稿</a> 
                <?php
                  }
                ?>
                </td>
              </tr>
            <?php
}
?>
            </tbody>
            </table>
          </ul>
          <div class="listDo appMsg">
            <div class="pageList fRight"><?php
$atts = array();
$atts['tagname'] = 'pagelist';
$atts['listsize'] = '5';
 echo $this->refObj->GetPageList($atts,$this->refObj,$fields); 
?>
</div>
          </div>
        </div>
      </form>
      <!--主操作区域 -->
    </div>
  </div>
  <?php include(DEDEMEMBER."/templets/foot.htm"); ?>
</div>
<script>
IMAGESPATH = "<?php echo $cfg_cmspath; ?>/js/zDialog/images/";
var images=["icon_alert.gif","icon_dialog.gif","icon_query.gif","window.gif","dialog_cb.gif","dialog_closebtn.gif","dialog_closebtn_over.gif"];
var dlgimgs=ielt7?["dialog_ct.gif","dialog_lb.gif","dialog_lt.gif","dialog_mlm.gif","dialog_mrm.gif","dialog_rb.gif","dialog_rt.gif"]:["dialog_cb.png",
"dialog_ct.png","dialog_lb.png","dialog_lt.png","dialog_mlm.png","dialog_mrm.png","dialog_rb.png","dialog_rt.png"]
var images=images.concat(dlgimgs);
var imgsHtml=[];
for(var i=0;i<images.length;i++){
	imgsHtml.push('<img src="'+IMAGESPATH+images[i]+'"/>')
}
document.write('<div id="imgsloader" style="text-align:right; display:none;"">'+imgsHtml.join("")+'</div>')
</script>
</body>
</html>