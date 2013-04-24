t:til 10;

t: 2 3 5 7 11 13 17 19 23 29;

A:169;
B:83;
C:0;
while[(A-B)>2; A:A-2;C:C+1]

is_prime:{s: floor sqrt x; 
	i:2; 
	is_p:0b; 
	while[(i<=s) and (not is_p);
		is_p: (0 = (x  mod i));
		i:i+1
		] 
	i
	} 