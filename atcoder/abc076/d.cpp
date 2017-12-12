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

using pi = pair<int,int>;
using P = pair<pi,pi>;

int main()
{
    int n;
    cin >>n;

    vector<int> t(n),v(n);
    rep(i,n) cin >>t[i];
    rep(i,n) cin >>v[i];

    vector<int> st(n);
    st[0] = t[0];
    for(int i=1; i<n; ++i) st[i] = st[i-1]+t[i];

    int T=st[n-1];

    vector<P> cond;
    cond.pb({{1,0},{0,T}});
    cond.pb({{-1,T},{0,T}});

    int pre = 0;
    rep(i,n)
    {
        cond.pb({{0,v[i]},{pre,pre+t[i]}});
        cond.pb({{-1,v[i]+pre},{0,pre}});
        cond.pb({{1,v[i]+pre},{pre+t[i],T}});
        pre += t[i];
    }

    double ans = 0;
    double nv = 0;
    rep(i,2*T)
    {
        double now = 0.5*i;
        double nx = now+0.5;
        // printf("%5.2f: v = %5.2f\n", now,nv);

        double lim = nv+0.5;
        rep(j,cond.size())
        {
            pi para = cond[j].fi;
            pi range = cond[j].se;
            if(range.fi<=now && now<range.se)
            {
                lim = min(lim, para.fi*nx+para.se);
            }
        }

        ans += (nv+lim)/2;
        nv = lim;
    }

    printf("%.10f\n", ans/2);
    return 0;
}
