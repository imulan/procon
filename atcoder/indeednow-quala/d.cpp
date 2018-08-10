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
using vi = vector<int>;
using mat = vector<vi>;

const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};

int h,w;

inline bool IN(int y, int x){
    return 0<=y && y<h && 0<=x && x<w;
}

map<mat,int> dp;

int ans = 24;
mat now;
pi pos;
void dfs(int d){
    if(dp.count(now)) ans = min(ans, d+dp[now]);
    if(d==12) return;

    pi def = pos;
    rep(i,4){
        int ny = pos.fi+dy[i], nx = pos.se+dx[i];
        if(IN(ny,nx)){
            swap(now[ny][nx], now[pos.fi][pos.se]);
            pos = {ny,nx};
            dfs(d+1);
            pos = def;
            swap(now[ny][nx], now[pos.fi][pos.se]);
        }
    }
}

int main(){
    cin >>h >>w;

    mat s(h,vi(w));
    rep(i,h)rep(j,w) cin >>s[i][j];
    pi spos;
    rep(i,h)rep(j,w)if(s[i][j]==0) spos = {i,j};

    using state = pair<mat,pi>;
    queue<state> que;
    dp[s] = 0;
    que.push({s,spos});
    while(!que.empty()){
        state cur = que.front();
        que.pop();

        mat c = cur.fi;
        pi cpos = cur.se;

        int D = dp[c];
        if(D==11) continue;

        rep(i,4){
            int ny = cpos.fi+dy[i], nx = cpos.se+dx[i];
            if(IN(ny,nx)){
                swap(c[ny][nx], c[cpos.fi][cpos.se]);
                if(!dp.count(c)){
                    dp[c] = D+1;
                    que.push({c, {ny,nx}});
                }
                swap(c[ny][nx], c[cpos.fi][cpos.se]);
            }
        }
    }

    now = mat(h,vi(w));
    rep(i,h)rep(j,w) now[i][j] = i*w+j+1;
    now[h-1][w-1] = 0;
    pos = {h-1,w-1};

    dfs(0);

    cout << ans << endl;
    return 0;
}
