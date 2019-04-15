<?php
require_once(dirname(__FILE__)."/../config.php");

//载入可发布频道
$addset = '';

//检测可用的内容模型
if($cfg_admin_channel = 'array' && count($admin_catalogs) > 0)
{
	$admin_catalog = join(',', $admin_catalogs);
	$dsql->SetQuery(" Select channeltype From `#@__arctype` where id in({$admin_catalog}) group by channeltype ");
}
else
{
	$dsql->SetQuery(" Select channeltype From `#@__arctype` group by channeltype ");
}
$dsql->Execute();
$candoChannel = '';
while($row = $dsql->GetObject())
{
	$candoChannel .= ($candoChannel=='' ? $row->channeltype : ','.$row->channeltype);
}
if(empty($candoChannel)) $candoChannel = 1;
$dsql->SetQuery("Select id,typename,addcon,mancon From `#@__channeltype` where id in({$candoChannel}) And id<>-1 And isshow=1 order by id asc");
$dsql->Execute();
while($row = $dsql->GetObject())
{
	$addset .= "  <m:item name='{$row->typename}' ischannel='1' link='{$row->mancon}?channelid={$row->id}' linkadd='{$row->addcon}?channelid={$row->id}' channelid='{$row->id}' rank='' target='main' />\r\n";
}
//////////////////////////

$adminMenu1 = $adminMenu2 = '';
if($cuserLogin->getUserType() >= 10)
{
	
$adminMenu2 = "
<m:top item='10_' name='系统设置' display='none' rank='sys_User,sys_Group,sys_Edit,sys_Log,sys_Data'>
  <m:item name='系统基本参数' link='sys_info.php' rank='sys_Edit' target='main' />
  <m:item name='系统用户管理' link='sys_admin_user.php' rank='sys_User' target='main' />
  <m:item name='用户组设定' link='sys_group.php' rank='sys_Group' target='main' />
  
  <m:item name='自定义文档属性' link='content_att.php' rank='sys_Att' target='main' />
  <m:item name='系统错误修复[S]' link='sys_repair.php' rank='sys_verify' target='main' />
</m:top>

<m:top item='10_6_' name='支付工具' display='none' rank='sys_Data'>
  <m:item name='点卡产品分类' link='cards_type.php' rank='sys_Data' target='main' />
  <m:item name='点卡产品管理' link='cards_manage.php' rank='sys_Data' target='main' />
  <m:item name='会员产品分类' link='member_type.php' rank='sys_Data' target='main' />
  <m:item name='会员消费记录' link='member_operations.php' rank='sys_Data' target='main' />
  <m:item name='会员提现记录' link='member_benefit.php' rank='sys_Data' target='main' />
  <m:item name='支付接口设置' link='sys_info_pay.php' .php' rank='sys_Data' target='main' />
</m:top>

	";
}
$remoteMenu = ($cfg_remote_site=='Y')? "<m:item name='远程服务器同步' link='makeremote_all.php' rank='sys_ArcBatch' target='main' />" : "";
$menusMain = "
-----------------------------------------------

<m:top item='1_' name='常用操作' display='block'>
  <m:item name='网站栏目管理' link='catalog_main.php' ischannel='1' addalt='创建栏目' linkadd='catalog_add.php?id=17' rank='t_List,t_AccList' target='main' />
  <m:item name='所有档案列表' link='content_list.php?cid=17' rank='a_List,a_AccList' target='main' />
  <m:item name='等审核的档案' link='content_list.php?cid=17&arcrank=-1' rank='a_Check,a_AccCheck' target='main' />
  <m:item name='我发布的文档' link='content_list.php?cid=17&mid=".$cuserLogin->getUserID()."' rank='a_List,a_AccList,a_MyList' target='main' />
  <m:item name='评论管理' link='feedback_main.php' rank='sys_Feedback' target='main' />
  <m:item name='内容回收站' link='recycling.php' ischannel='1' addalt='清空回收站' addico='img/gtk-del.png' linkadd='archives_do.php?dopost=clear&aid=no' rank='a_List,a_AccList,a_MyList' target='main' />
</m:top>



<m:top item='1_' name='附件管理' display='none' rank='sys_Upload,sys_MyUpload,plus_文件管理器'>s
  <m:item name='附件数据管理' link='media_main.php' rank='sys_Upload,sys_MyUpload' target='main' />
</m:top>


<m:top item='1_3_3' name='批量维护' display='block'>
  <m:item name='更新系统缓存' link='sys_cache_up.php' rank='sys_ArcBatch' target='main' />
  <m:item name='文档批量维护' link='content_batch_up.php' rank='sys_ArcBatch' target='main' />
  <m:item name='重复文档检测' link='article_test_same.php' rank='sys_ArcBatch' target='main' />
  <m:item name='TAG标签管理' link='tags_main.php' rank='sys_Keyword' target='main' />
</m:top>

<m:top item='5_' name='自动任务' notshowall='1'  display='block' rank='sys_MakeHtml'>
  <m:item name='一键更新网站' link='makehtml_all.php' rank='sys_MakeHtml' target='main' />
  <m:item name='更新系统缓存' link='sys_cache_up.php' rank='sys_ArcBatch' target='main' />
  {$remoteMenu}
</m:top>

<m:top item='5_' name='HTML更新' notshowall='1' display='none' rank='sys_MakeHtml'>
  <m:item name='更新主页HTML' link='makehtml_homepage.php' rank='sys_MakeHtml' target='main' />
  <m:item name='更新栏目HTML' link='makehtml_list.php' rank='sys_MakeHtml' target='main' />
  <m:item name='更新文档HTML' link='makehtml_archives.php' rank='sys_MakeHtml' target='main' />
</m:top>

<m:top item='6_' name='会员管理' display='none' rank='member_List,member_Type'>
  <m:item name='注册会员列表' link='member_main.php' rank='member_List' target='main' />
  <m:item name='会员级别设置' link='member_rank.php' rank='member_Type' target='main' />
  <m:item name='积分头衔设置' link='member_scores.php' rank='member_Type' target='main' />
  <m:item name='会员短信管理' link='member_pm.php' rank='member_Type' target='main' />
  <m:item name='会员留言管理' link='member_guestbook.php' rank='member_Type' target='main' />
  <m:item name='会员动态管理' link='member_info_main.php?type=feed' rank='member_Type' target='main' />
</m:top>

$adminMenu2
-----------------------------------------------
";

?>