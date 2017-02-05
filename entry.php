<?php
class Entry
{
	var $rName;
	var $rPlate;
   var $oPlate;

	function Entry($rName, $rPlate,$oPlate) 
   {
       $this->rName = $rName;
       $this->rPlate = $rPlate;
       $this->oPlate = $oPlate;
   } 

   function getRName()
   {
   	return $this->rName;
   }
   function getRPlate()
   {
   	return $this->rPlate;
   }
   function getOPlate()
   {
      return $this->oPlate;
   }

   function setRName($name)
   {
   	$this->rName = $name;
   }
  function setRPlate($rPlate)
   {
      $this->rPlate= $rPlate;
   }
   function setOPlate($oPlate)
   {
      $this->oPlate= $oPlate;
   }
}
?>