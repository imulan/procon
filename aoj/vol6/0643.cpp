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
    int h,w;
    cin >>h >>w;
    vector<vector<int>> a(h,vector<int>(w));
    rep(i,h)rep(j,w) cin >>a[i][j];

    int ans = 10101010;
    rep(i,h)rep(j,w){
        int tmp = 0;
        rep(y,h)rep(x,w){
            int d = min(abs(i-y), abs(j-x));
            tmp += d*a[y][x];
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
