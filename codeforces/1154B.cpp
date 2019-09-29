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

const int INF = 101010;

int main(){
    int n;
    cin >>n;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    int ans = INF;
    rep(t,111){
        set<int> s;
        rep(i,n){
            int d = abs(a[i]-t);
            if(d>0) s.insert(d);
        }

        if(s.empty()) ans = 0;
        else if(s.size() == 1) ans = min(ans, *s.begin());
    }

    if(ans == INF) ans = -1;
    cout << ans << "\n";
    return 0;
}
