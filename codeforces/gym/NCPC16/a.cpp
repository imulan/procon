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

const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};

using pi = pair<int,int>;
using P = pair<pi,pi>;

P READ(){
    int x1,y1,x2,y2;
    scanf(" %d %d %d %d", &x1, &y1, &x2, &y2);
    --x1;
    --y1;
    --x2;
    --y2;
    return {{x1,y1},{x2,y2}};
}

const int N = 1000;
int ct[N][N];
bool vis[N][N];

void ADD(P p, int v){
    int x1 = p.fi.fi, y1 = p.fi.se, x2 = p.se.fi, y2 = p.se.se;
    if(y1==y2){
        for(int x=x1; x<=x2; ++x) ct[y1][x] += v;
    }
    else{
        for(int y=y1; y<=y2; ++y) ct[y][x1] += v;
    }
}

int main(){
    int w,h,q;
    scanf(" %d %d %d", &w, &h, &q);

    auto IN = [&](int y, int x){
        return 0<=y && y<h && 0<=x && x<w;
    };

    auto ID = [&](int y, int x){
        return y*w + x;
    };

    vector<P> l(q);
    rep(i,q) l[i] = READ();

    rep(i,q) ADD(l[i],1);

    UF uf(h*w);
    int num = 0;
    rep(i,h)rep(j,w){
        if(ct[i][j]>0 || vis[i][j]) continue;

        ++num;

        vis[i][j] = true;
        queue<pi> que({{i,j}});
        while(!que.empty()){
            pi p = que.front();
            que.pop();
            rep(d,4){
                int ny = p.fi+dy[d], nx = p.se+dx[d];
                if(IN(ny,nx) && ct[ny][nx]==0 && !vis[ny][nx]){
                    uf.unite(ID(p.fi,p.se),ID(ny,nx));
                    vis[ny][nx] = true;
                    que.push({ny,nx});
                }
            }
        }
    }

    auto CHECK = [&](int y, int x){
        ++num;
        rep(i,4){
            int ny = y+dy[i], nx = x+dx[i];
            if(!IN(ny,nx)) continue;
            if(ct[ny][nx] == 0){
                if(uf.unite(ID(y,x),ID(ny,nx))) --num;
            }
        }
    };

    vector<int> ans(q);
    ans[q-1] = num;
    for(int i=q-1; i>0; --i){
        int x1 = l[i].fi.fi, y1 = l[i].fi.se, x2 = l[i].se.fi, y2 = l[i].se.se;
        if(y1==y2){
            for(int x=x1; x<=x2; ++x){
                --ct[y1][x];
                if(ct[y1][x]==0) CHECK(y1,x);
            }
        }
        else{
            for(int y=y1; y<=y2; ++y){
                --ct[y][x1];
                if(ct[y][x1]==0) CHECK(y,x1);
            }
        }

        ans[i-1] = num;
    }

    rep(i,q) printf("%d\n", ans[i]);
    return 0;
}
