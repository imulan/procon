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

int main()
{
    ll Q,H,S,D,N;
    cin >>Q >>H >>S >>D >>N;

    ll ans = 0;

    // 2L以下になるまで一番安い方法で買う
    ll num = N/2;
    ll p = min({D,S*2,H*4,Q*8});

    ans += p*num;
    N -= 2*num;

    // 2L以下の買い方を全探索
    ll t = LLONG_MAX;
    rep(i,9)rep(j,9)rep(k,9)rep(l,9)
    {
        ll ml = 250*i + 500*j + 1000*k + 2000*l;
        if(ml == 1000*N) t = min(t, i*Q+j*H+k*S+l*D);
    }
    ans += t;

    cout << ans << endl;
    return 0;
}
