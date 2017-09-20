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

const int INF = 19191919;

const int N = 100000;
vector<int> G[N];

int main()
{
    int n;
    cin >>n;
    rep(i,n-1)
    {
        int u,v;
        cin >>u >>v;
        --u;
        --v;
        G[u].pb(v);
        G[v].pb(u);
    }

    vector<int> d(n,INF);
    d[0]=0;
    queue<int> que;
    que.push(0);
    while(!que.empty())
    {
        int v = que.front();
        que.pop();
        for(int e:G[v])
        {
            if(d[e]>d[v]+1)
            {
                d[e] = d[v]+1;
                que.push(e);
            }
        }
    }

    vector<int> g[2];
    rep(i,n) g[d[i]%2].pb(i);

    ll U = (ll)g[0].size()*g[1].size();
    cout << U - (n-1) << endl;
    return 0;
}
