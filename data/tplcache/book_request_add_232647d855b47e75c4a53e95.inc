<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>发布文档悬赏任务 - 会员中心 - <?php echo $cfg_webname; ?></title>
<link href="templets/style/common.css" rel="stylesheet" type="text/css" />
<link href="templets/style/class.css" rel="stylesheet" type="text/css" />
<link href="templets/style/base.css" rel="stylesheet" type="text/css" />
<script type="text/javascript" src="templets/js/j.js"></script>
<script language="javascript" type="text/javascript" src="<?php echo $GLOBALS['cfg_cmspath']; ?>/js/j.js"></script>
<script type="text/javascript" src="templets/js/load.js"></script>
<script type="text/javascript" src="templets/js/leftmenu.js"></script>
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
          <li><a href="book_request.php"><span>悬赏任务列表</span></a></li>
          <li class="thisTab"><a href="book_request_add.php"><span>发布文档悬赏</span></a></li>
        </ul>
      </div>
     <form class="mTB10 mR10 mL10" name="addcontent" action="book_request.php?dopost=add" method="post" onsubmit="return checkSubmit();">
        <div id="mainCp">
          <div class="postForm">
            <p class="cellBg">
              <label>文档名称：</label>
              <input name="doctitle" type="text" id="doctitle" maxlength="100" class="intxt"/>
            </p>
            <p class="cellBg">
              <label>悬赏积分：</label>
              <select name="score">
              	<option value="10">10分</option>
                <option value="20">20分</option>
                <option value="30">30分</option>
                <option value="40">40分</option>
                <option value="50">50分</option>
              </select>
            </p>
            <p class="cellBg">
              <label>备注信息：</label>
              <textarea name="remark"></textarea>
            </p>
            <p class="cellBg">
              <label>有效期限：</label>
              <input name="validate" type="text" id="validate" class="intxt" value="2012-10-11"/>
            </p>
            <p class="cellBg">
              <label>验证码：</label>
              <input name="vdcode" type="text" id="vdcode" maxlength="100" class="intxt" style='width:50px;text-transform:uppercase;' />
              <img src="../include/vdimgck.php" alt="看不清？点击更换" align="absmiddle" style="cursor:pointer" onclick="this.src=this.src+'?'" /></p>
              
              <p>
              <button class="button2" type="submit">提交</button>
              <button class="button2 ml10" type="reset" onclick="location.reload();">重置</button>
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