<?php
require_once(dirname(__FILE__)."/config.php");
//���ǰ�ȫԭ�򲻹��Ƿ����ο�Ͷ�幦�ܣ����������û�Ͷ��
CheckRank(0,0);
if($cfg_mb_lit=='Y')
{
	ShowMsg("����ϵͳ�����˾�����Ա�ռ䣬����ʵĹ��ܲ����ã�","-1");
	exit();
}
require_once(DEDEINC."/dedetag.class.php");
require_once(DEDEINC."/userlogin.class.php");
require_once(DEDEINC."/customfields.func.php");
require_once(DEDEMEMBER."/inc/inc_catalog_options.php");
require_once(DEDEMEMBER."/inc/inc_archives_functions.php");
$channelid = isset($channelid) && is_numeric($channelid) ? $channelid : 17;//�鼮Ƶ��ģ��ID

/*-------------
function _ShowForm(){  }
--------------*/
if(empty($dopost))
{
	$cInfos = $dsql->GetOne("Select * From `#@__channeltype`  where id='$channelid'; ");
	if(!is_array($cInfos))
	{
		ShowMsg('ģ�Ͳ���ȷ', '-1');
		exit();
	}

	//��������˻�Ա��������ͣ��������ο�Ͷ��ѡ����Ч
	if($cInfos['sendrank']>0 || $cInfos['usertype']!='')
	{
		CheckRank(0,0);
	}

	//����Ա�ȼ�����������
	if($cInfos['sendrank'] > $cfg_ml->M_Rank)
	{
		$row = $dsql->GetOne("Select membername From `#@__arcrank` where rank='".$cInfos['sendrank']."' ");
		ShowMsg("�Բ�����Ҫ[".$row['membername']."]���������Ƶ�������ĵ���","-1","0",5000);
		exit();
	}
	if($cInfos['usertype']!='' && $cInfos['usertype'] != $cfg_ml->M_MbType)
	{
		ShowMsg("�Բ�����Ҫ[".$cInfos['usertype']."�ʺ�]���������Ƶ�������ĵ���","-1","0",5000);
		exit();
	}
	include(DEDEMEMBER."/templets/book_add.htm");
	exit();
}
?>
