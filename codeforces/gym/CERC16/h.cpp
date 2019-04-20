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

struct UF{
    int n;
    //正だったらその頂点の親,負だったら根で連結成分の個数
    vector<int> d;
    UF() {}
    UF(int N):n(N), d(N,-1){}
    int root(int v){
        if(d[v]<0) return v;
        return d[v]=root(d[v]);
    }
    bool unite(int X,int Y){
        X=root(X); Y=root(Y);
        if(X==Y) return false;
        if(size(X) < size(Y)) swap(X,Y);
        d[X]+=d[Y];
        d[Y]=X;
        return true;
    }
    int size(int v){ return -d[root(v)]; }
    bool same(int X,int Y){ return root(X)==root(Y); }
};

using pi = pair<int,int>;

const int N = 1010;
char s[N][N];

const int dy[4]={1,-1,0,0};
const int dx[4]={0,0,1,-1};

int main(){
    int n;
    scanf(" %d", &n);
    rep(i,n) scanf(" %s", s[i]);

    int q;
    scanf(" %d", &q);
    vector<int> a(q), b(q);
    rep(i,q){
        int ra,ca,rb,cb;
        scanf(" %d %d %d %d", &ra, &ca, &rb, &cb);
        a[i] = (ra-1)*n + ca-1;
        b[i] = (rb-1)*n + cb-1;
    }

    auto IN = [&](int y, int x){
        return 0<=y && y<n && 0<=x && x<n;
    };

    vector<vector<int>> sq(n,vector<int>(n,-1));
    rep(i,n)for(int j:{0,n-1}){
        if(s[j][i]=='.') sq[j][i] = 1;
        if(s[i][j]=='.') sq[i][j] = 1;
    }
    rep(i,n)rep(j,n)if(s[i][j]=='#'){
        sq[i][j] = 0;
        for(int yy=-1; yy<=1; ++yy)for(int xx=-1; xx<=1; ++xx){
            int ny = i+yy, nx = j+xx;
            if(IN(ny,nx) && s[ny][nx]=='.') sq[ny][nx]=1;
        }
    }

    queue<pi> que;
    rep(i,n)rep(j,n)if(sq[i][j]==1) que.push({i,j});
    while(!que.empty()){
        pi c = que.front();
        que.pop();
        int v = sq[c.fi][c.se];
        for(int yy=-1; yy<=1; ++yy)for(int xx=-1; xx<=1; ++xx){
            int ny = c.fi+yy, nx = c.se+xx;
            if(IN(ny,nx) && s[ny][nx]=='.' && sq[ny][nx]==-1){
                sq[ny][nx] = v+2;
                que.push({ny,nx});
            }
        }
    }

    vector<int> cand;
    cand.pb(0);
    for(int i=1; i<=n; i+=2) cand.pb(i);
    cand.pb(n+1);
    int sz = cand.size();

    vector<int> ok(q,0), ng(q,sz-1);

    vector<vector<pi>> pos(sz);
    rep(i,n)rep(j,n){
        if(sq[i][j]>0){
            int idx = (sq[i][j]+1)/2;
            pos[idx].pb({i,j});
        }
    }

    rep(loop,9){
        vector<vector<int>> QUERY(sz);
        rep(i,q) QUERY[(ok[i]+ng[i])/2].pb(i);

        UF uf(n*n);
        for(int i=sz-1; i>=0; --i){
            for(pi p:pos[i]){
                rep(d,4){
                    int ny = p.fi+dy[d], nx = p.se+dx[d];
                    if(IN(ny,nx) && cand[i] <= sq[ny][nx]){
                        uf.unite(n*p.fi+p.se, n*ny+nx);
                    }
                }
            }

            for(int idx:QUERY[i]){
                if(uf.same(a[idx],b[idx])) ok[idx] = i;
                else ng[idx] = i;
            }
        }
    }

    rep(i,q) printf("%d\n", cand[ok[i]]);
    return 0;
}
