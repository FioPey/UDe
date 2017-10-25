use <servo.scad>
$fn=120;
difference()
{
    rotate([90,0,0])
    {
        linear_extrude(height = 64)
        {
            polygon(points = [[0,0] ,[0,5],[10,28],[29.5,21],[20,0] ]);
        }
        translate([20,25])cylinder(r=10.5,h=64);
    }
    translate([-1,-55-2,5])cube([50,50,50]);
    translate([10.5,-30-2,-3])encaix();
    translate([20,-8-2,25])rotate([-90,0])encaix();
    translate([20,-52-2,25])rotate([90,0])encaix();
}
