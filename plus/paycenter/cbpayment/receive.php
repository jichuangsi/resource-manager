<?php
require_once (dirname(__FILE__) . "/../../../include/common.inc.php");
require_once DEDEINC.'/shopcar.class.php';
require_once DEDEINC.'/memberlogin.class.php';
require_once DEDEROOT.'/data/sys_pay.cache.php';
require_once(dirname(__FILE__)."/cbpayment_config.php");
$cfg_ml = new MemberLogin(); 
$cart 	= new MemberShops();
$cfg_ml->PutLoginInfo($cfg_ml->M_ID);
if($cfg_ml->M_ID>0) $burl = $cfg_basehost."/member/control.php";
else $burl = "javascript:;";
$cart->MakeOrders();
$v_oid     =trim($_POST['v_oid']);       // �̻����͵�v_oid�������   
$v_pmode   =trim($_POST['v_pmode']);    // ֧����ʽ���ַ�����   
$v_pstatus =trim($_POST['v_pstatus']);   //  ֧��״̬ ��20��֧���ɹ�����30��֧��ʧ�ܣ�
$v_pstring =trim($_POST['v_pstring']);   // ֧�������Ϣ �� ֧����ɣ���v_pstatus=20ʱ����ʧ��ԭ�򣨵�v_pstatus=30ʱ,�ַ������� 
$v_amount  =trim($_POST['v_amount']);     // ����ʵ��֧�����
$v_moneytype  =trim($_POST['v_moneytype']); //����ʵ��֧������    
$remark1   =trim($_POST['remark1' ]);      //��ע�ֶ�1
$remark2   =trim($_POST['remark2' ]);     //��ע�ֶ�2
$v_md5str  =trim($_POST['v_md5str' ]);   //ƴ�պ��MD5У��ֵ  

$md5string=strtoupper(md5($v_oid.$v_pstatus.$v_amount.$v_moneytype.$key));

if ($v_md5str==$md5string)
{
	if($v_pstatus=="20"){
		$sql = "UPDATE `#@__shops_orders` SET `state`='1' WHERE `oid`='$v_oid' AND `userid`='".$cfg_ml->M_ID."';";
		if($dsql->ExecuteNoneQuery($sql)){
			ShowMsg("֧���ɹ�!","javascript:;");
			exit;
		}else{
			ShowMsg("֧��ʧ��","javascript:;");
			exit;
		}
	}else{
		ShowMsg("֧��ʧ��","javascript:;");
		exit;
	}
}else{
	ShowMsg("У��ʧ��,���ݿ���!","javascript:;");
	exit;
}
?>