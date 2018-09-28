#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

#define double long double

// using ll = long long;
using ll = __int128;

ll ABS(ll x){
    if(x<0) return -x;
    return x;
}

using F = pair<ll,ll>;
using Point = pair<F,F>;
using Line = pair<Point,Point>;

#define X first
#define Y second

F ADD_F(F p, F q, int m){
    ll aa = p.fi*q.se + m*q.fi*p.se;
    ll bb = p.se*q.se;

    ll G = __gcd(ABS(aa),bb);
    aa /= G;
    bb /= G;
    return {aa,bb};
}

F MUL_F(F p, F q){
    ll aa = p.fi*q.fi;
    ll bb = p.se*q.se;

    ll G = __gcd(ABS(aa),bb);
    aa /= G;
    bb /= G;
    return {aa,bb};
}

int COMP_F(F p, F q){
    ll res = p.fi*q.se - q.fi*p.se;
    if(res==0) return 0;
    if(res<0) return 1; // p<q
    return -1; // p>q
}

namespace std {
    bool operator<(const Point a, const Point b) {
        return COMP_F(a.X,b.X)!=0 ? COMP_F(a.X,b.X)==1 : COMP_F(a.Y,b.Y)==1;
    }
}

Point ADD_P(Point a, Point b, int m){
    return {ADD_F(a.X,b.X,m), ADD_F(a.Y,b.Y,m)};
}

Point MUL_P(Point a, F mul){
    return {MUL_F(a.X,mul), MUL_F(a.Y,mul)};
}

// 内積　dot(a,b) = |a||b|cosθ
F dot(Point a, Point b) {
    return ADD_F( MUL_F(a.X,b.X), MUL_F(a.Y,b.Y), 1);
}

// 外積　cross(a,b) = |a||b|sinθ
F cross(Point a, Point b) {
    return ADD_F( MUL_F(a.X,b.Y), MUL_F(a.Y,b.X), -1);
}

F norm(Point a){
    return ADD_F( MUL_F(a.X,a.X), MUL_F(a.Y,a.Y), 1);
}

int ccw(Point a, Point b, Point c) {
    b = ADD_P(b,a,-1);
    c = ADD_P(c,a,-1);
    if (cross(b,c).fi >  0) return +1;  // counter clockwise
    if (cross(b,c).fi <  0) return -1;  // clockwise
    if (dot(b,c).fi   <  0) return +2;  // c--a--b on line
    if (COMP_F(norm(b),norm(c)) == 1) return -2;  // a--b--c on line or a==b
    return 0;                          // a--c--b on line or a==c or b==c
}

// 線分と線分
bool isecSS(Point a1, Point a2, Point b1, Point b2) {
  return ccw(a1, a2, b1)*ccw(a1, a2, b2) <= 0 &&
  ccw(b1, b2, a1)*ccw(b1, b2, a2) <= 0;
}

// 線分と点
bool isecSP(Point a1, Point a2, Point b) {
  return !ccw(a1, a2, b);
}

// 2直線の交点
Point crosspointLL(Point a1, Point a2, Point b1, Point b2) {
    F d1 = cross( ADD_P(b2,b1,-1), ADD_P(b1,a1,-1) );
    F d2 = cross( ADD_P(b2,b1,-1), ADD_P(a2,a1,-1) );
    if (d1.fi==0 && d2.fi==0) return a1;  // same line
    assert(d2.se!=0); // 交点がない

    if(d2.fi<0){
        d2.fi *= -1;
        d2.se *= -1;
    }
    swap(d2.fi, d2.se);

    F pp = d1;
    pp = MUL_F(d1,d2);

    return ADD_P(a1, MUL_P(ADD_P(a2,a1,-1), pp), 1);
}

Point READ_P(){
    int x,y;
    cin >>x >>y;
    return {{x,1},{y,1}};
}

using pi = pair<int,int>;

double sq(double x){
    return x*x;
}

int main(){
    int n,m;
    cin >>n >>m;

    double U = 0;
    vector<Line> pipe(n);
    rep(i,n){
        pipe[i].fi = READ_P();
        pipe[i].se = READ_P();

        U += sqrt( sq(pipe[i].fi.X.fi - pipe[i].se.X.fi) + sq(pipe[i].fi.Y.fi - pipe[i].se.Y.fi) );
    }

    vector<Point> valve(m);
    map<Point,int> v2id;
    rep(i,m){
        valve[i] = READ_P();
        v2id[valve[i]] = i;
    }

    Point source = READ_P(), repair = READ_P();

    vector<vector<Point>> seg(n);
    rep(i,n){
        seg[i].pb(pipe[i].fi);
        seg[i].pb(pipe[i].se);

        if(isecSP(pipe[i].fi, pipe[i].se, source)) seg[i].pb(source);
        if(isecSP(pipe[i].fi, pipe[i].se, repair)) seg[i].pb(repair);
        rep(j,m){
            if(isecSP(pipe[i].fi, pipe[i].se, valve[j])) seg[i].pb(valve[j]);
        }
    }

    map<Point,pi> intersection;
    rep(i,n)rep(j,i){
        if(isecSS(pipe[i].fi,pipe[i].se,pipe[j].fi,pipe[j].se)){
            Point cp = crosspointLL(pipe[i].fi,pipe[i].se,pipe[j].fi,pipe[j].se);

            seg[i].pb(cp);
            seg[j].pb(cp);
            intersection[cp] = {j,i};
        }
    }

    vector<vector<bool>> vis(n);
    vector<int> sz(n);
    rep(i,n){
        sort(all(seg[i]));
        seg[i].erase(unique(all(seg[i])), seg[i].end());
        sz[i] = seg[i].size();
        vis[i] = vector<bool>(sz[i],false);
    }

    auto is_valve = [&](Point p){
        return v2id.count(p);
    };

    // 締めるべきバルブを決定
    queue<pi> que;
    rep(i,n){
        int idx = lower_bound(all(seg[i]), repair) - seg[i].begin();
        if(idx < sz[i] && seg[i][idx] == repair){
            vis[i][idx] = true;
            que.push({i,idx});
        }
    }

    vector<bool> stop(m);
    while(!que.empty()){
        pi now = que.front();
        que.pop();
        int pid = now.fi;

        Point ppp = seg[now.fi][now.se];


        if(is_valve(ppp)){
            stop[v2id[ppp]] = true;
            continue;
        }

        // 違うパイプへ
        if(intersection.count(ppp)){
            pi I = intersection[ppp];
            int npid = I.fi + I.se - pid;
            int nidx = lower_bound(all(seg[npid]),ppp) - seg[npid].begin();
            if(!vis[npid][nidx]){
                vis[npid][nidx] = true;
                que.push({npid,nidx});
            }
        }

        // 隣へ
        for(int i:{-1,1}){
            int nx = now.se + i;
            if(0<=nx && nx<sz[pid] && !vis[pid][nx]){
                vis[pid][nx] = true;
                que.push({pid,nx});
            }
        }
    }


    // 水の到達箇所をチェック
    // initialize
    rep(i,n) vis[i] = vector<bool>(sz[i],false);

    rep(i,n){
        int idx = lower_bound(all(seg[i]), source) - seg[i].begin();
        if(idx < sz[i] && seg[i][idx] == source){
            vis[i][idx] = true;
            que.push({i,idx});
        }
    }
    while(!que.empty()){
        pi now = que.front();
        que.pop();
        int pid = now.fi;

        Point ppp = seg[now.fi][now.se];

        // fail
        if(ppp == repair){
            printf("-1\n");
            return 0;
        }

        if(is_valve(ppp) && stop[v2id[ppp]]) continue;

        // 違うパイプへ
        if(intersection.count(ppp)){
            pi I = intersection[ppp];
            int npid = I.fi + I.se - pid;
            int nidx = lower_bound(all(seg[npid]),ppp) - seg[npid].begin();
            if(!vis[npid][nidx]){
                vis[npid][nidx] = true;
                que.push({npid,nidx});
            }
        }

        // 隣へ
        for(int i:{-1,1}){
            int nx = now.se + i;
            if(0<=nx && nx<sz[pid] && !vis[pid][nx]){
                vis[pid][nx] = true;
                que.push({pid,nx});
            }
        }
    }

    double sub = 0;
    rep(i,n){
        rep(j,sz[i]-1){
            if(vis[i][j] && vis[i][j+1]){
                Point vec = ADD_P(seg[i][j],seg[i][j+1],-1);

                F vx = vec.X, vy = vec.Y;

                double dx = (double)vx.fi/vx.se;
                double dy = (double)vy.fi/vy.se;

                sub += sqrt( sq(dx) + sq(dy));
            }
        }
    }
    printf("%.10Lf\n", U - sub);
    return 0;
}
