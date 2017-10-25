$fn=90;

difference()
{
    hull()
    {
        cylinder(r=7.5,h=29-7.5);
        translate([0,0,29-7.5])sphere(7.5);
        translate([55-10,0,0])
        {
            cylinder(r=7.5,h=29-7.5);
            translate([0,0,29-7.5])sphere(7.5);
        }
        translate([0,78-14,0])
        {
            cylinder(r=7.5,h=29-7.5);
            translate([0,0,29-7.5])sphere(7.5);
        }
        translate([55-10,78-14,0])
        {
            cylinder(r=7.5,h=29-7.5);
            translate([0,0,29-7.5])sphere(7.5);
        }
    }
    hull()
    {
        translate([0,2.5,0])cylinder(r=5,h=29-10);
        translate([0,2.5,29-10])sphere(5);
        translate([55-10,2.5,0])
        {
            cylinder(r=5,h=29-10);
            translate([0,0,29-10])sphere(5);
        }
        translate([0,78-2.5-14,0])
        {
            cylinder(r=5,h=29-10);
            translate([0,0,29-10])sphere(5);
        }
        translate([55-10,78-2.5-14,0])
        {
            cylinder(r=5,h=29-10);
            translate([0,0,29-10])sphere(5);
        }
    }
    //Forat cables alimentació
    translate([2,12.5-2.5])rotate([0,-90])cylinder(r=7.5,h=10);
    //Forat cable servos
    translate([35,2,5])cube([25,61,40]);
    //Forat programador
    translate([-10,55,5])cube([27.5,75,40]);
    

}
difference()
{
translate([-2.5,(78-14)/2])rotate([0,-90])difference()
{
  cylinder(r=10,h=5);
  translate([-3,0,-1])cylinder(r=1.5,h=7);
  translate([-3,0,2])cylinder(r=3,h=7);
}
 hull()
    {
        translate([0,2.5,0])cylinder(r=5,h=29-7.5);
        translate([0,2.5,29-7.5])sphere(5);
        translate([55-15,2.5,0])
        {
            cylinder(r=5,h=29-7.5);
            translate([0,0,29-7.5])sphere(5);
        }
        translate([0,78-2.5,0])
        {
            cylinder(r=5,h=29-7.5);
            translate([0,0,29-7.5])sphere(5);
        }
        translate([55-15,78-2.5,0])
        {
            cylinder(r=5,h=29-7.5);
            translate([0,0,29-7.5])sphere(5);
        }
    }

}