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
    vector<int> v(3);
    rep(i,3) scanf(" %d", &v[i]);

    int ans = 0;
    rep(mask,1<<7){
        vector<int> x(v);
        rep(i,7)if(mask>>i&1){
            rep(j,3)if((i+1)>>j&1) --x[j];
        }

        bool ok = true;
        rep(i,3)if(x[i]<0) ok = false;
        if(ok) ans = max(ans, __builtin_popcount(mask));
    }
    return ans;
}

int main(){
    int t;
    scanf(" %d", &t);
    while(t--) printf("%d\n", solve());
    return 0;
}
