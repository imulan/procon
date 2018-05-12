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
    int n,s,w,q;
    while(cin >>n >>s >>w >>q,n){
        int g = s;
        vector<ll> a(n);
        rep(i,n){
            a[i] = (g/7)%10;
            if(g%2==0) g = (g/2);
            else g = (g/2)^w;
        }

        ll ans = 0;
        if(q==2 || q==5){
            ll non_zero = 0;
            rep(i,n){
                non_zero += (a[i]!=0);
                if(a[i]%q==0){
                    ans += non_zero;
                }
            }
        }
        else{
            vector<ll> pw(n);
            pw[0] = 1;
            for(int i=1; i<n; ++i) pw[i] = (pw[i-1]*10)%q;

            vector<ll> suf(n);
            suf[n-1] = a[n-1]%q;
            for(int i=1; i<n; ++i){
                suf[n-1-i] = (suf[n-i]+pw[i]*a[n-1-i])%q;
            }

            map<ll,int> ct;
            rep(i,n){
                if(a[i]!=0) ++ct[suf[i]];
            }

            for(int i=n-1; i>=0; --i){
                ll sub = 0;
                if(i+1<n) sub = suf[i+1];

                if(ct.count(sub)) ans += ct[sub];
                if(a[i]!=0) --ct[suf[i]];

            }
        }

        cout << ans << endl;
    }
    return 0;
}
