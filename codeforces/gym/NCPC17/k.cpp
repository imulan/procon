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
using P = pair<ll,pi>;

int main(){
    vector<int> n(3);
    rep(i,3) cin >>n[i];

    vector<ll> s(3);
    rep(i,3) cin >>s[i];

    int m = (n[0]+n[1]+n[2])/2;
    vector<ll> c(m);
    rep(i,m) cin >>c[i];
    sort(all(c), greater<ll>());


    vector<P> ss;
    rep(i,3)rep(j,i+1) ss.pb({s[i]+s[j], {i,j}});
    sort(all(ss));

    auto check = [&](ll v){
        int cidx = 0;
        vector<int> rem(n);

        for(P p:ss){
            while(cidx<m){
                bool ok = true;
                for(int idx:{p.se.fi, p.se.se}){
                    --rem[idx];
                    if(rem[idx]<0) ok = false;
                }

                ll tv = c[cidx]*p.fi;
                if(tv<v) ok = false;

                if(!ok){
                    for(int idx:{p.se.fi, p.se.se}) ++rem[idx];
                    break;
                }

                ++cidx;
            }
        }

        return cidx == m;
    };

    ll ok=0, ng=300000000;
    while(ng-ok>1){
        ll mid = (ok+ng)/2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << "\n";
    return 0;
}
