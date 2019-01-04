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

const int N = 50;
const int INF = 19191919;

int main(){
    int a[N][N]={}, b[N][N]={}, c[N][N]={};
    int H,W,h,w;

    cin >>H >>W;
    rep(i,H)rep(j,W) cin >>a[i][j];
    rep(i,H)rep(j,W) cin >>b[i][j];
    cin >>h >>w;
    rep(i,h)rep(j,w) cin >>c[i][j];

    int ans = -INF;
    rep(i,H-h+1)rep(j,W-w+1){
        bool ok = true;
        rep(y,h)rep(x,w)if(b[i+y][j+x] != c[y][x]) ok = false;
        if(!ok) continue;
        int t = 0;
        rep(y,h)rep(x,w) t += a[i+y][j+x];
        ans = max(ans, t);
    }

    if(ans == -INF) cout << "NA" << "\n";
    else cout << ans << "\n";
    return 0;
}
