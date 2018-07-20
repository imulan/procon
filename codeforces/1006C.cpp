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
    int n;
    cin >>n;
    vector<ll> d(n);
    rep(i,n) cin >>d[i];

    ll ans = 0;
    ll s1 = 0, s3 = 0;
    int j = n-1;
    rep(i,n){
        s1 += d[i];
        while(j>=0 && s3+d[j]<=s1){
            s3 += d[j];
            --j;
        }

        if(s1==s3 && i<=j) ans = max(ans, s1);
    }
    cout << ans << endl;
    return 0;
}
