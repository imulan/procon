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
    int n;
    cin >>n;
    vector<int> a(n+1);
    rep(i,n) cin >>a[i+1];

    vector<int> e(n+1), o(n+1);
    for(int i=1; i<=n; ++i){
        if(i%2==1) o[i] = a[i];
        else e[i] = a[i];
    }
    rep(i,n){
        e[i+1] += e[i];
        o[i+1] += o[i];
    }

    auto sum = [&](const vector<int> &v, int l, int r){
        return v[r] - v[l];
    };

    int ans = 0;
    for(int i=1; i<=n; ++i){
        int x = sum(o,0,i-1) + sum(e,i,n);
        int y = sum(e,0,i-1) + sum(o,i,n);
        ans += (x==y);
    }
    cout << ans << "\n";
    return 0;
}
