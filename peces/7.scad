use <servo.scad>
$fn=200;

t=20.5;
rotate([0,-90])difference()
{
    union()
    {
        cube([21,65,50]);
        translate([60,65,0])cylinder(r=60,h=50);
    }
    translate([21,1,-1])cube([150,150,70]);
    rotate([0,0,0])
    {
        linear_extrude(height = 60)
        {
            polygon(points = [[0,0] ,[0,5],[10,28],[29.5,21],[20,0] ]);
        }
        translate([20,25])cylinder(r=10.5,h=60);
    }
    translate([20,25,5])rotate([0,0,t])translate([10,30,0])rotate([90,-90,0])servo();
    translate([15,-1,-1])cube ([50,20,60]);
}
