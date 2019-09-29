#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

int t[7] = {0,1,2,0,2,1,0};
const ll INF = LLONG_MAX/3;

int main(){
    ll v[3];
    rep(i,3) cin >>v[i];

    ll ans = 0;
    rep(i,7){
        ll ok = 0, ng = INF;
        while(ng-ok>1){
            ll x = (ng+ok)/2;

            ll ct[3]={};
            rep(j,7){
                int idx = (i+j)%7;

                ll add = x/7;
                if(j<x%7) ++add;

                ct[t[idx]] += add;
            }

            bool valid = true;
            rep(j,3)if(ct[j]>v[j]) valid = false;
            if(valid) ok = x;
            else ng = x;
        }

        ans = max(ans, ok);
    }
    cout << ans << "\n";
    return 0;
}
