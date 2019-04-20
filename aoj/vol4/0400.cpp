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

const int N = 1010;
const int INF = 19191919;

const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};

int w,h;
string f[N];
int s[10][10];

pi pos[35];

int main(){
    cin >>w >>h;
    rep(i,h) cin >>f[i];
    rep(i,10)rep(j,10) cin >>s[i][j];

    int S = 30, T = 31;
    rep(i,h)rep(j,w){
        if(f[i][j] == 'S') pos[S] = {i,j};
        if(f[i][j] == 'T') pos[T] = {i,j};

        if(isdigit(f[i][j])) pos[f[i][j]-'0'] = {i,j};
        if(isupper(f[i][j])) pos[f[i][j]-'A'+10] = {i,j};
        if(islower(f[i][j])) pos[f[i][j]-'A'+20] = {i,j};
    }

    auto IN = [&](int y, int x){
        return 0<=y && y<h && 0<=x && x<w;
    };

    auto BFS = [&](int s_idx){
        vector<vector<int>> d(h,vector<int>(w,INF));
        d[pos[s_idx].fi][pos[s_idx].se] = 0;
        queue<pi> que;
        que.push(pos[s_idx]);
        while(!que.empty()){
            pi p = que.front();
            que.pop();
            rep(i,4){
                int ny = p.fi+dy[i], nx = p.se+dx[i];
                if(!IN(ny,nx)) continue;
                if(s[ny][nx]=='#' ||  isupper(s[ny][nx]) || islower(s[ny][nx]) ) continue;

                if(d[ny][nx] > d[p.fi][p.se]+1){
                    d[ny][nx] = d[p.fi][p.se]+1;
                    que.push({ny,nx});
                }
            }
        }
        return d;
    };

    return 0;
}
