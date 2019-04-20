#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

struct UF{
    int n;
    vector<int> d;
    UF(){}
    UF(int N):n(N), d(N,-1){}
    int root(int v){
        if(d[v]<0) return v;
        return d[v] = root(d[v]);
    }
    bool unite(int X, int Y){
        X = root(X);
        Y = root(Y);
        if(X==Y) return false;
        if(size(X) < size(Y)) swap(X,Y);
        d[X] += d[Y];
        d[Y] = X;
        return true;
    }
    int size(int v){ return -d[root(v)]; }
    bool same(int X, int Y){ return root(X)==root(Y); }
};

const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};

using pi = pair<int,int>;

pi READ(){
    int y,x;
    scanf(" %d %d", &y, &x);
    return {y-1, x-1};
}

int main(){
    int h,w,q;
    scanf(" %d %d %d", &h, &w, &q);

    vector<vector<int>> a(h,vector<int>(w));
    rep(i,h)rep(j,w) scanf(" %d", &a[i][j]);

    vector<pi> s(q),g(q);
    rep(i,q){
        s[i] = READ();
        g[i] = READ();
    }

    vector<int> x;
    x.pb(0);
    rep(i,h)rep(j,w) x.pb(a[i][j]);

    sort(all(x));
    x.erase(unique(all(x)), x.end());
    int X = x.size();

    unordered_map<int,int> v2id;
    rep(i,X) v2id[x[i]] = i;

    vector<vector<pi>> pts(X);
    rep(i,h)rep(j,w) pts[v2id[a[i][j]]].pb({i,j});

    auto ID = [&](int yy, int xx){
        return yy*w + xx;
    };

    auto IN = [&](int yy, int xx){
        return 0<=yy && yy<h && 0<=xx && xx<w;
    };

    vector<int> ng(q,0), ok(q,X-1);
    rep(loop,18){
        vector<vector<int>> QUERY(X);
        rep(i,q) QUERY[(ng[i]+ok[i])/2].pb(i);

        UF uf(h*w);

        rep(i,X){
            for(pi p:pts[i]){
                rep(j,4){
                    int ny = p.fi+dy[j], nx = p.se+dx[j];
                    if(IN(ny,nx) && a[ny][nx]<=x[i]){
                        uf.unite(ID(p.fi,p.se), ID(ny,nx));
                    }
                }
            }

            for(int qid:QUERY[i]){
                int sid = ID(s[qid].fi, s[qid].se);
                int gid = ID(g[qid].fi, g[qid].se);

                if(uf.same(sid,gid)) ok[qid] = i;
                else ng[qid] = i;
            }
        }
    }

    rep(i,q){
        int ans = x[ok[i]];
        if(s[i] == g[i]) ans = a[s[i].fi][s[i].se];
        printf("%d\n", ans);
    }
    return 0;
}

