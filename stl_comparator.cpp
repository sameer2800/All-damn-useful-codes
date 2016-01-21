#include <bits/stdc++.h>

using namespace std;



struct prize {
    int gold;
    int silver;
    int bronze;
};

struct group {
    string name;
    int gold;
    int silver;
    int bronze;
};

map<string, prize> m;

bool compareByLength(group a, group b)
{
    if(a.gold == b.gold) {

        if(a.silver == b.silver) {

            if(a.bronze == b.bronze) {
                return a.name > b.name;
            }

            return a.bronze < b.bronze;
        }

        return a.silver < b.silver;
    }
    return a.gold < b.gold;
}

int main()
{
    int t;

    string a, b, c;

    cin >> t;

    while(t--) {
        cin >> a >> b >> c;

        m[a].gold++;
        m[b].silver++;
        m[c].bronze++;
    }

    vector<group> ans;

    int i = 0;
    for(map<string, prize>::iterator it = m.begin(); it != m.end(); it++, i++) {

        struct group temp;

        temp.name = it->first;
        temp.gold = it->second.gold;
        temp.silver = it->second.silver;
        temp.bronze = it->second.bronze;

        ans.push_back(temp);
    }

    sort(ans.begin(), ans.end(), compareByLength);

    for(int i = ans.size() - 1; i >=0 ; i--) {
        cout << ans[i].name<<" "<<ans[i].gold <<" "<<ans[i].silver<<" "<<ans[i].bronze<<endl;
    }

    return 0;
}