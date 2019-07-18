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

int main(){
    int n,k;
    cin >>n >>k;

    vector<ll> c(k);
    for(int i=1; i<=n; ++i) ++c[i%k];

    ll ans = 0;
    rep(i,k){
        int r = (k-i)%k;
        if(i==r){
            ans += c[i];
            ans += (c[i]*(c[i]-1))*3;
            ans += (c[i]*(c[i]-1)*(c[i]-2))/6*6;
        }
        else{
            if((2*r)%k == 0) ans += c[i]*3*(c[r] + (c[r]*(c[r]-1))/2*2);
        }
    }
    cout << ans << endl;
    return 0;
}
