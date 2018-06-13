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

const long double INF = 1e10;

using vd = vector<long double>;
using V = vector<vd>;

using pi = pair<int,int>;

const int dy[4]={1,-1,0,0}, dx[4]={0,0,1,-1};

int main(){
    int w,h;
    cin >>w >>h;
    vector<string> s(h);
    rep(i,h) cin >>s[i];

    auto IN = [&](int y, int x){
        return 0<=y && y<h && 0<=x && x<w;
    };

    auto calc = [&](double m){
        V dp(h,vd(w,INF));

        queue<pi> que;
        rep(i,h)rep(j,w){
            if(s[i][j]=='g'){
                dp[i][j]=0;
                que.push({i,j});
            }
            if(s[i][j]=='*'){
                dp[i][j]=m;
                que.push({i,j});
            }
        }

        while(!que.empty()){
            pi pos = que.front();
            que.pop();
            rep(d,4){
                int ny = pos.fi+dy[d], nx = pos.se+dx[d];
                if(IN(ny,nx) && s[ny][nx]!='#' && s[ny][nx]!='*'){
                    if(dp[ny][nx] > dp[pos.fi][pos.se]+1){
                        dp[ny][nx] = dp[pos.fi][pos.se]+1;
                        que.push({ny,nx});
                    }
                }
            }
        }

        return dp;
    };

    long double l=0, r=INF;
    rep(loop,80){
        long double m = (l+r)/2;
        V E = calc(m);

        int n = 0;
        rep(i,h)rep(j,w)if(s[i][j]=='.' || s[i][j]=='s') ++n;

        long double sumE = 0;
        rep(i,h)rep(j,w){
            if(s[i][j]=='.' || s[i][j]=='s') sumE += E[i][j]/n;
        }

        if(sumE<m) r=m;
        else l=m;
    }
    // dbg(l);
    // dbg(r-l);

    V E = calc(l);
    long double ans=-1;
    rep(i,h)rep(j,w)if(s[i][j]=='s') ans = E[i][j];
    printf("%.15Lf\n", ans);
    return 0;
}
