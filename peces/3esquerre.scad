use <servo.scad>
$fn=200;
R=19;
difference()
{
    cylinder(r=32.5,h=90);
    translate([0,0,80])cylinder(r=25,h=95);//Tall a dalt
    //per a que el servo de dalt pugui girar be:
    translate([0,21,70])rotate([90,0,0])cylinder(r=15,h=42);//Tall a dalt
    //i el de baix
    translate([0,21,10])rotate([90,0,0])cylinder(r=22.3,h=42);//Tall a dalt
    //forat per la forquilla del peu
    translate([-32.5,-11.5,-1])cube([66,23,29]);
   translate([-35,15,80])union()//trapezi:
    {
        cube([70,20,20]);
        translate([0,-34.5,10])cube([70,45,20]);
        rotate([45,0])cube([70,16,20]);
        translate([0,-50])cube([70,20,20]);
        translate([0,-30])rotate([-45,0])translate([0,-16,0])cube([70,16,20]);
    }
    //arrodonimentCostats
    translate([0,0,40])rotate_extrude(convexity = 10){
      translate([55.0,0, 0])
      {
        circle(r =27.5, $fn = 100);
      }
    }
    translate([-10,-30,28])cube([20,60,24]);
    
    //Forat de secció:
    translate([-40,-32.5,-1])cube([30,65,95]);
    //Tall de dins:
    translate([-11,-25.5,-5])cube([21,51,90]);
    //Encaixos turmell
    translate([0,22.5,10])rotate([-90,0,0])encaix(true);//Encaix pel tormell
    translate([0,-22.5,10])rotate([90,0,0])encaix(true);//Encaix pel tormell
    //Encaixos genoll
    translate([0,22.5,70])rotate([-90,0,0])encaix(true);//Encaix pel genoll
    translate([0,-22.5,70])rotate([90,0,0])encaix(true);//Encaix pel genoll
    //Forat per a que passi el peu
    translate([0,30,10.5])rotate([90,0,0])difference()
{
  cylinder(r=40,h=30);
  translate([0,0,-1])cylinder(r=15,h=40);
  translate([-45,0,-1])cube([90,90,90]);
}
  translate([15,11,10.5])rotate([0,29,0])cube([40,19,30]);

}
//aro pels cables
difference()
{
  
translate([-10,28,5.5])rotate([90,0,0])rotate_extrude(convexity = 10)
{
  translate([4, 0, 0])
      circle(r = 1.5, $fn = 100);
}
translate([0,22.5,10])rotate([-90,0,0])encaix(true);//Encaix pel tormell
}
difference()
{
  
translate([-10,28,80])rotate([90,0,0])rotate_extrude(convexity = 10)
{
  translate([4, 0, 0])
      circle(r = 1.5, $fn = 100);
}
translate([0,22.5,70])rotate([-90,0,0])encaix(true);//Encaix pel tormell
}


