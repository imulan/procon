#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

const int N = 200000;
vector<int> G[N];

int solve()
{
    int n,m,k;
    scanf(" %d %d %d", &n, &m, &k);

    vector<int> q(k),x(k),y(k);
    rep(i,k) scanf(" %d %d %d", &q[i], &x[i], &y[i]);

    int l=0,r=k+1;
    while(r-l>1)
    {
        rep(i,n+m) G[i].clear();

        bool ok = true;
        int mid = (l+r)/2;
        rep(i,mid)
        {
            if(q[i]==1)
            {
                int a=x[i]-1, b=y[i]-1;
                G[a].pb(b);
                G[b].pb(a);
            }
            else
            {
                int a=x[i]-1, club=y[i]-1+n;
                G[a].pb(club);
                G[club].pb(a);
            }
        }

        vector<bool> vis(n+m);
        rep(i,n)if(!vis[i])
        {
            set<int> club;
            vis[i] = true;
            queue<int> que;
            que.push(i);
            while(!que.empty())
            {
                int v = que.front();
                que.pop();
                for(int e:G[v])
                {
                    if(!vis[e])
                    {
                        vis[e]=true;
                        que.push(e);
                        if(e>=n) club.insert(e);
                    }
                }
            }

            if(club.size()>1)
            {
                ok=false;
                break;
            }
        }

        if(ok) l=mid;
        else r=mid;
    }

    if(r==k+1) r=0;
    return r;
}

int main()
{
    printf("%d\n", solve());
    return 0;
}
