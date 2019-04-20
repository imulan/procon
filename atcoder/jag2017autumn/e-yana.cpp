#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb(x) push_back((x))
#define mp(x) make_pair((x))
#define fi first
#define se second

using P = pair<int,int>;


vector<int> g[100005];

int dp1[100005];
int dp2[100005];

int n,k;

int dfs(int v, int from){
    int sz = 1;
    int kcnt = 0;
    vector<P> v1,v2;
    for (int to : g[v]) if(to != from){
        int r = dfs(to, v);
        v1.push_back(make_pair(dp1[to], r));
        v2.push_back(make_pair(dp2[to], r));
        sz += r;
        if(r>=k) kcnt++;
    }
    sort(all(v1));
    reverse(all(v1));
    sort(all(v2));
    reverse(all(v2));

    dp2[v] = dp1[v] = 0;
    if(v1.size()>0){
        dp1[v] = v1[0].first;
        dp2[v] = kcnt;
        // take 1 dp2
        {
            rep(i,v2.size()){
                int nv = v2[i].first + kcnt;
                if (v2[i].second>= k) nv--;
                dp2[v] = max(dp2[v], nv);
                if(n-sz >= k) nv++;
                dp1[v] = max(dp1[v], nv);
            }
        }
        // take 2 dp2
        if (v2.size()>=2){
            int nv = v2[0].first + v2[1].first;
            rep(i,v2.size()) if(i>1){
                if (v2[i].second>= k) nv++;
            }
            if(n-sz >=k) nv++;
            dp1[v] = max(dp1[v], nv);
        }
    }

    return sz;
}

int main()
{
    cin>>n>>k;
    rep(i,n-1){
        int a,b;
        cin>>a>>b;
        a--;b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    dfs(0, -1);

    // rep(i,n) cout << "**" << i+1 << " " << dp1[i] << " " << dp2[i] << endl;

    cout << dp1[0] << endl;


    return 0;
}
