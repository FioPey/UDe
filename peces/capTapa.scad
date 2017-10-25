
$fn=90;
intersection()
{
  difference()
  {
    translate([0,0,22])sphere(23);
    translate([-11.5,-25,-1])cube([50,50,50]);
  }
  translate([-40,0,15+12.5+1.5])rotate([0,90,0])
  {
    cylinder(r=9.95,h=50);
  }
}
