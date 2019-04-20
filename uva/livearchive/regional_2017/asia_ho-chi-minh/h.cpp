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
using P = pair<int,pi>;

const int N = 1000000;
vector<pi> Q[N];

int main(){
    int h,w;
    scanf(" %d %d", &h, &w);

    vector<vector<int>> v(h,vector<int>(w));
    vector<int> uv;
    rep(i,h)rep(j,w){
        scanf(" %d", &v[i][j]);
        uv.pb(v[i][j]);
    }

    sort(all(uv));
    uv.erase(unique(all(uv)), uv.end());
    int UV = uv.size();

    rep(i,h)rep(j,w){
        v[i][j] = lower_bound(all(uv), v[i][j]) - uv.begin();
        Q[v[i][j]].pb({i,j});
    }

    vector<int> mh(h,-1), mw(w,-1);
    vector<vector<int>> s(h,vector<int>(w,-1));
    rep(q,UV){
        // dbg(q);
        priority_queue<P> pq;
        unordered_map<int,vector<int>> hh,ww;
        for(const auto &p:Q[q]){
            hh[p.fi].pb(p.se);
            ww[p.se].pb(p.fi);
            int t = max(mh[p.fi], mw[p.se]);
            pq.push({t+1,p});
            // dbg(p);
        }

        while(!pq.empty()){
            P now = pq.top();
            pq.pop();
            // dbg(now);

            int t = now.fi;
            int y = now.se.fi, x = now.se.se;
            if(s[y][x]!=-1) continue;

            s[y][x] = t;
            mh[y] = max(mh[y], t);
            mw[x] = max(mw[x], t);

            queue<pi> que;
            que.push({y,x});
            while(!que.empty()){
                pi cc = que.front();
                que.pop();
                int yy = cc.fi, xx = cc.se;
                int HH = hh[yy].size(), WW = ww[xx].size();

                int idx = lower_bound(all(hh[yy]), xx) - hh[yy].begin();
                for(int i:{-1,1}){
                    int j = idx+i;
                    if(0<=j && j<HH){
                        int nx = hh[yy][j];
                        if(s[yy][nx]==-1){
                            s[yy][nx] = t;
                            que.push({yy,nx});
                            mh[yy] = max(mh[yy], t);
                            mw[nx] = max(mw[nx], t);
                        }
                    }
                }

                idx = lower_bound(all(ww[xx]), yy) - ww[xx].begin();
                for(int i:{-1,1}){
                    int j = idx+i;
                    if(0<=j && j<WW){
                        int ny = ww[xx][j];
                        if(s[ny][xx]==-1){
                            s[ny][xx] = t;
                            que.push({ny,xx});
                            mh[ny] = max(mh[ny], t);
                            mw[xx] = max(mw[xx], t);
                        }
                    }
                }
            }
        }
    }

    // rep(i,h){
    //     rep(j,w) printf(" %d", s[i][j]);
    //     printf("\n");
    // }

    int ans = 0;
    rep(i,h)rep(j,w) ans = max(ans, s[i][j]);
    printf("%d\n", ans+1);
    return 0;
}
