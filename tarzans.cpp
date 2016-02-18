#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

vector < ll>  v[1010];
ll discovery[1010], low[1010], stac[1010];
ll n, global_time, set_no;
stack <ll> stk;
set < ll > st[1010];

void tarzan_dfs(int curr)
{
	discovery[curr] = global_time;
	global_time++;
	low[curr] = discovery[curr];
	stac[curr] = 1;
	stk.push(curr);

	for (int i = 0; i < v[curr].size(); i++) {
		if (discovery[v[curr][i]] == -1) {
			tarzan_dfs(v[curr][i]);
			low[curr] = min(low[curr], low[v[curr][i]]);

		} else if (stac[v[curr][i]] == 1 ) {
			low[curr] = min(low[curr], discovery[v[curr][i]]);
		}
	}

	if (discovery[curr] == low[curr]) {
		while (stk.top() != curr) {
			st[set_no].insert(stk.top());
			stac[stk.top()] = 0;
			stk.pop();
		}

		stk.pop();
		stac[curr] = 0;
		st[set_no].insert(curr);
		set_no++;
	}
}


void tarzan()
{
	for (int i = 0; i < 1010; i++)
		st[i].clear();

	global_time = 0;
	set_no = 0;
	memset(discovery, -1, sizeof discovery);
	memset(low, 0, sizeof low);
	memset(stac, 0, sizeof stac);

	for (int i = 0; i <= n; i++) {
		if (discovery[i] == -1) {
			tarzan_dfs(i);
		}
	}

	set < ll >::iterator it;
	ll zindex = 0;

	for (int i = 0; i < set_no; i++) {
		cout << "-----------set no : " << i << endl;

		for (it = st[i].begin(); it != st[i].end(); it++) {
			cout << *it << " ";
		}

		cout << endl;
	}
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("/home/sameer/Documents/sameer/input.sam", "r", stdin);
#endif
	ll i, j, k, m, t, cont, a, b;
	scanf("%lld", &t);
	ll cases = t;

	while (t--) {
		scanf("%lld %lld", &m, &n);

		for (i = 0; i < 1010; i++)
			v[i].clear();

		for (i = 0; i < m; i++) {
			scanf("%lld %lld", &a, &b);
			v[a].push_back(b);
		}

		tarzan();
	}

	return 0;
}