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

    vector<int> ct(k);
    rep(i,n){
        int d;
        cin >>d;
        ++ct[d%k];
    }

    int ans = ct[0]/2;
    for(int i=1; i<=k-i; ++i){
        if(i==k-i) ans += ct[i]/2;
        else ans += min(ct[i],ct[k-i]);
    }

    cout << ans*2 << "\n";
    return 0;
}
