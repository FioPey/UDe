$fn=90;
use <servo.scad>
difference()
{
    cylinder(r=25,h=60);
    translate([-30,-30,-2.5])cube([60,20,650]);//Seccio cilindre
    translate([-20,-11,25])cube([40,40,40]);//Forat Forquilla
    translate([-30.5,-10.5,50])difference()//arrodinimentForquilla
    {
        translate([0,-10-10-10])cube([55,40,20]);
        translate([-0.5,10.5,0])rotate([0,90])cylinder(r=10.5,h=56);
    }
    
    //Fixacio servo
    translate([-20,10,20])rotate([180,0,0])servo();
    translate([-20,10,80])rotate([180,0,0])servo();
    translate([-20,-11,-20])cube([40,20,40]);
    //Forats per al femur
    translate([22,0,50])rotate([0,90,0])encaix(true);//Encaix pel tormell
    translate([-22,0,50])rotate([0,-90,0])encaix(true);//Encaix pel tormell
    translate([-23/2,31.045])rotate([90-43.53119928561417,0])cube([23,50,90]);
}
//fixador del cable
difference()
{
translate([22,-11,5.5])rotate([0,90,0])rotate_extrude(convexity = 10)
{
  translate([4, 0, 0])
      circle(r = 1.5, $fn = 100);
}
    translate([-20,10,20])rotate([180,0,0])servo();

}
