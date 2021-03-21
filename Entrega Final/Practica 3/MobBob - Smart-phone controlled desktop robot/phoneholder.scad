translate([-35,-20.5,1])
cube([70,2,110]);

translate([-37,-32.5,1])
cube([2,14,40]);

translate([34.9,-32.5,1])
cube([2,14,40]);

translate([-35,-32.5,1])
cube([70,12,2]);

translate([-35,-32.5,1])
cube([70,2,10]);

hull(){
    translate([-26,-18,29])
    rotate([10,0,0])
    cube([4,14.5,3]);

    translate([-26,-19,55])
    rotate([-8,0,0])
    cube([4,10.5,3]);
}

hull(){
    translate([22,-18,29])
    rotate([10,0,0])
    cube([4,14.5,3]);

    translate([22,-19,55])
    rotate([-8,0,0])
    cube([4,10.5,3]);
}

translate([-22,-20,30])
cube([45,4,27.8]);

translate([-22,-19,28.7])
rotate([10,0,0])
cube([46,15.5,3]);
