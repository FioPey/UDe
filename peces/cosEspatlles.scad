//En realitat son 50mm d'altura però els 5 que falten son de la tapa
//La Bat fa casi 60x30(amb el cable 35)x15 mm
//l'eix del servo amb el connector fa 7mm
use <servo.scad> 
$fn=90;
difference()
{
    cube([110,60,45]);
    //Espatlla dreta
    translate([65,45,25])rotate([90,0,0])servoUncostat();
    translate([65,15,35])rotate([0,90])cylinder(r=7,h=50,$fn=90);
    translate([65,8,35])cube([50,14,10]);
    //Espatlla esquerre
    translate([45,45,45])rotate([90,180,0])servoUncostat();
    translate([-5,15,35])rotate([0,90])cylinder(r=7,h=50,$fn=90);
    translate([-5,8,35])cube([50,14,10]);
    translate([5,5,35])cube([40,40,50]);
    translate([5,10,35])cube([100,35,40]);
    //Cintura
    translate([65,13,5])rotate([0,0,90])servoUncostat(true);
    translate([55,60.5,35])rotate([90,0,0])
    {
        cylinder(r=10.5,h=16);
        translate([-10.5,0,0])cube([21,10.5,16]);
    }
    translate([5,-2,3])cube([35,60,17]);
    translate([70,-2,3])cube([35,60,17]);
    //Motxilla
    translate([55,-1,0])rotate([-90,0,0])cylinder(r=10,h=6);
    translate([55,4,3])rotate([-90,0,0])cylinder(r=1.25,h=15);
    //Tapa
    translate([55,-1,45])rotate([-90,0,0])cylinder(r=10,h=4);
    translate([55,-1,42])rotate([-90,0,0])cylinder(r=1.25,h=15);
    
    translate([87.5,57,45])rotate([-90,0,0])cylinder(r=10,h=4);
    translate([87.5,44,42])rotate([-90,0,0])cylinder(r=1.25,h=14);
    
    translate([22.5,57,45])rotate([-90,0,0])cylinder(r=10,h=4);
    translate([22.5,44,42])rotate([-90,0,0])cylinder(r=1.25,h=14);
    //Fixació coll
    translate([55,6,32.5])rotate([90,90,0])union()
    {   hull()
        {
            cylinder(r=3.5,h=1.6);
            translate([14.5,0,0])cylinder(r=2,h=1.6);
        }
        cylinder(r=3.5,h=4.1);
        translate([6.5,0,-5])cylinder(r=0.5,h=7.5);
        translate([6.5,0,2.5])cylinder(r=2.6,h=4);
        translate([14.5,0,-2])cylinder(r=0.5,h=7.5);
        translate([14.5,0,5])cylinder(r=2.6,h=4);
        translate([0,0,-18])cylinder(r1=6,r2=3,h=18);
        translate([0,0,4.2])cylinder(r=9,h=18);
        translate([-15,-3.5])cube([15,7,4.1]);
    }
}
