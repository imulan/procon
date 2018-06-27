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
using P = pair<ll,int>;

struct edge{
    int to;
    ll cost;
};

const int dx[4]={1,0,-1,0}, dy[4]={0,-1,0,1};
const int sy[4][2] = {{0,1}, {-1,-1}, {0,1}, {2,2}};
const int sx[4][2] = {{2,2}, {0,1}, {-1,-1}, {0,1}};

const int N = 10010;
const ll INF = LLONG_MAX/3;

vector<edge> G[N];
ll d[N];

int main(){
    int H,W;
    while(cin >>H >>W,H){
        vector<string> s(H);
        rep(i,H) cin >>s[i];

        auto ID = [&](int y, int x, int dir){
            return 4*(W*y+x) + dir;
        };

        auto IN = [&](int y, int x){
            return 0<=y && y<H && 0<=x && x<W;
        };

        auto king_can_place = [&](int ly, int lx){
            bool ret = false;
            if(0<=ly && ly<H-1 && 0<=lx && lx<W-1){
                ret = true;
                rep(i,2)rep(j,2) ret &= (s[ly+i][lx+j]!='*');
            }
            return ret;
        };

        rep(i,N) G[i].clear();
        int src = 10000, dst = src+1;

        // make graph
        rep(ly,H-1)rep(lx,W-1){
            if(!king_can_place(ly,lx)) continue;

            vector<string> f(s);
            rep(i,H)rep(j,W)if(f[i][j]!='*') f[i][j] = '.';
            rep(i,2)rep(j,2) f[ly+i][lx+j] = 'X';

            rep(dir,4){
                pi br[2];
                bool ok = true;
                rep(i,2){
                    int yy = ly+sy[dir][i], xx = lx+sx[dir][i];
                    if(!IN(yy,xx) || f[yy][xx]!='.') ok = false;
                    br[i] = {yy,xx};
                }
                if(!ok) continue;

                int nx = lx+dx[dir], ny = ly+dy[dir];

                if(king_can_place(ny,nx)){
                    int u = ID(ly,lx,dir), v = ID(ny,nx,dir^2);
                    G[u].pb({v,1});
                    G[v].pb({u,1});
                }

                vector<vector<ll>> dist[2];
                rep(i,2){
                    vector<vector<ll>> td(H,vector<ll>(W,INF));
                    queue<pi> que;

                    td[br[i].fi][br[i].se] = 0;
                    que.push(br[i]);
                    while(!que.empty()){
                        pi pos = que.front();
                        que.pop();
                        rep(dd,4){
                            int yy = pos.fi+dy[dd], xx = pos.se+dx[dd];
                            if(IN(yy,xx) && f[yy][xx]=='.' && td[yy][xx] > td[pos.fi][pos.se]+1){
                                td[yy][xx] = td[pos.fi][pos.se]+1;
                                que.push({yy,xx});
                            }
                        }
                    }

                    dist[i] = td;
                }


                rep(ndir,4)if(dir != ndir){
                    pi nbr[2];
                    bool nok = true;
                    rep(i,2){
                        int yy = ly+sy[ndir][i], xx = lx+sx[ndir][i];
                        if(!IN(yy,xx) || f[yy][xx]!='.') nok = false;
                        nbr[i] = {yy,xx};
                    }
                    if(!nok) continue;

                    ll COST = INF;
                    rep(i,2) COST = min(COST, dist[i][nbr[0].fi][nbr[0].se]+dist[!i][nbr[1].fi][nbr[1].se]);
                    if(COST<INF){
                        int u = ID(ly,lx,dir), v = ID(ly,lx,ndir);
                        G[u].pb({v,COST});
                    }
                }
            }
        }

        // make edge from src
        vector<pi> start_br;
        rep(i,H)rep(j,W){
            if(s[i][j]=='.') start_br.pb({i,j});
        }
        assert(start_br.size() == 2);

        pi king;
        for(int i=H-1; i>=0; --i)for(int j=W-1; j>=0; --j){
            if(s[i][j]=='X') king = {i,j};
        }
        if(king == pi(0,0)) G[src].pb({dst,0});

        vector<string> f(s);
        rep(i,H)rep(j,W)if(f[i][j]!='*') f[i][j] = '.';
        rep(i,2)rep(j,2) f[king.fi+i][king.se+j] = 'X';

        vector<vector<ll>> dist[2];
        rep(i,2){
            vector<vector<ll>> td(H,vector<ll>(W,INF));
            queue<pi> que;

            td[start_br[i].fi][start_br[i].se] = 0;
            que.push(start_br[i]);
            while(!que.empty()){
                pi pos = que.front();
                que.pop();
                rep(dd,4){
                    int yy = pos.fi+dy[dd], xx = pos.se+dx[dd];
                    if(IN(yy,xx) && f[yy][xx]=='.' && td[yy][xx] > td[pos.fi][pos.se]+1){
                        td[yy][xx] = td[pos.fi][pos.se]+1;
                        que.push({yy,xx});
                    }
                }
            }

            dist[i] = td;
        }

        rep(ndir,4){
            pi nbr[2];
            bool nok = true;
            rep(i,2){
                int yy = king.fi+sy[ndir][i], xx = king.se+sx[ndir][i];
                if(!IN(yy,xx) || f[yy][xx]!='.') nok = false;
                nbr[i] = {yy,xx};
            }
            if(!nok) continue;

            ll COST = INF;
            rep(i,2) COST = min(COST, dist[i][nbr[0].fi][nbr[0].se]+dist[!i][nbr[1].fi][nbr[1].se]);
            if(COST<INF){
                int v = ID(king.fi,king.se,ndir);
                // printf("src -> %d %lld\n",v,COST);
                G[src].pb({v,COST});
            }
        }

        // make edge to dst
        rep(dir,4){
            bool ok = true;
            rep(i,2){
                int yy = 0+sy[dir][i], xx = 0+sx[dir][i];
                if(!IN(yy,xx) || s[yy][xx]=='*') ok = false;
            }
            if(!ok) continue;

            // printf(" %d -> dst\n",ID(0,0,dir));
            G[ID(0,0,dir)].pb({dst,0});
        }


        // dijkstra
        fill(d,d+N,INF);
        priority_queue<P, vector<P>, greater<P>> pq;
        d[src] = 0;
        pq.push({0,src});
        while(!pq.empty()){
            P now = pq.top();
            pq.pop();
            int v = now.se;
            // printf(" %lld , %d\n",d[v],v);

            if(now.fi>d[v]) continue;

            for(const auto &e:G[v]){
                if(d[e.to] > d[v]+e.cost){
                    d[e.to] = d[v]+e.cost;
                    pq.push({d[e.to],e.to});
                }
            }
        }

        ll ans = d[dst];
        if(ans == INF) ans = -1;
        cout << ans << endl;
    }
    return 0;
}
