<?php
require_once (dirname(__FILE__) . "/include/common.inc.php");
require_once (DEDEINC . "/arc.bookrequest.class.php");//�ĵ�����
$PageNo = $pageno;
$dlist = new BookRequestList('bookrequest_list.htm');
$dlist->Display();
exit();
?>