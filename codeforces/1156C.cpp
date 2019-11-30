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
    int n,z;
    cin >>n >>z;
    vector<int> x(n);
    rep(i,n) cin >>x[i];
    sort(all(x));

    auto check = [&](int k){
        vector<int> p,s;
        rep(i,k){
            p.pb(x[i]);
            s.pb(x[n-1-i]);
        }
        sort(all(p));
        sort(all(s));

        rep(i,k)if(s[i]-p[i]<z) return false;
        return true;
    };

    int ok = 0, ng = n/2+1;
    while(ng-ok>1){
        int mid = (ok+ng)/2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << "\n";
    return 0;
}
