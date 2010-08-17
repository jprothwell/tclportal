<?php
Function getRandNumber ($fMin, $fMax) {
	srand((double)microtime()*1000000);
	$fLen   =   "%0 ".strlen($fMax). "d ";
	Return   sprintf($fLen,   rand($fMin,$fMax));
}
$str=getRandNumber(1000,9999);
setcookie("chknumber",$str);
$width = 45;
$height = 18;
@header("Content-Type:image/png");
$im=imagecreate($width,$height);
$back=imagecolorallocatealpha($im,0,0,0,127);
$font=imagecolorallocate($im,255,255,255);
imagestring($im, 5, 5, 4,$str, $font);
imagepng($im);
imagedestroy($im);
?>

