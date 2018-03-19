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
    ll n,k,a,b;
    cin >>n >>k >>a >>b;

    ll ans = 0;
    if(k==1) ans = a*(n-1);
    else{
        while(n>1){
            if(n<k){
                ans += a*(n-1);
                break;
            }

            if(n%k==0){
                ll nx = n/k;
                ans += min(b, a*(n-nx));
                n = nx;
            }
            else{
                ll r = n%k;
                ans += a*r;
                n -= r;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
