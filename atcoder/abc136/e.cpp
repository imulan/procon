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

vector<int> divisor(int n){
    vector<int> d;
    for(int i=1; i*i<=n; ++i){
        if(n%i==0){
            d.pb(i);
            if(i != n/i) d.pb(n/i);
        }
    }
    sort(all(d), greater<int>());
    return d;
}

int main(){
    int n,k;
    cin >>n >>k;

    int sa = 0;
    vector<int> a(n);
    rep(i,n){
        cin >>a[i];
        sa += a[i];
    }

    for(int d:divisor(sa)){
        int sr = 0;
        vector<int> r(n);
        rep(i,n){
            r[i] = a[i]%d;
            sr += r[i];
        }
        sort(all(r));

        int num = sr/d;
        int ct = 0;
        rep(i,n-num) ct += r[i];

        if(ct<=k){
            cout << d << "\n";
            return 0;
        }
    }
    return 0;
}
