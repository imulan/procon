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
using P = pair<char,pi>;

const int dx[8]={1,1,0,-1,-1,-1,0,1};
const int dy[8]={0,-1,-1,-1,0,1,1,1};

// knight direction
const int kx[8]={2,1,-1,-2,-2,-1,1,2};
const int ky[8]={-1,-2,-2,-1,1,2,2,1};

pi king[2];

inline void print_P(const vector<P> &ppp){
    int A = ppp.size();
    assert(A<4);
    printf("%d\n", A);
    rep(i,A) printf("%c %d %d\n", ppp[i].fi, ppp[i].se.fi, ppp[i].se.se);
}

char f[10][10];
vector<P> ans,now;

inline bool IN(int x, int y){
    return 0<=x && x<8 && 0<=y && y<8;
}

inline bool check(const vector<P> &ppp){
    char ch[10][10];
    int ef[10][10];

    // not move
    rep(i,8)rep(j,8) ch[i][j] = f[i][j];
    memset(ef, 0, sizeof(ef));
    for(const auto &b:ppp){
        char c = b.fi;
        pi pos = b.se;
        ch[pos.fi][pos.se] = c;
    }

    for(const auto &b:ppp){
        pi pos = b.se;
        char c = ch[pos.fi][pos.se];

        if(c=='Q'){
            rep(d,8){
                for(int t=1; t<=8; ++t){
                    int ny = pos.fi+t*dy[d], nx = pos.se+t*dx[d];
                    if(!IN(ny,nx)) break;
                    ++ef[ny][nx];
                    if(ch[ny][nx]!='.') break;
                }
            }
        }
        else if(c=='N'){
            rep(d,8){
                int ny = pos.fi+ky[d], nx = pos.se+kx[d];
                if(IN(ny,nx)) ++ef[ny][nx];
            }
        }
    }
    rep(i,2)if(ef[king[i].fi][king[i].se]==0) return false;

    // move one king
    rep(kid,2)rep(kd,8){
        rep(i,8)rep(j,8) ch[i][j] = f[i][j];
        memset(ef, 0, sizeof(ef));
        for(const auto &b:ppp){
            char c = b.fi;
            pi pos = b.se;
            ch[pos.fi][pos.se] = c;
        }

        pi tk[2];
        rep(i,2) tk[i]=king[i];

        tk[kid].fi += dy[kd];
        tk[kid].se += dx[kd];
        if(!IN(tk[kid].fi, tk[kid].se)) continue;
        if(ch[tk[kid].fi][tk[kid].se]=='K') continue;

        ch[tk[kid].fi][tk[kid].se] = 'K';
        ch[king[kid].fi][king[kid].se] = '.';

        // printf("--FIELD\n");
        // rep(i,8){
        //     rep(j,8) printf("%c",ch[i][j]);
        //     printf("\n");
        // }

        for(const auto &b:ppp){
            pi pos = b.se;
            char c = ch[pos.fi][pos.se];

            if(c=='Q'){
                rep(d,8){
                    for(int t=1; t<=8; ++t){
                        int ny = pos.fi+t*dy[d], nx = pos.se+t*dx[d];
                        if(!IN(ny,nx)) break;
                        ++ef[ny][nx];
                        if(ch[ny][nx]!='.') break;
                    }
                }
            }
            else if(c=='N'){
                rep(d,8){
                    int ny = pos.fi+ky[d], nx = pos.se+kx[d];
                    if(IN(ny,nx)) ++ef[ny][nx];
                }
            }
        }

        // printf("--EFFECT\n");
        // rep(i,8){
        //     rep(j,8) printf("%d",ef[i][j]);
        //     printf("\n");
        // }
        rep(i,2)if(ef[tk[i].fi][tk[i].se]==0) return false;
    }
    return true;
}

const string PIECE = "QN";
inline void dfs(int dep){
    if(check(now)){
        ans = now;
    }
    if(dep+1 >= ans.size()) return;

    rep(i,8)rep(j,8)if(f[i][j]=='.'){
        rep(k,2){
            char c = PIECE[k];

            f[i][j] = c;
            now.pb({c,{i,j}});
            dfs(dep+1);
            f[i][j] = '.';
            now.pop_back();
        }
    }
}

inline void solve(){
    // initialize
    rep(i,8)rep(j,8) f[i][j] = '.';
    ans.clear();
    now.clear();

    // input
    rep(i,2){
        scanf(" %d %d", &king[i].fi, &king[i].se);
        f[king[i].fi][king[i].se] = 'K';
    }

    // set default at most 4 queens
    set<pi> def_queens;
    rep(i,2){
        rep(j,8){
            bool ok = true;
            rep(k,2){
                int d = (j+k)%8;
                int ny = king[i].fi+dy[d], nx = king[i].se+dx[d];
                ok &= (IN(nx,ny) && f[ny][nx]=='.');
            }
            if(!ok) continue;

            rep(k,2){
                int d = (j+k)%8;
                int ny = king[i].fi+dy[d], nx = king[i].se+dx[d];
                def_queens.insert({ny,nx});
            }
            break;
        }
    }
    for(const auto &qq:def_queens) ans.pb({'Q',qq});
    ans.resize(5);
    // assert(check(ans));
    dfs(0);
    print_P(ans);
}

int main(){
    int q;
    scanf(" %d", &q);
    while(q--) solve();
    return 0;
}
