<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?><html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>业务管理</title>
<link href="img/base.css" rel="stylesheet" type="text/css" />
<script language="javascript">
//获得选中项
function getCheckboxItem()
{
	var allSel="";
	if(document.form1.aids.value) return document.form1.aids.value;
	for(i=0;i<document.form1.aids.length;i++)
	{
		if(document.form1.aids[i].checked)
		{
			if(allSel=="")
				allSel=document.form1.aids[i].value;
			else
				allSel=allSel+"`"+document.form1.aids[i].value;
		}
	}
	return allSel;
}
function ReSel()
{
	for(i=0;i<document.form1.aids.length;i++)
	{
		if(document.form1.aids[i].checked) document.form1.aids[i].checked = false;
		else document.form1.aids[i].checked = true;
	}
}
//设置提现记录为已付款
function UpSel()
{
	var nid = getCheckboxItem();
	if(nid==""){
		alert("请选择要更改的提现记录!\r\n");
		return ;
	}
	location.href = "member_benefit_do.php?dopost=upbenefit&nid="+nid;
}
//设置为已审核
function CheckSel()
{
	var nid = getCheckboxItem();
	if(nid==""){
		alert("请选择要更改的提现记录!\r\n");
		return ;
	}
	location.href = "member_do.php?dopost=checkedbenefit&nid="+nid;
}
//设置为拒绝
function RefuseSel()
{
	var nid = getCheckboxItem();
	if(nid==""){
		alert("请选择要更改的提现记录!\r\n");
		return ;
	}
	location.href = "member_do.php?dopost=refusebenefit&nid="+nid;
}
</script>
</head>
<body background='img/allbg.gif' leftmargin='8' topmargin='8'>
<table width="98%" border="0" cellpadding="1" cellspacing="1" align="center" class="tbtitle" style="background:#cbd8ac;margin-bottom:5px;">
  <tr>
    <td height="30" align="center" bgcolor="#FAFCEF">
	<form name="form2" method="get" action="member_benefit.php">
        <table border="0" cellspacing="0" cellpadding="0">
          <tr>
            <td>输入会员名称：</td>
            <td>
              <input name="userid" type="text" id="userid"></td>
            <td width="100" align="center"> <input name="imageField" type="submit" value="搜索" class='np coolbg' />
            </td>
          </tr>
        </table>
      </form></td>
  </tr>
</table>
<table width="98%" border="0" cellpadding="1" cellspacing="1" align="center" class="tbtitle" style="background:#cbd8ac;">
  <tr>
    <td height="28" colspan="9" bgcolor="#EDF9D5" background='img/tbg.gif'>
    	<table width="98%" border="0" cellspacing="0" cellpadding="0">
        <tr>
          <td width="30%">&nbsp;<strong>&gt;
            会员提现管理：</strong> </td>
          <td width="45%" align="right" style="padding-top:4px;">
          	<input type="button" name="ss13" value="未审核" style="width:50px;margin-right:6px" onClick="location='member_benefit.php?sta=0';" class='np coolbg' />
            <input type="button" name="ss13" value="已拒绝" style="width:50px;margin-right:6px" onClick="location='member_benefit.php?sta=1';" class='np coolbg' />
            <input type="button" name="ss14" value="已同意/未付款" style="width:100px;margin-right:6px" onClick="location='member_benefit.php?sta=2';" class='np coolbg' />
            <input type="button" name="ss142" value="已付款" style="width:50px;margin-right:6px" onClick="location='member_benefit.php?sta=3';" class='np coolbg' />
            <input type="button" name="ss16" value="全部" style="width:40px;margin-right:6px" onClick="location='member_benefit.php';" class='np coolbg' />
          </td>
          <td width="25%" align="right" style="padding-top:4px;">
          	<input type="button" name="ss12" value="会员管理" style="width:90px;margin-right:6px" onClick="location='member_main.php';" class='np coolbg' />
          </td>
        </tr>
      </table></td>
  </tr>
  <tr bgcolor="#F8FBFB">
    <td width="5%" align="center">选择</td>
    <td width="5%" align="center">会员ID</td>
    <td width="15%" align="center">会员名称</td>
    <td width="7%" align="center">提现金币</td>
    <td width="8%" align="center">提现人民币</td>
    <td width="15%" align="center">提现账号</td>
    <td width="15%" align="center">申请时间</td>
    <td width="10%" align="center">状态</td>
    <td width="20%" align="center">操作</td>
  </tr>
  <form name="form1">
<?php
$atts = array();
$atts['tagname'] = 'datalist';
$blockValue = $this->refObj->GetArcList($atts,$this->refObj,$fields); 
foreach( $blockValue as $key=>$fields )
{
?>
    <tr bgcolor="#FFFFFF">
      <td align="center">
<input type='checkbox' name='aids' value='<?php echo $fields['id']?>' class='np'></td>
      <td align="center">
        <?php echo $fields['mid']?>
      </td>
      <td align="center">
        <?php
        echo GetMemberID($fields['mid']);
        ?>
      </td>
      <td align="center">
        <?php echo $fields['money']?>
      </td>
      <td align="center">
        <?php echo $fields['rmb']?>
      </td>
      <td align="center">
        <?php echo $fields['account']?>
      </td>
      <td align="center">
        <?php echo $fields['addtime']?>
      </td>
      <td align="center">
        <?php echo GetSta($fields['status'])?>
      </td>
      <td align="center">
        <input type="button" name="ss16" value="同意" style="width:40px;margin-right:6px" onClick="location='member_benefit_do.php?dopost=checkedbenefit&nid=<?php echo $fields['id']?>';" class='np coolbg' />
        <input type="button" name="ss16" value="拒绝" style="width:40px;margin-right:6px" onClick="location='member_benefit_do.php?dopost=refusebenefit&nid=<?php echo $fields['id']?>';" class='np coolbg' />
        <input type="button" name="ss16" value="已付款" style="width:50px;margin-right:6px" onClick="location='member_benefit_do.php?dopost=upbenefit&nid=<?php echo $fields['id']?>';" class='np coolbg' />
      </td>
    </tr>
<?php
}
?>
  </form>
  <tr>
    <td height="28" colspan="9" bgcolor="#FCFDF7" style="padding-top:4px;">
    	&nbsp;
      <input type="button" name="b7" value="反选" style="width:40" onClick="ReSel();" class='np coolbg' />
      <input type="button" name="b5" value="设为已付款状态" style="width:100" onClick="UpSel();" class='np coolbg' />
    </td>
  </tr>
  <tr>
    <td height="36" colspan="9" bgcolor="#FCFDF7" align="center">
     <?php
$atts = array();
$atts['tagname'] = 'pagelist';
$atts['listitem'] = 'info,index,end,pre,next,pageno';
$atts['listsize'] = '5';
 echo $this->refObj->GetPageList($atts,$this->refObj,$fields); 
?>

    </td>
  </tr>
</table>
</body>
</html>