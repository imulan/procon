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

const int N = 10;
const int INF = 19191919;

int w,h;

int p[N][N];
int sq[N][N];
int need[N][N];
int ct[N][N];

bool can_place(int y, int x, int sz){
    for(int i=y; i<y+sz; ++i)for(int j=x; j<x+sz; ++j)if(!p[i][j]) return false;
    return true;
}

int check_need(int y, int x){
    int LY = y, RY = y+sq[y][x];
    int LX = x, RX = x+sq[y][x];
    rep(i,h)rep(j,w){
        if(i==y && j==x) continue;
        int ly = i, ry = i+sq[i][j];
        int lx = j, rx = j+sq[i][j];
        if(ly<=LY && RY<=ry && lx<=LX && RX<=rx) return 0;
    }
    return 1;
}

int ans;
int now;
bool ret;
void dfs(int y, int x){
    if(y==h-1 && x==w-1){
        rep(i,h)rep(j,w){
            if(p[i][j]){
                if(!ct[i][j]) return;
            }
            else{
                if(ct[i][j]) return;
            }
        }
        ret = true;
        return;
    }

    int ny = y, nx = x+1;
    if(nx==w){
        ++ny;
        nx = 0;
    }

    if(!need[y][x]) dfs(ny,nx);
    else{
        if(!ct[y][x]){
            for(int i=y; i<y+sq[y][x]; ++i)for(int j=x; j<x+sq[y][x]; ++j) ++ct[i][j];
            if(now<ans){
                ++now;
                dfs(ny,nx);
                --now;
            }
            for(int i=y; i<y+sq[y][x]; ++i)for(int j=x; j<x+sq[y][x]; ++j) --ct[i][j];
        }
        else{
            dfs(ny,nx);
            if(ret) return;

            // bool worth = false;
            // for(int i=y; i<y+sq[y][x]; ++i)for(int j=x; j<x+sq[y][x]; ++j){
            //     if(ct[i][j]==0) worth = true;
            // }

            for(int i=y; i<y+sq[y][x]; ++i)for(int j=x; j<x+sq[y][x]; ++j) ++ct[i][j];
            if(now<ans){
                ++now;
                dfs(ny,nx);
                --now;
            }
            for(int i=y; i<y+sq[y][x]; ++i)for(int j=x; j<x+sq[y][x]; ++j) --ct[i][j];
        }
    }
}

int main(){
    while(scanf(" %d %d", &w, &h),w){
        rep(i,h)rep(j,w) scanf(" %d", &p[i][j]);

        memset(sq,0,sizeof(sq));
        rep(i,h)rep(j,w)if(p[i][j]){
            for(int k=min(w-j,h-i); k>=1; --k){
                if(can_place(i,j,k)){
                    sq[i][j] = k;
                    break;
                }
            }
        }

        memset(need,0,sizeof(need));
        rep(i,h)rep(j,w)if(p[i][j]){
            need[i][j] = check_need(i,j);
        }

        memset(ct,0,sizeof(ct));
        int must = 0;
        vector<pair<int,int>> ppp;
        rep(i,h)rep(j,w){
            if(!need[i][j]) continue;

            bool flg = false;
            for(int y=i; y<i+sq[i][j]; ++y)for(int x=j; x<j+sq[i][j]; ++x){
                int covered = 0;
                rep(li,h)rep(lj,w){
                    if(!need[li][lj]) continue;

                    if(li<=y && y<li+sq[li][lj] && lj<=x && x<lj+sq[li][lj]) ++covered;
                }
                if(covered == 1){
                    flg = true;
                    break;
                }
            }

            if(flg){
                ppp.pb({i,j});
                ++must;
                for(int y=i; y<i+sq[i][j]; ++y)for(int x=j; x<j+sq[i][j]; ++x) ++ct[y][x];
            }
        }
        for(const auto &pp:ppp) need[pp.fi][pp.se] = 0;

        // rep(i,h){
        //     rep(j,w) printf(" %d", need[i][j]);
        //     puts("");
        // }

        ans = must;
        while(1){
            // dbg(ans);
            ret = false;
            now = must;
            dfs(0,0);
            if(ret) break;
            ++ans;
        }
        printf("%d\n",ans);
    }
    return 0;
}
