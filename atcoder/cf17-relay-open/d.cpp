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

const int N = 100000;
vector<int> G[N];

int n,m;

int bfs(int s)
{
    vector<bool> vis(n);
    queue<int> que;
    que.push(s);
    vis[s] = true;

    int ret = 1;
    while(!que.empty())
    {
        int v = que.front();
        que.pop();
        for(int e:G[v])
        {
            if(!vis[e])
            {
                ++ret;
                vis[e] = true;
                que.push(e);
            }
        }
    }
    return ret;
}

ll f(ll x)
{
    return x*(x-1)/2;
}

int main()
{
    cin >>n >>m;
    rep(i,m)
    {
        int a,b;
        cin >>a >>b;
        --a;
        --b;
        G[a].pb(b);
        G[b].pb(a);
    }

    int X = bfs(0), Y = bfs(1);
    int Z = n-X-Y;

    ll U = f(X)+f(Y)+f(Z)+max(X,Y)*Z-m;
    cout << U << endl;
    return 0;
}
