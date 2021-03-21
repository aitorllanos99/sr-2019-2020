hull(){
for(i = [24,-24],j=[29,-29]){
translate([i,j,-3])
union(){
cylinder(h=1,r=3,$fn=50);
     translate([0,-0.5,5])
    sphere(r=3,$fn=50);
}
}
}
translate([2.9,-2.5,1])
cube([5,10,15]);
translate([-25.5,-2.5,0])
cube([5,5,16]);