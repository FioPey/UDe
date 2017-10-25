use <servo.scad>
$fn=120;
difference()
{
    union()
    {
        translate([0,40,45]) rotate ([90,0,0]) cube([50,25,40]);
        cube([50,20,50]);        
    }
    translate([5,40,50])rotate([90,0,0])servo();
    translate([5,0,45])rotate([90,90,90])servo();
    
  translate([-1,10,70])rotate([180,0])
  {  
      translate([0,0,10])rotate([0,90,0])cylinder(r=7,h=55,$fn=90);
      translate([0,-7,0])cube([55,14,10]); 
  }
  translate([35,0,54])rotate([-90,90])
  {  
      translate([0,0,10])rotate([0,90,0])cylinder(r=7,h=55,$fn=90);
      translate([0,-7,0])cube([55,14,10]); 
  }
  translate([44.5,-6,33])cube([6,21,6]);
}
