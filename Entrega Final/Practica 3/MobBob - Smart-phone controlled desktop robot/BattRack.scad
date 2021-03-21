anchoCubo = 3;
alturaCubo = 20;
largoCubo = 42;
for (i = [12, -12-anchoCubo]){
    translate([i,0,0])
    cube([anchoCubo,largoCubo,alturaCubo]);
}
rotate([0,0,90])
translate([39,-15,0])
cube([anchoCubo,28,alturaCubo]);
for(i=[12,-26-anchoCubo]){
    rotate([0,90,0])
    translate([-4,1/1.4,i])
    cube([anchoCubo+1,11,17]);
   }

