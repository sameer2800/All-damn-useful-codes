#include <bits/stdc++.h>
#define ll long long
#define MAX 100100
#define mod 1000000007 

using namespace std;

ll fact[1000100];
ll ifact[1000100];

ll power(ll a,ll b)
{
	if(b==0)
		return 1;

	if(b==1)
		return a;

	ll half = power(a,b/2);

	if(b % 2 != 0){
		return (((half * half) % mod ) * a) % mod;
	}
	else
		return ((half * half) % mod ) ;
		
}

ll ncr(ll n,ll r)
{
	if(r > n)
		return 0;

	ll numer = fact[n];

	ll denom = ifact[r] * ifact[n-r];
	denom %= mod;

	return (numer*denom) % mod;
	
}

void prefunc()
{

	fact[0] = 1;

	for(int i =1;i < 1000020;i++){ 
		fact[i] = i * fact[i-1];
		fact[i] %= mod;
	}	

	ifact[0] = 1;
	ifact[1] = 1;

	for(int i =2;i < 1000020;i++) {
		ifact[i] = power(i,mod-2) * ifact[i-1];
		ifact[i] %= mod;
	}

}


int main()
{
	
	prefunc();

	cout << ncr(10,3) << endl;


	return 0;
}
