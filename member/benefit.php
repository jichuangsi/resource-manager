<?php
require_once(dirname(__FILE__).'/config.php');
CheckRank(0,0);
$myurl = $cfg_basehost.$cfg_member_dir.'/index.php?uid='.$cfg_ml->M_LoginID;
//�ж��û��Ƿ��������������ֵ����п���Ϣ
$row = $dsql->GetOne("select banktype, account from `#@__member_bank_account` where mid = '$cfg_ml->M_ID'");
$banktype = $row["banktype"];//����
$account = $row["account"];//����

$tpl = new DedeTemplate();
$tpl->LoadTemplate(DEDEMEMBER.'/templets/benefit.htm');
$tpl->Display();
?>