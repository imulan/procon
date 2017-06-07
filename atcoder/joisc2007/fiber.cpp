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

vector<int> G[10000];

int main()
{
    int n,m;
    scanf(" %d %d", &n, &m);
    rep(i,m)
    {
        int a,b;
        scanf(" %d %d", &a, &b);
        --a;
        --b;
        G[a].pb(b);
        G[b].pb(a);
    }

    vector<bool> vis(n,false);
    int ct=0;
    rep(i,n)
    {
        if(vis[i]) continue;

        ++ct;
        vis[i]=true;
        queue<int> que;
        que.push(i);
        while(!que.empty())
        {
            int v = que.front();
            que.pop();
            for(const auto &x:G[v])
            {
                if(!vis[x])
                {
                    vis[x]=true;
                    que.push(x);
                }
            }
        }
    }
    printf("%d\n", ct-1);
    return 0;
}
