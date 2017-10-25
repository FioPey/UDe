$fn=90;
Rencaixpetit=4.75;//medir
Hencaixpetit=5;//medir
Rencaixgran=10.5;
HencaixgranAmple=3;//comprovar
HencaixgranEstret=2;//Comprovar
distAmple=2;
distEstret=3;

module servo(encaix)
{
  
  {
    cube([40,20,40]);
    translate([0,10,30])rotate([0,270,0])//continuació eix
    {
      cylinder(r1=7,r2=6,h=2,$fn=90);
      cylinder(r=6.5/2,h=6,$fn=90);
    }
  }
  translate([40,10,30])rotate([0,90,0])//eix
  {
    color([0,0,0])cylinder(r1=7,r2=6,h=2,$fn=90);
    color([213/255,181/255,79/255]) cylinder(r=3,h=6,$fn=90);
  }
  translate([40,0,0])rotate([90,0,90])//3 forats per collar
  {
    translate([10,3])cylinder(r=1,h=10,$fn=90);
    translate([10,3,3])cylinder(r=1.75,h=7,$fn=90);
    translate([3,10])cylinder(r=1,h=10,$fn=90);
    translate([3,10,3])cylinder(r=1.75,h=7,$fn=90);
    translate([17,10])cylinder(r=1,h=10,$fn=90);
    translate([17,10,3])cylinder(r=1.75,h=7,$fn=90);
  }
  rotate([0,-90,0])
  {
    translate([2.5,2.5])cylinder(r=1,h=10,$fn=90);
    translate([2.5,2.5,3])cylinder(r=1.75,h=7,$fn=90);
    translate([2.5,17.5])cylinder(r=1,h=10,$fn=90);
    translate([2.5,17.5,3])cylinder(r=1.75,h=7,$fn=90);
    translate([17.5,2.5])cylinder(r=1,h=10,$fn=90);
    translate([17.5,2.5,3])cylinder(r=1.75,h=7,$fn=90);
    translate([17.5,17.5])cylinder(r=1,h=10,$fn=90);
    translate([17.5,17.5,3])cylinder(r=1.75,h=7,$fn=90);
  }
  if(encaix==true)
  {
    translate([45,10,30])rotate([0,270,0])//continuació eix
    {
      translate([0,0,-2.5])cylinder(r=7,h=55,$fn=90);
    }
     translate([-7.5,3,30])cube([55,14,10]);
  }
}

module servoUncostat(encaix)
{
  cube([40,20,40]);
  translate([40,10,30])rotate([0,90,0])//eix
  {
    color([0,0,0])cylinder(r1=7,r2=6,h=2,$fn=90);
    color([213/255,181/255,79/255]) cylinder(r=3,h=6,$fn=90);
  }
  translate([40,0,0])rotate([90,0,90])//3 forats per collar
  {
    translate([10,3])cylinder(r=1,h=10,$fn=90);
    translate([10,3,3])cylinder(r=1.75,h=7,$fn=90);
    translate([3,10])cylinder(r=1,h=10,$fn=90);
    translate([3,10,3])cylinder(r=1.75,h=7,$fn=90);
    translate([17,10])cylinder(r=1,h=10,$fn=90);
    translate([17,10,3])cylinder(r=1.75,h=7,$fn=90);
  }
}

module encaix(ample)
{
    cylinder(r=Rencaixpetit,h=Hencaixpetit);
    if (ample)translate([0,0,distAmple])cylinder(r=Rencaixgran,h=HencaixgranAmple);
    else translate([0,0,distEstret])cylinder(r=Rencaixgran,h=HencaixgranEstret);
    translate([0,0,-1])cylinder(r=1.5,h=15);
    translate([7,0,-3])cylinder(r=1.5,h=10);
    translate([-7,0,-3])cylinder(r=1.5,h=10);
    translate([0,7,-3])cylinder(r=1.5,h=10);
    translate([0,-7,-3])cylinder(r=1.5,h=10);
    translate([0,0,-1]) cylinder(r=3,h=16);
    translate([7,0,distAmple+HencaixgranAmple+2]) cylinder(r=3,h=10);
    translate([-7,0,distAmple+HencaixgranAmple+2]) cylinder(r=3,h=10);
    translate([0,7,distAmple+HencaixgranAmple+2]) cylinder(r=3,h=10);
    translate([0,-7,distAmple+HencaixgranAmple+2]) cylinder(r=3,h=10);
}

module servoBlau()
{
      cube([22,12.2,22]);
      translate([-5,0,15.5])cube([32,12.2,3.5]);
      translate([6,6,0])cylinder(r=6,h=26);
      translate([6+6.5,6,0])cylinder(r=3,h=26);
}

module encaix_continuacio()
{
    translate([0,0,1.5])cylinder(r=Rencaixpetit,h=1.5);
    translate([0,0,distEstret])cylinder(r=Rencaixgran,h=HencaixgranEstret);
    translate([0,0,-1])cylinder(r=1.5,h=15);
    translate([7,0,-3])cylinder(r=1.5,h=10);
    translate([-7,0,-3])cylinder(r=1.5,h=10);
    translate([0,7,-3])cylinder(r=1.5,h=10);
    translate([0,-7,-3])cylinder(r=1.5,h=10);
    translate([0,0,-1]) cylinder(r=3,h=16);
    translate([7,0,distAmple+HencaixgranAmple+2]) cylinder(r=3,h=10);
    translate([-7,0,distAmple+HencaixgranAmple+2]) cylinder(r=3,h=10);
    translate([0,7,distAmple+HencaixgranAmple+2]) cylinder(r=3,h=10);
    translate([0,-7,distAmple+HencaixgranAmple+2]) cylinder(r=3,h=10);
}

translate([0,10,30])rotate([0,270,0])//continuació eix
    {
      cylinder(r1=7,r2=6,h=2,$fn=90);
  
    }
