#All useful codes 

##1d Segment tree with lazy propagation :
	
	my solution above calculates number of elements  in a given array which are multiples of 3.
	qsn link : lightoj.com/volume_showproblem.php?problem=1135.s  

##2d segment tree :
 	
	As we know 1d segment tree for array queries such as update,range sums etc..
	2d segment tree is used for matrix queries. 

	Queries are of 
	1) update an element
	2) range query like : sum of elements from a to b row and  c to d column   

	complexity of each query is log n * log m. where n= rows and m = columns. 

##Set inclusion and Exclusion :
	
	this solution is useful when we deal with all the subsets present in an array.
	there are 2^n subsets. 

	we can generate subsets only when n is smaller . 
	range of n :  n < 20 .

## Maximum bipartite matching :

	variations : max flow min cut , ford fulkerson algo 


## nCr with mod :

	calculates  nCr with modulo mod.
	nCr = n! / ((r!)*(n-r)!) 
	 ncr % mod = n! * inverse(r!) * inverse((n-r)!)  % mod

	 inverse(a) = a ^ (mod -2) where mod must be prime. 



## Prime sieve (segmented sieve) :

   Normal sieve upto 10^5 , and to generate prime numbers bigger than that 
   use sam_sieve which is basically segmented sieve. by this,we can generate
   prime numbers upto range 10^9.

   Complexity : O(N)

## Prims Algorithm :

	This algorithm is used to build minimum spanning tree.I used priority
	queue in stl which minimized my work :p.

	complexity : O(V + ElogE)           

##stl-comparator function :

	we are sorting array of structures here :

	priority : lesser value of gold comes first ,
	if 2 groups have same amount of gold, take the one with lesser silver ,
	similarly bronze.

	but if all the three are equal ,
	the string "name" with lexicographically bigger will come first. 	

## Z-algorithm :
	
	A very good technique for pattern searching.
	Z- array contains 	   
	z[i] = maximum substring length from ith index  which is also equal to 
	prefix of the array .

	if we append the pattern at the starting, answer will be equal to all
	indexes whose z[i] is equal to length of the pattern.

	complexity is O(N) 




