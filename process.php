<?php
require_once('entry.php');
$myfile = fopen("data.txt", "r") or die("Unable to open file!");
$content = fread($myfile,filesize("data.txt"));
$people = explode("\n", $content);
$existing = array();
$string = "<table class=\"table\">
  <thead class=\"thead-inverse\">
    <tr>
      <th>Incident Number</th>
      <th>Incident Reporter</th>
      <th>License Plate Reporter</th>
      <th>License Plate Other</th>
    </tr>
  </thead>
  <tbody>";
for($i = 0;$i < sizeof($people);$i++)
{
	$info = explode(':',$people[$i]);
	$temp = new Entry($info[0],$info[1],$info[2]);
	//echo "<br /> The Password is: ".$temp->userName;
	$existing[$i] =  $temp;
}
for($j = 0;$j < sizeof($existing);$j++)
{
	$string = $string. "<tr>";
	$string =  $string. "<td>".($j+1)."</td>";
	$string =  $string."<td>".$existing[$j]->getRName() ."</td>";
	$string =  $string."<td>". $existing[$j]->getRPlate() ."</td>";
	$string =  $string."<td>". $existing[$j]->getOPlate() ."</td>";
	//echo "<br /> The Password is: ".$existing[$j]->userName;
	//echo $existing[$j]->getRName();
	$string = $string. "</tr>";
	
}
fclose($myfile);
$string = $string. "</tbody>
</table>";
echo $string;
?>