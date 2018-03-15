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

const int INF = 10101010;

const int E = 1<<4;
const int N = 100;
const int R = 101;

int d[E][N][R];
int event[N];
vector<int> G[E][N];

struct state{
    int mask, pos, day;
};

int main(){
    int n,m,e,s,t,r;
    cin >>n >>m >>e >>s >>t >>r;

    rep(i,m){
        int a,b;
        scanf(" %d %d", &a, &b);
        rep(j,1<<e){
            G[j][a].pb(b);
            G[j][b].pb(a);
        }
    }

    int smask = 0;
    fill(event, event+N, -1);
    rep(i,e){
        int a,b,c;
        scanf(" %d %d %d", &a, &b, &c);
        event[c] = i;
        if(c==s) smask = 1<<i;

        rep(j,1<<e)if(j>>i&1){
            G[j][a].pb(b);
            G[j][b].pb(a);
        }
    }

    rep(i,E)rep(j,N)rep(k,R) d[i][j][k] = INF;
    d[smask][s][0] = 0;
    queue<state> que;
    que.push({smask,s,0});

    while(!que.empty()){
        state c = que.front();
        que.pop();

        int D = d[c.mask][c.pos][c.day];

        // move
        if(c.day<r){
            int nd = c.day+1;
            for(int nx:G[c.mask][c.pos]){
                int nmask = c.mask;
                if(event[nx]!=-1) nmask |= (1<<event[nx]);

                if(d[nmask][nx][nd] > D+1){
                    d[nmask][nx][nd] = D+1;
                    que.push({nmask,nx,nd});
                }
            }
        }

        // ocarina
        if(d[c.mask][s][0] > D+1){
            d[c.mask][s][0] = D+1;
            que.push({c.mask,s,0});
        }
    }

    int ans = INF;
    rep(mask,1<<e)rep(i,r+1) ans = min(ans,d[mask][t][i]);
    if(ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}
