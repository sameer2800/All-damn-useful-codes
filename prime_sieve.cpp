#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll arr[500100];
ll sum[100010];

vector <ll> primes;

void sieve()
{
	ll i,j;

	for(i=2; i < 500010;i++){
		if(arr[i] == 0){
			primes.push_back(i);

			for(j = i ; j < 500010;j += i){
				arr[j] = 1;
			}
		}
	}	


}

vector <ll > sol;

ll sieve_sam(ll a ,ll b)
{
	ll i,j,k,flag;

		ll st = a;

		int sieved[200110];


		memset(sieved,-1,sizeof sieved);

		for(i =0;i < primes.size();i++){

			j = a/primes[i];



			if(j < 2)
				j = 2;

			
			while(1) {

				int prod = j*primes[i];
				
				if(prod > b){
					break;
				} 

				if(prod >= a){
					sieved[prod-a] = 1;
					//cout << "yo" << prod << endl;
				}

				j++;
			}


		}

		ll counter = 0;

		for(i= 0;i <= b-a;i++){
			if(sieved[i] == -1)
				cout << i + a << endl; 
		}


		return counter;
}


int main()
{

	std::ios::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("/home/placements2016/input.sam", "r", stdin);
	#endif

	ll i,j,k,m,n,x,t,a,b;

	cin >> t;

	sieve();

	while(t--){
		sol.clear();
		cin >> a >> b;

		ll ans = 0;

		if(b <= 500000){
			vector <ll>::iterator hey = upper_bound(primes.begin(),primes.end(),b);
			vector <ll>::iterator ho = lower_bound(primes.begin(),primes.end(),a);
			
			ans += hey - ho;

			for(ho+1 ;ho!= hey; ho++){
				cout << *ho << endl;	

			}


		}else{

			ans = sieve_sam(a,b);

			


		}
		cout << endl;

	}

	return 0;
}