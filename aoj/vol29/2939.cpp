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

using vi = vector<int>;
using vvi = vector<vi>;

const int N = 8;

bool IN(int y, int x){
    return 0<=y && y<N && 0<=x && x<N;
}

void dfs(const vvi &f, int t){
    bool end = true;
    rep(i,N)rep(j,N)if(f[i][j]==-1){
        bool ok = false;
        vvi nf(f);
        nf[i][j] = t;
        for(int dy=-1; dy<=1; ++dy)for(int dx=-1; dx<=1; ++dx){
            if(dy==0 && dx==0) continue;

            int cy = i+dy, cx = j+dx;
            if(IN(cy,cx) && nf[cy][cx]==!t){
                while(IN(cy,cx) && nf[cy][cx]==!t){
                    cy += dy;
                    cx += dx;
                }

                if(IN(cy,cx) && nf[cy][cx]==t){
                    cy = i+dy;
                    cx = j+dx;
                    while(IN(cy,cx) && nf[cy][cx]==!t){
                        nf[cy][cx] = t;
                        cy += dy;
                        cx += dx;
                    }
                    ok = true;
                }
            }
        }
        if(ok){
            end = false;
            dfs(nf,!t);
        }
    }

    if(end){
        printf("---------------------\n");
        rep(i,N){
            rep(j,N){
                char c = f[i][j]+'0';
                if(f[i][j]==-1) c = '.';
                printf("%c", c);
            }
            printf("\n");
        }
    }
}

void test(){
    vvi s(N);
    rep(i,N) s[i] = vi(N,-1);
    s[3][3] = 0;
    s[3][4] = 1;
    s[4][4] = 0;

    dfs(s,1);
    dbg("END");
}

int f[N][N]={};
int dp[N][N][N][N];
int solve(int ly, int lx, int ry, int rx){
    if(dp[ly][lx][ry][rx]>=0) return dp[ly][lx][ry][rx];

    int a = 0;
    for(int i=ly; i<=ry; ++i)for(int j=lx; j<=rx; ++j) a += f[i][j];

    return dp[ly][lx][ry][rx] = a;
}

int main(){
    // test();

    rep(i,N)rep(j,N){
        if(i%2==0 && j%2==1) f[i][j] = 0;
        else f[i][j] = 1;
    }

    memset(dp, -1, sizeof(dp));
    int q;
    scanf(" %d", &q);
    while(q--){
        int a,b,c,d;
        scanf(" %d %d %d %d", &a, &b, &c, &d);
        printf("%d\n", solve(a-1, b-1, c-1, d-1));
    }
    return 0;
}
