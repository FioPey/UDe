
$fn=200;
r_c=25;
h_c=50;
x_cub=40;
y_cub=30;
z_cub=20;
r_s=70;
off=10;  
difference()//intersection()//per canviar entre la tapa i el cap
{
    union()
    {
        
        intersection()
        {
            difference()
            {
                intersection()
                {
                    hull()
                    {
                        difference()
                        {
                          
                            translate([0,0,off])rotate([0,90])cylinder(r=r_c,h=h_c);
                            translate([-5,-r_c-5,-r_c-5])cube([h_c+10,2*r_c+10,r_c+5]);
                        }
                        translate([(h_c-x_cub),-y_cub/2,-z_cub])cube([x_cub,y_cub,z_cub]);
                    }
                    translate([-(r_s-h_c),0,off])sphere(r=r_s);
                    translate([r_s+9,0,off])sphere(r=r_s);
                }
                //Servo
                translate([h_c-23-5-4,-13/2,-21])cube([23,13,20]);
                //Cable servo
                translate([h_c-22.5-5-6,-5/2,-21])cube([22.5,5,20]);
                //UEYE
                translate([h_c-25,-23.5/2])cube([20.5,23.5,27.5]);
                //Forat Cable
                translate([h_c-25+4.5-5,0,14.5-6])cube([10,50,12]);
                //Forat per la lent:
                translate([h_c-5.5,0,16])rotate([0,90])cylinder(r1=5.5,r2=15,h=6);
                //Forat per encaixar la tapa
                translate([22,0,0])cylinder(r=0.75,h=50);
                translate([22,0,31.5])cylinder(r=1.5,h=5);
            }
            translate([r_c+off,45,0])rotate([90,0])cylinder(r=r_c+off,h=90);
        }
    }
    translate([0,0,27.5/2])rotate([90,45,90])cylinder(r=19.5,h=25.1,$fn=4);
    
}



