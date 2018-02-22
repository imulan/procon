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

const ll mod = 1e9+7;

ll cnt[32][2][2][2], dp[32][2][2][2];

ll f(int X, int Y, int K){
    if(X<0 || Y<0 || K<0) return 0;
    memset(cnt,0,sizeof(cnt));
    memset(dp,0,sizeof(dp));

    int xx[32]={},yy[32]={},kk[32]={};
    rep(i,31){
        xx[i] = (X>>(30-i))&1;
        yy[i] = (Y>>(30-i))&1;
        kk[i] = (K>>(30-i))&1;
    }

    cnt[0][0][0][0] = 1;

    // 状態(i,a,b,c)に対して
    rep(i,31)rep(a,2)rep(b,2)rep(c,2){

        // X側はxを、Y側はyを選ぶ
        rep(x,2)rep(y,2){
            int k = x^y;
            if(a==0 && xx[i]<x) continue;
            if(b==0 && yy[i]<y) continue;
            if(c==0 && kk[i]<k) continue;

            int na = a|(x<xx[i]), nb = b|(y<yy[i]), nc = c|(k<kk[i]);
            (cnt[i+1][na][nb][nc] += cnt[i][a][b][c]) %= mod;
            (dp[i+1][na][nb][nc] += dp[i][a][b][c]) %= mod;
            (dp[i+1][na][nb][nc] += (k<<(30-i))*cnt[i][a][b][c]) %= mod;
        }
    }

    ll ret = 0;
    rep(i,2)rep(j,2)rep(k,2){
        ret += dp[31][i][j][k];
        ret += cnt[31][i][j][k];
        ret %= mod;
    }
    return ret;
}

int main(){
    int Q;
    scanf(" %d", &Q);
    while(Q--){
        int x1,y1,x2,y2,k;
        scanf(" %d %d %d %d %d", &x1, &y1, &x2, &y2, &k);
        --x1; --y1; --x2; --y2; --k;

        ll ans = (f(x2,y2,k) - f(x2,y1-1,k) - f(x1-1,y2,k) + f(x1-1,y1-1,k) + 2*mod) % mod;
        printf("%lld\n", ans);
    }
    return 0;
}
