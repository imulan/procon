#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(int)n; ++i)
#define all(x) (x).begin() (x).end()
#define fi first
#define se second

const int N=10001;
vector<int> G[N];

int main(){
    int n;
    cin >>n;

    int m = 2*n*n - 2*n;
    vector<int> a(m),b(m);
    map<int,int> ct;
    rep(i,m)
    {
        cin >>a[i] >>b[i];
        ++ct[a[i]];
        ++ct[b[i]];
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }

    vector<vector<int>> ans(n,vector<int>(n));

    for(const auto &p:ct)
    {
        if(p.se==2)
        {
            ans[0][0]=p.fi;
            ct.erase(p.fi);
            break;
        }
    }

    ans[1][0] = G[ans[0][0]][0];
    ans[0][1] = G[ans[0][0]][1];

    ct.erase(ans[1][0]);
    ct.erase(ans[0][1]);

    // yoko
    for(int i=2; i<n; ++i)
    {
        for(const int nx:G[ans[0][i-1]])
        {
            int v = 3;
            if(i==n-1) --v;

            if(ct[nx]==v)
            {
                ans[0][i] = nx;
                ct.erase(nx);
                break;
            }
        }
    }
    // tate
    for(int i=2; i<n; ++i)
    {
        for(const int nx:G[ans[i-1][0]])
        {
            int v = 3;
            if(i==n-1) --v;

            if(ct[nx]==v)
            {
                ans[i][0] = nx;
                ct.erase(nx);
                break;
            }
        }
    }

    for(int i=1; i<n; ++i)for(int j=1; j<n; ++j)
    {
        int v = 4;
        if(i==n-1) --v;
        if(j==n-1) --v;

        for(const auto &p:ct)if(p.se==v)
        {
            bool x = false, y = false;
            for(const int nx:G[p.fi])
            {
                if(nx==ans[i-1][j]) x=true;
                if(nx==ans[i][j-1]) y=true;
            }

            if(x&&y)
            {
                ans[i][j]=p.fi;
                ct.erase(p.fi);
                break;
            }
        }
    }

    rep(i,n)rep(j,n)printf("%d%c", ans[i][j],(j==n-1)?'\n':' ');
    return 0;
}
