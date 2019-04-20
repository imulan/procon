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

vector<ll> c[2];

int main(){
    int n;
    ll L,W;
    cin >>n >>L >>W;

    rep(i,n){
        ll x;
        int v;
        cin >>x >>v;

        if(v==1) c[0].pb(x);
        else c[1].pb(x);
    }

    rep(i,2) sort(all(c[i]));

    int P = c[0].size(), N = c[1].size();

    ll ans = 0;

    rep(i,P){
        ll x = c[0][i];
        if(x<0){
            ll xj = (W-1)/(W+1) * x - L;
            if( (W-1)%(W+1) == 0) ++xj;

            int idx = lower_bound(all(c[1]), xj) - c[1].begin();
            ans += N-idx;
        }
        else{
            if(W>1){
                ll xj = (W+1)/(W-1) * x - L;
                if( (W+1)%(W-1) == 0) ++xj;
                int lidx = lower_bound(all(c[1]), xj) - c[1].begin();

                xj = ((W+1)*(x+L) + W-2)/(W-1);
                if( (W+1)%(W-1) == 0) ++xj;
                int ridx = lower_bound(all(c[1]), xj) - c[1].begin();

                // printf(" r l %d-%d\n", ridx,lidx);
                ans += ridx-lidx;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
