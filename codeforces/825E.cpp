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

const int N=100000;
vector<int> G[N];

int main()
{
    int n,m;
    scanf(" %d %d", &n, &m);

    vector<int> out(n);
    rep(i,m)
    {
        int v,u;
        scanf(" %d %d", &v, &u);
        --v;
        --u;
        G[u].pb(v);
        ++out[v];
    }

    priority_queue<int> pq;
    rep(i,n)if(out[i]==0) pq.push(i);

    vector<int> ans(n);
    rep(i,n)
    {
        int v = pq.top(); pq.pop();
        ans[v] = n-i;
        for(auto nx:G[v])
        {
            --out[nx];
            if(out[nx]==0) pq.push(nx);
        }
    }

    rep(i,n) printf("%d%c", ans[i], (i==n-1?'\n':' '));
    return 0;
}
