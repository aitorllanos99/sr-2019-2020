translate([-15,-1,0])
difference(){
    cube([30,2,23.8]);
    rotate([90,0,0])
    translate([15,12,-2])
    cylinder(h=3,r=1.5,$fn=200);
}
for(i=[-37.5,27.5]){
union(){
translate([i,-1,0])
difference(){

cube([10,2,23.8]);
 rotate([90,0,0])
for(j=[3,-5]) {
translate([j+2,12,-2])
 cylinder(h=6,r=1.5,$fn=200);
}
}
}
}
for(i=[-29.5,13]){
 union(){
translate([i,17.5,0])
cube([16.5,2,23.8]);
}
}
for(i=[27.5,13,-27.5-2,-13-2]){
union(){
rotate([0,0,90])
translate([1,i,0])
cube([16.5,2,23.8]);
}

}