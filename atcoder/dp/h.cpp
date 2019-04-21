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

const int mod = 1000000007;
const int dx[2]={1,0}, dy[2]={0,1};

int main(){
    int h,w;
    cin >>h >>w;
    vector<string> a(h);
    rep(i,h) cin >>a[i];

    auto IN = [&](int y, int x){
        return 0<=y && y<h && 0<=x && x<w;
    };

    vector<vector<int>> dp(h,vector<int>(w));
    dp[0][0] = 1;
    rep(i,h)rep(j,w){
        rep(d,2){
            int ny = i+dy[d], nx = j+dx[d];
            if(IN(ny,nx) && a[ny][nx]=='.') (dp[ny][nx] += dp[i][j]) %= mod;
        }
    }
    cout << dp[h-1][w-1] << "\n";
    return 0;
}
