.rand.norm:{[n;u;s]
 Z:.qml.nicdf[n?1.0];
 X: u + s*Z
 }
 
.rand.mnorm:{[r;c]
 (r; c) # (.qml.nicdf (r*c)?1.0)
 }
 
.rand.norm:{[n]
 raze {U1:1?1.0;
 U2:1?1.0;
 R:sqrt (-2 * log U2);
 t:2*3.14*U1;
 X:R*cos t;
 Y:R*sin t } each til n
 }
 
.rand.phi:{[x] pi:3.14;(exp -1*x*x%2)%(sqrt 2*pi)}
.rand.normcdf:{[x] b0:0.2316419; b:0.31938153 -0.356563782 1.781477937 -1.821255978 1.330274429; $[x<0; 1 - .rand.normcdf neg x;[t:1%(1+b0*x); 1 - .rand.phi[x]*{sum b * t xexp x}[1+ til count b]]]
 }