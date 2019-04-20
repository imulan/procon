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
    ll x;
    cin >>n >>x;

    vector<ll> a(n);
    rep(i,n) cin >>a[i];
    sort(all(a));

    int ok = 1, ng = n+1;
    while(ng-ok>1){
        int mid = (ok+ng)/2;
        ll v = a[mid-1]+a[mid-2];

        if(v>x) ng = mid;
        else ok = mid;
    }
    cout << ok << "\n";
    return 0;
}
