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

int main(){
    int C;
    scanf(" %d", &C);
    while(C--){
        ll n,k;
        scanf(" %lld %lld", &n, &k);

        if(n%2==0) --n;
        ll L = (n+1)/2;

        if(L < k){
            printf("-1\n");
            continue;
        }

        ll ng=0, ok=n;
        while(ok-ng>1){
            ll mid = (ng+ok)/2;

            ll t = n;
            ll ct = 0;

            ll d = 2;
            while(t>0){
                ll nt = t/3;
                if(nt%2==0) --nt;

                ll S = nt+2, E = t;
                if(S>E) S = 1;
                ll num = (E-S)/2 + 1;

                if(mid - S*d/2 >= 0){
                    ll i = (mid - S*d/2)/d;
                    ct += min(num,i+1);
                }

                t = nt;
                d *= 2;
            }

            if(ct >= k) ok = mid;
            else ng = mid;
        }
        printf("%lld\n", ok);
    }
    return 0;
}
