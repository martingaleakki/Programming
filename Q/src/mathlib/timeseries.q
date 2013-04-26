\l stat.q

.ts.isstat:{[t]
 
 }
 
.ts.multi:{[s;n;N;u;sig]
 ct:`a`b`c`d`e`f`g`h`i`j`k`l`m`n`o`p`q`r`s`t`u`v`w`x`y`z;
 tmp:.ts.uni[s;N;u;sig;ct[0]];
 mu:?[tmp;();();ct[0]];
 while[n-:1;tmp:aj[`date;tmp;.ts.uni[s;N;mu;sig%n;ct[n]]]];
 update int:1 from tmp
 }
 
.ts.uni:{[s;N;u;sig;c]
 date:s + til N;
 names:c;
 tmp:([] date:date);
 ![tmp;();0b; (enlist names)! (enlist (u + sig * nor N ))] 
 }