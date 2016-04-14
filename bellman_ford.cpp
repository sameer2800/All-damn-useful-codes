#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

vector <ll> revgraph[1010];

struct edg {
	int src;
	int dest;
	int weight;
};

vector <struct edg > edgo;


int dist[1010];
int mark[1010];
vector <ll> ans;

ll n, m;

void dfs(int src)
{
	if (mark[src] == 1) {
		return;
	}

	mark[src] = 1;
	ans.push_back(src);

	for (int i = 0; i < revgraph[src].size(); i++) {
		if (mark[revgraph[src][i]] != 1)
			dfs(revgraph[src][i]);
	}
}

void bellmanford()
{
	dist[n] = 0;
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < edgo.size(); j++) {
			edg sam = edgo[j];
			int src = sam.src , dest = sam.dest, weight = sam.weight;

			if (dist[src] != INT_MAX and dist[dest] > dist[src] + weight) {
				dist[dest] = dist[src] + weight;
			}
		}
	}

	for (j = 0; j < edgo.size(); j++) {
		edg sam = edgo[j];
		int src = sam.src , dest = sam.dest, weight = sam.weight;

		if (dist[src] != INT_MAX and dist[dest] > dist[src] + weight and mark[src] != 1) {
			dfs(src);
		}
	}
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("/home/sameer/Documents/sameer/input.sam", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	ll i, j, k, t, cont, a, b, c;
	cin >> t;
	ll cases = t;

	while (t--) {
		cin >> n >> m;

		for (i = 0; i < m; i++) {
			cin >> a >> b >> c;
			revgraph[b].push_back(a);
			edg sam;
			sam.src = b;
			sam.dest = a;
			sam.weight = c ;
			edgo.push_back(sam);
		}

		for (i = 0; i < n; i++) {
			revgraph[n].push_back(i);
			edg sam;
			sam.src = n;
			sam.dest = i;
			sam.weight = 0 ;
			edgo.push_back(sam);
			dist[i] = INT_MAX;
		}

		bellmanford();
		cout << "Case " << cases - t  << ": " ;
		sort(ans.begin(), ans.end());

		if (ans.size() == 0)
			cout << "impossible";
		else {
			for (i = 0; i < ans.size() - 1; i++)
				cout << ans[i] << " ";

			cout << ans[i]  ;
		}

		cout << endl;
		ans.clear();
		edgo.clear();

		for (i = 0; i <= n; i++)
			revgraph[i].clear();

		memset(mark, 0, sizeof mark);
	}

	return 0;
}

