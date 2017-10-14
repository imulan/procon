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

    vector<int> d(n,19191919),par(n,0);
    vector<double> p(n,0);

    queue<int> que;
    que.push(0);
    d[0]=0;
    p[0]=1;
    while(!que.empty())
    {
        int v = que.front();
        que.pop();

        int nx = 0;
        for(int e:G[v])if(d[e]>d[v]+1) ++nx;

        for(int e:G[v])
        {
            if(d[e]>d[v]+1)
            {
                d[e] = d[v]+1;
                p[e] = p[v]/nx;
                par[e] = v;
                que.push(e);
            }
        }
    }

    vector<bool> leaf(n,true);
    rep(i,n) leaf[par[i]] = false;

    int L = 0;
    rep(i,n)if(leaf[i]) ++L;

    double ans = 0;
    rep(i,n)
    {
        if(leaf[i]) ans += p[i]*d[i];
    }

    printf("%.10f\n", ans);
    return 0;
}
