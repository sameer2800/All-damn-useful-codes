#include <bits/stdc++.h>
 #define ll long long
 #define MAX 100100
 
 using namespace std;
 
 string arr[20];
 
ll visited[1 << 20];
 
ll ans = 0;
ll zero,one;
ll cntzero[20],cntone[20],n;
 
void generate_sets(ll curr,ll n)
{
	
	ll cnt = __builtin_popcount(curr);
 
	if(cnt > n)
		return;
 
	
	if(visited[curr])
		return;
 
	visited[curr] = 1;
 
	ll omg = 0;
	ll ze =0, on =0;
	for(int i =0; i < n;i++){
		if( (curr & (1 << i))) {
			ze += cntzero[i];
			on += cntone[i];
			
		}
	}
 
	if(ze <= zero and on <= one)
		ans = max(ans,cnt);
 
	if(omg % 2==0) {
		ans += omg;
	}
 
	for(int i=0;i < n;i++) {
		if(! (curr & (1 << i))) {
			generate_sets(curr | (1 <<i),n);
		}
 
	}
 
	return;
}
 
void store()
{
 
	for(int i =0;i < n;i++){
		for(int j =0;j < arr[i].size();j++){
			if(arr[i][j] == '0')
				cntzero[i]++;
		}
	
		cntone[i] = arr[i].size()- cntzero[i];
 
	}
 
 
 
	
 
 
}
 
int main()
 {
     
 
	#ifndef ONLINE_JUDGE
	freopen("/home/placements2016/input.sam","r",stdin);
	#endif
 
 
     ios_base::sync_with_stdio(false);
     ll i,j,k,m,t,cont,a,b;
   
    
 
 
  	cin >> n;
 
  	for(i=0;i < n;i++){
  		cin >> arr[i];
  	}
 
  	store();
 
  	cin >> zero >> one;
  	generate_sets(0,n);
 
  	cout <<ans << endl;
     return 0;
}