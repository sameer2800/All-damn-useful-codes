#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

int mark[200010];
vector < pair <ll ,ll > > v[200010];
ll n;

class Compare
{
public:
    bool operator()(pair<ll, ll > n1,pair<ll ,ll > n2) {
        return n1.first > n2.first;
    }
};

priority_queue < pair <ll ,ll> , vector < pair <ll ,ll> >, Compare > pq;


ll prims()
{
	memset(mark,-1,sizeof mark);

	int head = 1;

	pq.push(make_pair(0,head));

	int counter =0;

	ll total_len = 0;

	while(!pq.empty()) {

	//	cout << " length upto nw : " <<  total_len << endl;

		pair <ll , ll > pr =  pq.top();

		pq.pop();

		int yo = pr.second;		

		if(mark[yo] == 1)
			continue;			

		total_len += pr.first;

		mark[yo] = 1;
		counter++;

		if(counter == n)
			break;

		for(int i =0;i < v[yo].size();i++) {
			if(mark[v[yo][i].first] == -1){
				pq.push(make_pair(v[yo][i].second ,v[yo][i].first  ));
			}
		}
	}


	return total_len;

}


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("/home/sameer/sameer/sam.sam","r",stdin);
	#endif


	ios_base::sync_with_stdio(false);
	ll i,j,k,m,t,cont,a,b,c;
	
		
	cin >> n >> m;
	
	for(i = 0; i < m ; i++) {
			cin >> a >> b >> c;
		
			v[a].push_back(make_pair(b,c));
			v[b].push_back(make_pair(a,c));
			
	}

	cout << prims() << endl;  // minimum tree length


	return 0;
}
