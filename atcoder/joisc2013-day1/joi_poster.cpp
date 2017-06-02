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

inline ll SQ(ll x){return x*x;}

int main()
{
    int n,w,h;
    cin >>n >>w >>h;
    vector<ll> x(n),y(n);
    rep(i,n) cin >>x[i] >>y[i];

    int ans=0;
    rep(a,n)rep(b,n)rep(c,n)rep(d,n)
    {
        if(a==b || a==c || a==d || b==c || b==d || c==d) continue;

        ll sq_R1 = SQ(x[a]-x[b]) + SQ(y[a]-y[b]);
        ll sq_R2 = SQ(x[c]-x[d]) + SQ(y[c]-y[d]);

        // 円がはみ出ていないかチェック
        if(sq_R1>SQ(x[a])) continue;
        if(sq_R1>SQ(w-x[a])) continue;
        if(sq_R1>SQ(y[a])) continue;
        if(sq_R1>SQ(h-y[a])) continue;
        if(sq_R2>SQ(x[c])) continue;
        if(sq_R2>SQ(w-x[c])) continue;
        if(sq_R2>SQ(y[c])) continue;
        if(sq_R2>SQ(h-y[c])) continue;

        if(sq_R1<=sq_R2) continue;

        ll sq_d = SQ(x[a]-x[c]) + SQ(y[a]-y[c]);
        ll r=sq_R1+sq_R2-sq_d;
        if(r<0) continue;

        if(4*sq_R1*sq_R2 < SQ(r)) ++ans;
    }
    cout << ans << endl;
    return 0;
}
