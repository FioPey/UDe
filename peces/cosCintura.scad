use <servo.scad> 
$fn=90;
difference()
{
   cube([90,50,25]);
   translate([50,5,5])rotate([90,0,90])servo(true);
   translate([40,5,25])rotate([-90,0,90])servo(true);
   //Fixacio eix
   translate([45,35,-1])cylinder(r=3,h=27);
   translate([45,35,5])cylinder(r=11,h=27);
   
   translate([45,42,2.5])cylinder(r=3,h=27);
   translate([52,35,2.5])cylinder(r=3,h=27);
   translate([38,35,2.5])cylinder(r=3,h=27);
   translate([45,28,2.5])cylinder(r=3,h=27);
   
   translate([45,42,-2.5])cylinder(r=1.5,h=27);
   translate([52,35,-2.5])cylinder(r=1.5,h=27);
   translate([38,35,-1])cylinder(r=1.5,h=27);
   translate([45,28,-1])cylinder(r=1.5,h=27);
   
   translate([-3,-1,15])cube([20,55,20]);
   translate([73,-1,15])cube([20,55,20]);
   
   translate([-2,5,5])cube([40,40,20]);
   translate([0,5,5])cube([40,40,20]);
   translate([0,5,6])cube([40,40,20]);
   translate([55,5,5])cube([40,40,20]);
   translate([50,5,6])cube([40,40,20]);
   translate([10,-2,15])rotate([-90,0,0])cylinder(r=7,h=70);
   translate([80,-2,15])rotate([-90,0,0])cylinder(r=7,h=70);
   translate([-4,-2,8])cube([14,70,10]);
   translate([80,-2,8])cube([14,70,10]);
}
