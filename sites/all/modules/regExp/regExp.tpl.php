<?php
$closp = '</p>';
//Echo Classes.
$Dc = '<p>Download files has been Classes:';
$truRezC = array_unique($rezC[2]);
foreach ($truRezC as $v) {
$class .= "<br />&#160;&#160;$v";
}
//Echo Methods.
$Dm = '<p>Download files has been Methods:';
$truRezM = array_unique($rezM[1]);
foreach ($truRezM as $v) {
$method .= "<br />&#160;&#160;$v";
}
//Echo V.
$Dp = '<p>Download files has been Values:';
$truRezP = array_unique($rezP[1]);
foreach ($truRezP as $v) {
$property .=  "<br />&#160;&#160;$v";
}
return $Dc . $class . $Dm . $method . $Dp . $property;
  



