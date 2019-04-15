<?php
require_once(dirname(__FILE__)."/config.php");
AjaxHead();
if($myurl == '')
{
	exit('');
}
$uid  = $cfg_ml->M_LoginID;

!$cfg_ml->fields['face'] && $face = ($cfg_ml->fields['sex'] == '女')? 'dfgirl' : 'dfboy';
$facepic = empty($face)? $cfg_ml->fields['face'] : $GLOBALS['cfg_memberurl'].'/templets/images/'.$face.'.png';

?>
<!--用户信息begin-->
<a class="username" href="<?php echo $cfg_memberurl; ?>/edit_baseinfo.php"><?php echo $cfg_ml->M_UserName; ?></a><span><a href="<?php echo $cfg_memberurl; ?>/content_list.php?channelid=17" class="mlfb">会员中心</a></span><a href="<?php echo $cfg_memberurl; ?>/pm.php"><img src="<?php echo $cfg_memberurl; ?>/templets/images/d_icon_email.gif" alt="消息"/></a><a class="mlrB" href="<?php echo $cfg_memberurl; ?>/pm.php">0</a><a href="<?php echo $cfg_memberurl; ?>/index_do.php?fmdo=login&dopost=exit" class="lo">退出</a>
<!--用户信息 end-->
