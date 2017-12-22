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

const int N = 100010;
const int B = 320;
using pi = pair<int,int>;
using P = pair<pi,int>;

int ans[N];
vector<P> query[N];

int pre[N];

void f(int v, const vector<int> &x)
{
    fill(pre,pre+N,0);
    rep(i,x.size()) ++pre[x[i]];
    rep(i,N-1) pre[i+1] += pre[i];

    rep(t,N)
    {
        for(const auto &q:query[t])
        {
            int l = q.fi.fi, r = q.fi.se;
            int id = q.se;

            l -= v*t;
            r -= v*t;
            l = min(l,N-1);
            r = min(r,N-1);

            int R = 0;
            if(r>=0) R = pre[r];
            int L = 0;
            if(l>0) L = pre[l-1];
            ans[id] += R-L;

        }
    }
}

int main()
{
    int n;
    cin >>n;

    map<int,vector<int>> m;
    rep(i,n)
    {
        int x,v;
        cin >>x >>v;
        m[v].pb(x);
    }

    int Q;
    cin >>Q;
    rep(i,Q)
    {
        int t,l,r;
        cin >>t >>l >>r;
        query[t].pb({{l,r},i});
    }

    vector<pi> fast;
    for(const auto &p:m)
    {
        int v = p.fi;
        if(abs(v)<B) f(v,m[v]);
        else
        {
            for(int x:m[v]) fast.pb({x,v});
        }
    }

    // fast
    int F = fast.size();
    rep(t,B)
    {
        fill(pre,pre+N,0);
        rep(i,F)
        {
            int x = fast[i].fi;
            if(0<=x && x<N) ++pre[x];
        }
        rep(i,N-1) pre[i+1] += pre[i];

        for(const auto &q:query[t])
        {
            int l = q.fi.fi, r = q.fi.se;
            int id = q.se;

            int R = pre[r];
            int L = 0;
            if(l>0) L = pre[l-1];
            ans[id] += R-L;
        }

        rep(i,F) fast[i].fi += fast[i].se;
    }

    rep(i,Q) cout << ans[i] << endl;
    return 0;
}
