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

inline int dist(string x, string y)
{
    int ret=0;
    rep(i,x.size()) if(x[i]!=y[i]) ++ret;
    return ret;
}

int main()
{
    string f,l;
    int n;

    cin >>f >>l;
    cin >>n;

    vector<string> s;
    s.pb(f);
    rep(i,n)
    {
        string t;
        cin >>t;
        s.pb(t);
    }
    s.pb(l);

    n+=2;
    /*
    0   : first
    1~n-2 : words
    n-1 : last
    */

    if(f==l)
    {
        printf("0\n");
        cout << f << endl;
        cout << l << endl;
        return 0;
    }

    vector<int> G[1002];
    rep(i,n)
    {
        rep(j,i)
        {
            if(dist(s[i],s[j])==1)
            {
                G[i].pb(j);
                G[j].pb(i);
            }
        }
    }

    int par[1002];
    int d[1002];
    const int INF=1000000;
    fill(d,d+n,INF);
    fill(par,par+n,-1);

    d[0]=0;
    queue<int> que;
    que.push(0);
    while(!que.empty())
    {
        int v=que.front();
        que.pop();
        rep(i,G[v].size())
        {
            int nx=G[v][i];
            if(d[nx]>d[v]+1)
            {
                d[nx]=d[v]+1;
                par[nx]=v;
                que.push(nx);
            }
        }
    }

    if(d[n-1]==INF) printf("-1\n");
    else
    {

        printf("%d\n", d[n-1]-1);

        vector<string> ans;
        int now=n-1;
        while(par[now]!=0)
        {
            ans.pb(s[par[now]]);
            now=par[now];
        }
        reverse(all(ans));

        cout << f << endl;
        for(const auto &x:ans) cout << x << endl;
        cout << l << endl;
    }

    return 0;
}
