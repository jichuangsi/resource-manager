<?php
require_once(dirname(__FILE__)."/config.php");
//ץȡ�ĵ�������ͼ
//��������Ķ�swf��ַ��ע��aid�Ǹ���ID����Ҫ���ҵ���Ӧ���ĵ�ID
//�Ȳ��Ҷ�Ӧ���ĵ�ID
$row = $dsql->GetOne("select arcid from #@__uploads where aid = '$aid'");

$aid = $row["arcid"];//���¾ͱ�ʾ�ĵ�ID�ˡ�


$row = $dsql->GetOne("select onlineviewurl from `#@__addonbook` where aid = '$aid'");

if($row["onlineviewurl"] == ""){//û���ҵ�Swf���˳� 
	echo "can't find the onlineviewurl!";
	exit();
}
$flash2jpeg = new COM("SunCN.Flash2Jpeg");
if ($flash2jpeg){
	$filename = '1'.'-'.dd2char(MyDate('ymdHis', time())).$rnddd.'-L';

	$filedir = $cfg_image_dir.'/'.MyDate($cfg_addon_savetype, time());
	
	//���Ŀ¼�����ڣ����ȴ���
	if(!file_exists($cfg_basedir.$filedir)){
		mkdir($cfg_basedir.$filedir, $cfg_dir_purview);
	}
	
	$fileurl = $filedir.'/'.$filename.'.jpg';
	
	$filepath = $cfg_basedir.$fileurl;

	$a = $flash2jpeg->Flash2Jpeg($cfg_basedir.$row['onlineviewurl'], 130, 140, $filepath);

	if ($a){ //��ȡʧ��
		$show_message.="Creat smallPic error!";

		$fileurl = "";

		echo $show_message;
	}else{ //��ȡ�ɹ�
		$show_message.="Creat smallPic OK.";

		//��������ͼ�ֶ�
		$dsql->ExecuteNoneQuery("Update `#@__archives` set litpic='$fileurl' where id='$aid' ");

		echo $show_message;
	}
	//$flash2jpeg->Release();
	$flash2jpeg = null;
	
}else{
	echo "Creat Flash2Jpeg error!";
}
?>