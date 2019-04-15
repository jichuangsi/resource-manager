<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
 include $this->CompilerInclude("header.htm");
 ?>
<div id="side" class="left"> <?php include $this->CompilerInclude("side_icon.htm");
  include $this->CompilerInclude("side_class.htm");
  include $this->CompilerInclude("side_visitor.htm");
  include $this->CompilerInclude("side_search.htm");
 ?> </div>
<!--begin main-->
<div id="main" class="right">
  <div class="box">
    <h2>文档列表</h2>
    <!--begin-->
    <?php
$atts = array();
$atts['tagname'] = 'datalist';
$blockValue = $this->refObj->GetArcList($atts,$this->refObj,$fields); 
foreach( $blockValue as $key=>$fields )
{

	if($fields['channel']==1) {
			$fields['arcurl'] = "index.php?uid={$_vars['userid_e']}&action=viewarchives&aid={$fields['id']}";
	}
?>
    <div class="text">
      <h3> <a href="<?php echo $fields['arcurl']; ?>" class="noul"><?php echo $fields['title']; ?></a> </h3>
      <table class="blog-content">
        <tr>
          <td><p> <img src='<?php echo $fields['litpic']; ?>' /><br />
              <?php echo $fields['description']; ?> </p>
            <p><a href='<?php echo $fields['arcurl']; ?>'>&lt;&lt;详细内容</a> </td>
        </tr>
      </table>
      <div class="bb">
        <div> <a href="<?php echo $fields['arcurl']; ?>" target="_blank" title="<?php echo $fields['title']; ?>">浏览全文</a>(<?php echo $fields['click']; ?>) | <a href="<?php echo $GLOBALS['cfg_phpurl']; ?>/feedback.php?aid=<?php echo $fields['id']; ?>" target="_blank">好评度</a>(<?php echo $fields['scores']; ?>) |
          上传时间：<?php echo MyDate('Y-m-d h:i',$fields['pubdate']); ?> </div>
        <div class="c"></div>
      </div>
    </div>
    <?php
}
?>
    <div class="big">
      <div class="pages"><?php
$atts = array();
$atts['tagname'] = 'pagelist';
 echo $this->refObj->GetPageList($atts,$this->refObj,$fields); 
?>
</div>
      </a></span></div>
    <!--end-->
  </div>
</div>
<!--end main-->
<?php include $this->CompilerInclude("footer.htm");
 ?>