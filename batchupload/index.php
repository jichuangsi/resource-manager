<?php

require_once(dirname(__FILE__)."/config.php");

require_once(DEDEINC."/dedetag.class.php");
require_once(DEDEINC."/userlogin.class.php");
require_once(DEDEINC."/customfields.func.php");
require_once(DEDEMEMBER."/inc/inc_catalog_options.php");
require_once(DEDEMEMBER."/inc/inc_archives_functions.php");
$channelid = isset($channelid) && is_numeric($channelid) ? $channelid : 17;//�鼮Ƶ��ģ��ID
$typeid = isset($typeid) && is_numeric($typeid) ? $typeid : 0;

$title=iconv("GB2312","UTF-8", $title);
$softurl1=iconv("GB2312","UTF-8", $softurl1);
$description=iconv("GB2312","UTF-8", $description);

	//������ֶε�Ĭ��ֵ beign by caozhiyang-------------------------------------
	$tags = '';
	//$writer = $cfg_ml->M_UserName;//��ǰ��Ա����
	$language = iconv("GB2312","UTF-8", '��������');
	$softtype = iconv("GB2312","UTF-8", '�����ĵ�');
	$accredit = iconv("GB2312","UTF-8", '�����ĵ�');
	$os = 'Win2003,WinXP,Win2000,Win9X';
	$softrank = '3';
	$officialDemo = '';
	$officialUrl = '';
	$source = '';
	//������ֶε�Ĭ��ֵ end-------------------------------------
	
	//$description = '';
	

	//ȡһ��Ĭ�Ϸ���
	$cts = $dsql->GetOne("Select id From `#@__arctype` where channeltype='$channelid' and ispart = 0 ");
	$typeid = trim($cts['id']);
	
	//���
	include('archives_check.php');
	
   //�����ĵ�ID
	$arcID = GetIndexKey($arcrank,$typeid,$sortrank,$channelid,$senddate,$mid);
	if(empty($arcID))
	{
		ShowMsg("�޷��������������޷����к���������","-1");
		exit();
	}



	//�Զ���ȡ�ؼ��� added by caozhiyang
	if($keywords=='')
	{
		$subject = $title;
		$message = $body;
		include_once(DEDEINC.'/splitword.class.php');
		$keywords = '';
		$sp = new SplitWord($cfg_soft_lang, $cfg_soft_lang);
		$sp->SetSource($subject, $cfg_soft_lang, $cfg_soft_lang);
		$sp->StartAnalysis();
		$titleindexs = preg_replace("/#p#|#e#/",'',$sp->GetFinallyIndex());
		$sp->SetSource(Html2Text($message), $cfg_soft_lang, $cfg_soft_lang);
		$allindexs = preg_replace("/#p#|#e#/",'',$sp->GetFinallyIndex());
		if(is_array($allindexs) && is_array($titleindexs))
		{
			foreach($titleindexs as $k => $v)
			{
				if(strlen($keywords.$k)>=60)
				{
					break;
				}
				else
				{
					$keywords .= $k.',';
				}
			}
			foreach($allindexs as $k => $v)
			{
				if(strlen($keywords.$k)>=60)
				{
					break;
				}
				else if(!in_array($k,$titleindexs))
				{
					$keywords .= $k.',';
				}
			}
		}
		$sp = null;
		$keywords = addslashes($keywords);
	}
	
	//��Ҫ���
	$arcrank = -1;

	//���浽����
	$inQuery = "INSERT INTO `#@__archives`(id,typeid,sortrank,flag,ismake,channel,arcrank,click,money,title,shorttitle,
color,writer,source,litpic,pubdate,senddate,mid,description,keywords)
VALUES ('$arcID','$typeid','$sortrank','$flag','$ismake','$channelid','$arcrank','0','$money','$title','$shorttitle',
'$color','$writer','$source','$litpic','$pubdate','$senddate','$mid','$description','$keywords'); ";
	if(!$dsql->ExecuteNoneQuery($inQuery))
	{
		$gerr = $dsql->GetError();
		$dsql->ExecuteNoneQuery("Delete From `#@__arctiny` where id='$arcID' ");
		ShowMsg("�����ݱ��浽���ݿ����� `#@__archives` ʱ��������ϵ����Ա��","javascript:;");
		exit();
	}

	//added by ��־��������Ҫ���ݸ���IDȡ����·���͸�����С
	
	//���ص�ַ�����û�ǰ̨����������̨���ݸ���ID��t_uploads����ȡ����
	//$row = $dsql->GetOne("Select aid,title,url From `#@__uploads` where aid = ".$uploadId."; ");
	//$softurl1 = $row["url"];//ȡ���ϴ��ļ��ĵ�ַ
	
	//�ĵ������б���ֻ���Ǳ������ӵ������
	$softurl1 = stripslashes($softurl1);
	$urls = '';
	$softsize = '';
	if($softurl1!='')
	{
		$urls .= "{dede:link islocal='1' text='��������'} $softurl1 {/dede:link}\r\n";
		//ȡ�ļ���չ��
		$file_part  = pathinfo($softurl1);
		$filetype = $file_part["extension"];
		$softsize = @filesize($cfg_basedir.$softurl1);
		if(empty($softsize)) $softsize = iconv("GB2312","UTF-8", 'δ֪');
		else
		{
			$softsize = trim(sprintf("%0.2f", $softsize / 1024 / 1024));
			$softsize = $softsize." MB";
		}
	}
	/**���������ݲ�����ȫ�Ǳ�������
	for($i=2;$i<=12;$i++)
	{
		if(!empty(${'softurl'.$i}))
		{
			$servermsg = str_replace("'","",stripslashes(${'servermsg'.$i}));
			$softurl = stripslashes(${'softurl'.$i});
			if($servermsg=='')
			{
				$servermsg = '���ص�ַ'.$i;
			}
			if($softurl!='' && $softurl!='http://')
			{
				$urls .= "{dede:link text='$servermsg'} $softurl {/dede:link}\r\n";
			}
		}
	}
	*/
	//�����С
	$urls = addslashes($urls);

	//���浽���ӱ�
	$needmoney = @intval($needmoney);
	if($needmoney > 100) $needmoney = 100;
	$cts = $dsql->GetOne("Select addtable From `#@__channeltype` where id='$channelid' ");
	$addtable = trim($cts['addtable']);
	if(empty($addtable))
	{
		$dsql->ExecuteNoneQuery("Delete From `#@__archives` where id='$arcID'");
		$dsql->ExecuteNoneQuery("Delete From `#@__arctiny` where id='$arcID'");
		ShowMsg("û�ҵ���ǰģ��[{$channelid}]��������Ϣ���޷���ɲ�������","javascript:;");
		exit();
	}
	//Ĭ����Ҫע���Ա�������� daccess������Ӧ�Ļ�Ա�ȼ�ID 10-ע���Ա��50-�м���Ա...
	$inQuery = "INSERT INTO `$addtable`(aid,typeid,filetype,language,softtype,accredit,
    os,softrank,officialUrl,officialDemo,softsize,softlinks,introduce,userip,templet,redirecturl,daccess,needmoney{$inadd_f})
    VALUES ('$arcID','$typeid','$filetype','$language','$softtype','$accredit',
    '$os','$softrank','$officialUrl','$officialDemo','$softsize','$urls','$description','$userip','','','10','$needmoney'{$inadd_v});";
	if(!$dsql->ExecuteNoneQuery($inQuery))
	{
		$gerr = $dsql->GetError();
		$dsql->ExecuteNoneQuery("Delete From `#@__archives` where id='$arcID'");
		$dsql->ExecuteNoneQuery("Delete From `#@__arctiny` where id='$arcID'");
		echo $inQuery;
		exit();
		ShowMsg("�����ݱ��浽���ݿ⸽�ӱ� `{$addtable}` ʱ������������Ϣ�ύ���ٷ���".str_replace('"','',$gerr),"javascript:;");
		exit();
	}

	//���ӻ���
	$dsql->ExecuteNoneQuery("Update `#@__member` set scores=scores+{$cfg_sendarc_scores} where mid='".$cfg_ml->M_ID."' ; ");

	//���½����ĵ��ϴ� added by caozhiyang 2010-08-12
	doSysStatistics("new_doc");

	//����ͳ��
	countArchives($channelid);
	
	//����HTML
	$tags = $keywords;//�ؼ�����Ϊ��ǩ
	InsertTags($tags,$arcID);
	
	$artUrl = MakeArt($arcID,true);
	
	//��Ա��̬��¼
	//$cfg_ml->RecordFeeds('addsoft',$title,$description,$arcID);
	//$query = "INSERT INTO `#@__member_feed` (`mid`, `userid`, `uname`, `type`, `aid`, `dtime`,`title`, `note`, `ischeck`) 
	//					Values('$this->M_ID', '$this->M_LoginID', '$this->M_UserName', '$type', '$aid', '$ntime', '$title', '$note', '$ischeck'); ";
	//$dsql->ExecuteNoneQuery($query);

	
	//����������һ���ļ���¼
	$softsize = @filesize($cfg_basedir.$softurl1);
	$uptime = time();
	$inquery = "INSERT INTO `#@__uploads`(arcid, title,url,mediatype,filetype,width,height,playtime,filesize,uptime,mid)
	   VALUES ('$arcID', '$title','$softurl1','$medaitype', '$filetype', '0','0','0','$softsize','$uptime','".$mid."'); ";
	$dsql->ExecuteNoneQuery($inquery);

	$fid = $dsql->GetLastID();
	
	exit(0);

?>