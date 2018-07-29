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

const int INF = 1919191;

int main(){
    int n;
    cin >>n;
    vector<ll> b(n);
    rep(i,n) cin >>b[i];

    int ans = INF;
    if(n<=2) ans = 0;
    else{
        for(int d0=-1; d0<=1; ++d0)for(int d1=-1; d1<=1; ++d1){
            vector<ll> t(b);
            t[0] += d0;
            t[1] += d1;

            ll D = t[1]-t[0];
            int tmp = abs(d0)+abs(d1);
            bool ok = true;
            for(int i=2; i<n; ++i){
                ll x = D-t[i]+t[i-1];
                if(abs(x)<=1){
                    t[i] += x;
                    tmp += abs(x);
                }
                else{
                    ok = false;
                    break;
                }
            }
            if(ok) ans = min(ans, tmp);
        }
    }
    if(ans==INF) ans = -1;
    cout << ans << endl;
    return 0;
}
