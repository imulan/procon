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
using P = pair<int,pi>;

int main(){
    int h,w;
    cin >>h >>w;

    auto IN = [&](int y, int x){
        return 0<=y && y<h && 0<=x && x<w;
    };

    vector<vector<int>> a(h,vector<int>(w));
    rep(i,h)rep(j,w) cin >>a[i][j];

    int y,x;
    cin >>y >>x;
    --y;
    --x;

    vector<vector<int>> dp(h,vector<int>(w));
    priority_queue<P, vector<P>, greater<P>> pq;
    dp[y][x] = a[y][x];
    pq.push({dp[y][x],{y,x}});
    while(!pq.empty()){
        P now = pq.top();
        pq.pop();

        int v = now.fi;
        pi p = now.se;
        for(int dy=-1; dy<=1; ++dy)for(int dx=-1; dx<=1; ++dx){
            int ny = p.fi+dy, nx = p.se+dx;
            if(IN(ny,nx) && a[ny][nx]<0){
                int vv = max(a[ny][nx], v);
                if(dp[ny][nx] > vv){
                    dp[ny][nx] = vv;
                    pq.push({vv,{ny,nx}});
                }
            }
        }
    }

    ll ans = 0;
    rep(i,h)rep(j,w) ans += -dp[i][j];
    cout << ans << '\n';
    return 0;
}
