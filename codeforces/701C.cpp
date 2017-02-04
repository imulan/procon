#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

vector<int> pos[60];

int solve()
{
    int n;
    string s;
    cin >>n >>s;

    vector<int> t(n);
    map<char,int> mp;
    int k=0;
    rep(i,n)
    {
        if(!mp.count(s[i])) mp[s[i]] = k++;
        t[i] = mp[s[i]];
    }

    rep(i,n) pos[t[i]].pb(i);

    int ans = n;

    rep(i,n)
    {
        rep(j,k)
        {
            int SZ = pos[j].size();
            if(pos[j][SZ-1]<i) return ans;
        }

        int max_p = i;
        rep(j,k)
        {
            int idx = lower_bound(all(pos[j]),i)-pos[j].begin();
            max_p = max(max_p,pos[j][idx]);
        }

        ans = min(ans, max_p-i+1);
    }

    return ans;
}

int main()
{
    cout << solve() << endl;
    return 0;
}
