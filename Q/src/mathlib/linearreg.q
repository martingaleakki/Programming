.mathlib.linearreg:{[x;y]
 x:"f"$x;
 y:"f"$y;
 coefs:$[(type x)=0h;
	(inv (flip x) mmu x) mmu ((flip x) mmu y);
	(x mmu y) % (x mmu x)];
 res: y - $[(type x)=0h; (x mmu coefs); x  * coefs];
 rss:raze (res) mmu res;
 sstot: raze (((y - first avg y)) mmu (y - first avg y));
 result:() ! ();
 result[`coefs]:coefs;
 result[`rss]:rss;
 result[`r2]:1 - (rss)%sstot;
 result[`res]: res;
 result[`sstot]:sstot;
 result[`n]: count y;
 result
 }
 
 
.mathlib.lu:{[X]n:count[X]-1;
 if[n=0;:(1f;X[0;0])];
 r:.mathlib.lu[X[0+til n;0+til n]];
 $[n=1;v:X[0+til n;n];v:lsq[X[0+til n;n];flip r[0]]];
 $[n=1;mT:X[n;0+til n]%r[1];mT:lsq[X[n;0+til n];r[1]]];
 w:X[n;n]-mT wsum v;
 L:(r[0],'n#0f),enlist(mT,1f);
 U:(r[1],'v),enlist((n#0f),w);
 : (L;U)
 };
 
.mathlib.det:{[X] n:count[X]; :prd .mathlib.lu[X][1] ./: (til n),'til n};

.mathlib.gaussnD:{[X;M;S] 
 if[not S~flip S;'`symmetry];
 if[not all n=/:(count[S];count[M];n:count[X]);'`size];
 reciprocal[xexp[(2*acos -1);n%2]*sqrt[.mathlib.det[S]]]*exp[neg((X-M)$inv[S]$(X-M))%2]
 }
 
/
data:.ts.multi[2000.01.01;10;ceiling 100*365.25;0;1]
result:exec .mathlib.linearreg[flip (c;b);a] from data where date.year within 2000 2050