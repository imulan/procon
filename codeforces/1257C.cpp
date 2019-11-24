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

int solve(){
    int n;
    cin >>n;

    map<int,vector<int>> m;
    rep(i,n){
        int a;
        cin >>a;
        m[a].pb(i);
    }

    int ans = n+1;
    for(const auto &e:m){
        vector<int> v(e.se);
        int V = v.size();

        rep(i,V-1) ans = min(ans, v[i+1]-v[i]+1);
    }

    if(ans == n+1) ans = -1;
    return ans;
}

int main(){
    int T;
    cin >>T;
    rep(i,T) cout << solve() << "\n";
    return 0;
}
