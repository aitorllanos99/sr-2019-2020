anchoCubo = 3;
alturaCubo = 10;


difference() {
translate([-17,27.5,5])
cube ([40,anchoCubo,alturaCubo], center = true);
rotate([90, 0, 0])
translate([-17,5,-35])
cylinder(h = 10, r = 2, $fn=50);
    
rotate([90, 0, 0])
    for(i = [-26, -8])
translate([i,5,-30])
cylinder(h = 10, r = 0.5, $fn=50);


}



hull() {
rotate([0,0,90])
translate([20.5,35.5,5])
union() {
cube ([11,anchoCubo,alturaCubo], center = true);
translate([-15,anchoCubo/2,0])
rotate([90, 0, 0])
    cylinder(h = anchoCubo, r = alturaCubo/2,$fn=50);   
}
}
translate([-35,5,5])
rotate([0, 90, 0])
cylinder(h = 6, r = 2.5, $fn=50);


difference() {
 hull(){
rotate([0,0,90])
translate([20.5,-1.5,5])
union() {
cube ([15.5,anchoCubo,alturaCubo], center = true);
translate([-15,anchoCubo/2,0])
rotate([90, 0, 0])
    cylinder(h = anchoCubo, r = alturaCubo/2,$fn=50);
}
}
for(i=[18, 11.8]) {
translate([-5,i,alturaCubo/2])
rotate([0, 90, 0])
    cylinder(h = 10, r = 0.5,$fn=50); 
}
translate([-5,5,alturaCubo/2])
rotate([0, 90, 0])
    cylinder(h = 10, r = 2.5,$fn=50); 
}



