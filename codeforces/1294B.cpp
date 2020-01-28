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

using pi = pair<int,int>;

void solve(){
    int n;
    cin >>n;
    vector<pi> p(n);
    rep(i,n){
        int x,y;
        cin >>x >>y;
        p[i] = {y,x};
    }

    sort(all(p));
    string ans = "";

    int x = 0, y = 0;
    for(const auto &a:p){
        if(a.fi < y || a.se < x){
            cout << "NO\n";
            return;
        }

        while(x < a.se){
            ++x;
            ans += 'R';
        }
        while(y < a.fi){
            ++y;
            ans += 'U';
        }
    }

    cout << "YES\n" << ans << "\n";
}

int main(){
    int t;
    cin >>t;
    while(t--) solve();
    return 0;
}
