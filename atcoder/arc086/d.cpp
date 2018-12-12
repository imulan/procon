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

using pi = pair<int,int>;

int main(){
    int n;
    cin >>n;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    int idx = 0;
    int d = 0;
    rep(i,n){
        if(abs(a[i]) > d){
            d = abs(a[i]);
            idx = i;
        }
    }

    vector<pi> ans;
    rep(i,n)if(i!=idx) ans.pb({idx,i});

    if(a[idx]>0) rep(i,n-1) ans.pb({i,i+1});
    else for(int i=n-1; i>0; --i) ans.pb({i,i-1});

    cout << ans.size() << endl;
    for(const auto &p:ans) cout << p.fi+1 << " " << p.se+1 << endl;

    // for(const auto &p:ans) a[p.se] += a[p.fi];
    // dbg(a);
    return 0;
}
