<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();

//cookie全部传到后台，否则取不到登录信息
$cookies .= '"MyCssSkin":'."'".$_COOKIE["MyCssSkin"]."',";
$cookies .= '"lastCid":'."'".$_COOKIE["lastCid"]."',";
$cookies .= '"lastCid__ckMd5":'."'".$_COOKIE["lastCid__ckMd5"]."',";
$cookies .= '"DedeUserID":'."'".$_COOKIE["DedeUserID"]."',";
$cookies .= '"DedeUserID__ckMd5":'."'".$_COOKIE["DedeUserID__ckMd5"]."',";
$cookies .= '"DedeLoginTime":'."'".$_COOKIE["DedeLoginTime"]."',";
$cookies .= '"DedeLoginTime__ckMd5":'."'".$_COOKIE["DedeLoginTime__ckMd5"]."',";
$cookies .= '"PHPSESSID":'."'".$_COOKIE["PHPSESSID"]."',";
$cookies .= '"reqid":'."'".$reqid."'";

//从配置中取允许上传的文件类型
$alltypes = explode('|', $cfg_mb_addontype);
$fileExt = "";
foreach($alltypes as $type){
	$fileExt.="*.".$type.";";
}

//从配置中取允许上传的文件大小，单位（Kb）
$allfilesize = $cfg_mb_upload_size;
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>文档投稿 - 会员中心 -<?php echo $cfg_webname; ?></title>
<link href="templets/style/common.css" rel="stylesheet" type="text/css" />
<link href="templets/style/class.css" rel="stylesheet" type="text/css" />
<link href="templets/style/base.css" rel="stylesheet" type="text/css" />
<script type="text/javascript" src="templets/js/j.js"></script>
<script language="javascript" type="text/javascript" src="<?php echo $GLOBALS['cfg_cmspath']; ?>/js/j.js"></script>
<script type="text/javascript" src="templets/js/load.js"></script>
<script type="text/javascript" src="templets/js/leftmenu.js"></script>
<link href="<?php echo $cfg_cmsurl; ?>/js/jquery.uploadify-v2.1.0/uploadify.css" rel="stylesheet" type="text/css" />
<link href="<?php echo $cfg_cmsurl; ?>/js/jGrowl-1.2.4/jquery.jgrowl.css" rel="stylesheet" type="text/css" />
<script type="text/javascript" src="<?php echo $cfg_cmsurl; ?>/js/jquery-1.3.2.min.js"></script>
<script type="text/javascript" src="<?php echo $cfg_cmsurl; ?>/js/swfobject.js"></script>
<script type="text/javascript" src="<?php echo $cfg_cmsurl; ?>/js/jquery.uploadify-v2.1.0/jquery.uploadify.v2.1.0.min.js"></script>
<script type="text/javascript" src="<?php echo $cfg_cmsurl; ?>/js/jGrowl-1.2.4/jquery.jgrowl_minimized.js"></script>

<script type="text/javascript">
$(document).ready(function() {
	$("#uploadify").uploadify({
		'uploader'       : '<?php echo $cfg_cmsurl; ?>/js/jquery.uploadify-v2.1.0/uploadify.swf',
		'script'         : '<?php echo $cfg_memberurl; ?>/inc/book_resp_uploadify.php',
		'scriptData'     : {<?php echo $cookies ?>},
		'cancelImg'      : '<?php echo $cfg_cmsurl; ?>/js/jquery.uploadify-v2.1.0/cancel.png',
		'folder'         : '<?php echo $cfg_memberurl; ?>/uploads',
		'queueID'        : 'fileQueue',
		'auto'           : true,
		'multi'          : false,
		'fileDesc'       : '支持的文件格式：<?php echo str_replace("|", ",", $cfg_mb_addontype);?>',
		'fileExt'        : "<?php echo $fileExt;?>",
		'buttonImg'      : 'templets/images/icon-up.gif',
		'width'          : 190,
		'height'         : 43,
		'onComplete'     : function(event, queueID, fileObj, response, data){
							   //alert(response);
							   var obj;
							   var theme='success';
								try{
									obj = eval("("+response+")");//转换为json对象 
								}catch(e){
									//alert(e);
									theme='error';
									$.jGrowl("文档上传发生异常，请联系系统管理员！",{theme:theme,position:'bottom-right',header:'提醒信息',life:5000,sticky:false});
									return;
								}
							   result = obj.result;
							   if(result == "0"){
							       //成功
								   $.jGrowl("文档【"+fileObj.name+"】上传成功！3秒钟后将自动返回...",{theme:theme,position:'bottom-right',header:'提醒信息',life:5000,sticky:false});
								   window.setTimeout(function(){window.location="book_request.php"}, 3000);
						       }else{
							       theme='error';
								   $.jGrowl(obj.msg, {theme:theme,position:'bottom-right',header:'提醒信息',life:5000,sticky:false});
							   }
		                   }

	});
});
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
          <li class="thisTab"><a href="book_request.php"><span>文档投稿</span></a></li>
          <li><a href="book_request_add.php"><span>发布文档悬赏</span></a></li>
        </ul>
      </div>
      <form class="mTB10 mR10 mL10" name="addcontent" action="book_request.php?dopost=add" method="post" onsubmit="return checkSubmit();">
        <input type="hidden" name="reqid" value="<?php echo $reqid ?>"  />
        <div id="mainCp">
          <div class="postForm">
            <!--上传-->
            <div id="uploaderContainer">
              <div id="fileQueue"></div>
              <input type="file" name="uploadify" id="uploadify" />
            </div>
            <!--上传 end-->
            <br />
            <h1>任务描述：</h1>
            <p class="cellBg">
              <label>标题：</label>
              <input name="doctitle" type="text" id="doctitle" value="<?php echo $bookReq['doctitle'] ?>" maxlength="100" class="intxt" disabled="disabled"/>
            </p>
            <p class="cellBg">
              <label>备注：</label>
              <textarea name="remark" disabled="disabled"><?php echo $bookReq['remark'] ?></textarea>
            </p>
            <p class="cellBg">
              <label>悬赏积分：</label>
              <span style="color:#F00; font-weight:bold;"><?php echo $bookReq['score'] ?></span>
            </p>
            <p class="cellBg">
              <label>有效期：</label>
              <span><?php echo GetDateMk($bookReq['validate']) ?></span>
            </p>
            <p class="cellBg">
              <label>发布人：</label>
              <span><?php echo $bookReq['uname'] ?></span>
            </p>
            <p class="cellBg">
              <label>发布时间：</label>
              <span><?php echo $bookReq['addtime'] ?></span>
            </p>
          </div>
        </div>
      </form>
      <!--主操作区域 -->
    </div>
  </div>
</div>
<?php include(DEDEMEMBER."/templets/foot.htm"); ?>
</div>
</body>
</html>