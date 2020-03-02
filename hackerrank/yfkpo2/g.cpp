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

using vi = vector<int>;

int main(){
    cin.tie(0); ios::sync_with_stdio(false);

    int h,w;
    cin >>h >>w;

    vector<vi> v(h,vi(w));
    rep(i,h)rep(j,w) cin >>v[i][j];

    vector<vi> s(h+1,vi(w+1));
    int q;
    cin >>q;
    rep(loop,2*q){
        int lh,rh,lc,rc;
        cin >>lh >>rh >>lc >>rc;
        --lh;
        --lc;

        ++s[lh][lc];
        --s[lh][rc];
        --s[rh][lc];
        ++s[rh][rc];
    }

    rep(i,h){
        rep(j,w) s[i][j+1] += s[i][j];
    }
    rep(i,w){
        rep(j,h) s[j+1][i] += s[j][i];
    }

    int ans = 0;
    rep(i,h)rep(j,w) ans += v[i][j]*(s[i][j]%2);
    cout << ans << "\n";
    return 0;
}
