#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

vector<int> G[5000];

int main()
{
    int n,m;
    cin >>n;

    map<string,int> f;
    vector<int> c(n);

    rep(i,n)
    {
        string a;
        int x;
        cin >>a >>x;
        f[a]=i;
        c[i]=x;
    }

    cin >>m;
    rep(i,m)
    {
        string s,t;
        cin >>s >>t;

        int x=f[s], y=f[t];
        G[x].pb(y);
        G[y].pb(x);
    }

    int ans=0;

    int vis[5000]={0};

    rep(i,n)
    {
        if(vis[i]) continue;

        int tv[5000]={0};

        queue<int> que;
        que.push(i);
        tv[i]=1;
        while(!que.empty())
        {
            int v=que.front();
            que.pop();
            rep(j,G[v].size())
            {
                int nx=G[v][j];
                if(!tv[nx])
                {
                    tv[nx]=1;
                    que.push(nx);
                }
            }
        }

        int add=1234;
        int ct=0;
        rep(j,n)
        {
            if(tv[j])
            {
                add=min(add,c[j]);
                ++ct;
            }
        }
        ans+=add*ct;

        rep(j,n) vis[j]|=tv[j];
    }

    cout << ans << endl;
    return 0;
}
