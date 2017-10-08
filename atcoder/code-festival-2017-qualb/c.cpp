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
const int INF = 19191919;
vector<int> G[N];

ll solve()
{
    int n,m;
    cin >>n >>m;

    vector<int> a(m),b(m);
    rep(i,m)
    {
        cin >>a[i] >>b[i];
        --a[i]; --b[i];
        G[a[i]].pb(b[i]);
        G[b[i]].pb(a[i]);
    }

    vector<int> d(n,INF);
    d[0] = 0;
    queue<int> que;
    que.push(0);
    while(!que.empty())
    {
        int v = que.front();
        que.pop();
        for(int e:G[v])
        {
            if(d[e] > d[v]+1)
            {
                d[e] = d[v]+1;
                que.push(e);
            }
        }
    }

    bool odd_loop = false;
    rep(i,m)
    {
        if(abs(d[a[i]]-d[b[i]])%2==0) odd_loop = true;
    }

    ll U = (ll)n*(n-1)/2;
    if(odd_loop) return U - m;

    ll ct[2]={};
    rep(i,n) ++ct[d[i]%2];
    return ct[0]*ct[1] - m;
}

int main()
{
    cout << solve() << endl;
    return 0;
}
