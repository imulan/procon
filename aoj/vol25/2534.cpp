#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int vis[30];
vector<int> G[30];
bool valid;

void dfs(int now)
{
    if(vis[now]==2)
    {
        valid=false;
        return;
    }
    else if(vis[now]==0)
    {
        vis[now]=2;
        rep(i,G[now].size()) dfs(G[now][i]);

        vis[now]=1;
    }
}

int main()
{
    int n;
    while(cin >>n,n)
    {
        vector<string> s(n);
        rep(i,n) cin >>s[i];

        rep(i,30)
        {
            vis[i]=0;
            G[i].clear();
            valid=true;
        }

        rep(i,n)for(int j=i+1; j<n; ++j)
        {
            int I=s[i].size(), J=s[j].size();
            int S=min(I,J);

            int idx=0;
            while(idx<S)
            {
                if(s[i][idx] != s[j][idx]) break;
                ++idx;
            }

            if(idx<S)
            {
                int from = s[i][idx]-'a', to = s[j][idx]-'a';
                G[from].pb(to);
            }
            else
            {
                if(I>J) valid=false;
            }
        }

        rep(i,30) dfs(i);

        cout << (valid?"yes":"no") << endl;
    }
    return 0;
}
