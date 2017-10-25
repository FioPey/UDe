use <servo.scad>
$fn=120;

difference()
{
    union()
    {
        cube([30,60,21]);
        translate([30,0,10.5])rotate([-90,0])cylinder(r=10.5,h=60);
    }
    translate([5,5,-0.5])cube([40,50,22]);
    translate([30,52,10.5])rotate([-90,0])encaix();
    translate([30,8,10.5])rotate([90,0])encaix();
    translate([-3,30,10.5])rotate([0,90])encaix();
}
