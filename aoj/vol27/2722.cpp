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

const int N = 200;
int D[N][N], V[N][N];

double max_r[N];

const int P = 1010;
double dp[N][P][2];

int main(){
    memset(D,-1,sizeof(D));
    memset(V,-1,sizeof(V));

    int n,m,p;
    scanf(" %d %d %d", &n, &m, &p);

    rep(i,m){
        int s,t,d,v;
        scanf(" %d %d %d %d", &s, &t, &d, &v);
        --s;
        --t;

        D[s][t] = D[t][s] = d;
        V[s][t] = V[t][s] = v;
    }

    rep(i,n){
        rep(j,n)if(D[i][j]!=-1){
            max_r[i] = max(max_r[i], (double)V[i][j]/D[i][j]);
        }
    }

    rep(i,N)rep(j,P)rep(k,2) dp[i][j][k] = -123456789;
    dp[0][0][0] = 0;
    rep(t,p+1){
        rep(v,n){
            rep(f,2){
                // 移動
                rep(nx,n)if(D[v][nx]!=-1){
                    int nt = t+D[v][nx];
                    if(nt<=p) dp[nx][nt][f] = max(dp[nx][nt][f], dp[v][t][f]+V[v][nx]);
                }
            }

            // うろうろ
            rep(a,p+1){
                int nt = t+a;
                if(nt>p) break;
                dp[v][nt][1] = max(dp[v][nt][1], dp[v][t][0]+max_r[v]*a);
            }
        }
    }

    printf("%.10f\n", dp[0][p][1]);
    return 0;
}
