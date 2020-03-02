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
    cin.tie(0); ios::sync_with_stdio(false);

    int n;
    cin >>n;
    vector<ll> a(n),b(n);
    rep(i,n) cin >>a[i];
    rep(i,n) cin >>b[i];

    rep(i,n-1){
        a[i+1] += a[i];
        b[i+1] += b[i];
    }

    int Q;
    cin >>Q;
    while(Q--){
        ll x;
        cin >>x;

        int idx = upper_bound(all(a), x) - a.begin();
        --idx;

        ll v = 0;
        if(idx>=0) v = b[idx];

        string ans = "draw";
        if(v > x) ans = "usagi";
        else if(v < x) ans = "kame";
        cout << ans << "\n";
    }
    return 0;
}
