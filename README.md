#All useful codes 

##2d segment tree :
 	
	As we know 1d segment tree for array queries such as update,range sums etc..
	2d segment tree is used for matrix queries. 

	Queries are of 
	1) update an element
	2) range query like : sum of elements from a to b row and  c to d column   

	complexity of each query is log n * log m. where n= rows and m = columns. 

## Prime sieve (segmented sieve) :

   Normal sieve upto 10^5 , and to generate prime numbers bigger than that 
   use sam_sieve which is basically segmented sieve. by this,we can generate
   prime numbers upto range 10^9.

   Complexity : O(N)

## Prims Algorithm :

	This algorithm is used to build minimum spanning tree.I used priority
	queue in stl which minimized my work :p.

	complexity : O(V + ElogE)           


## Z-algorithm :
	
	A very good technique for pattern searching.
	Z- array contains 	   
	z[i] = maximum substring length from ith index  which is also equal to 
	prefix of the array .

	if we append the pattern at the starting, answer will be equal to all
	indexes whose z[i] is equal to length of the pattern.

	complexity is O(N) 




