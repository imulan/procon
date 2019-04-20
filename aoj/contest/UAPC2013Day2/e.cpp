#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef complex<double> Point;
typedef pair<Point,Point> Line;
typedef vector<Point> VP;
const double EPS = 1e-6;
const double INF = 1e9;
#define X real()
#define Y imag()

#define LE(n,m) ((n)-(m) < EPS)
#define GE(n,m) (EPS > (m)-(n))
#define EQ(n,m) (abs((n)-(m)) < EPS)

const double PI = acos(-1);

namespace std {
    bool operator<(const Point a, const Point b){
        return a.X != b.X ? a.X < b.X : a.Y < b.Y;
    }
}

double dot(Point a, Point b){
    return a.X*b.X + a.Y*b.Y;
}

double cross(Point a, Point b){
    return a.X*b.Y - a.Y*b.X;
}

int ccw(Point a, Point b ,Point c){
    b -= a; c -= a;
    if(cross(b,c) >  EPS) return +1;
    if(cross(b,c) < -EPS) return -1;
    if(dot(b,c)   < -EPS) return +2;
    if(norm(b) < norm(c)) return -2;
    return 0;
}

Point proj(Point a1, Point a2, Point p){
    return a1 + dot(a2-a1, p-a1)/norm(a2-a1) * (a2-a1);
}

VP tangentPoints(Point a, double ar, Point p){
    VP ps;
    double sin = ar / abs(p-a);
    if( !LE(sin,1) ) return ps;
    double t = PI/2 - asin(min(sin, 1.0));
    ps.push_back( a+(p-a)*polar(sin,t) );
    if(!EQ(sin,1)) ps.push_back( a+(p-a)*polar(sin,-t) );
    return ps;
}

VP crosspointLC(Point a1, Point a2, Point c, double r){
    VP ps;
    Point ft = proj(a1,a2,c);
    if(!GE(r*r,norm(ft-c))) return ps;
    Point dir = sqrt(max(r*r-norm(ft-c),0.0)) / abs(a2-a1) * (a2-a1);
    ps.pb(ft+dir);
    if(!EQ(r*r,norm(ft-c))) ps.pb(ft-dir);
    return ps;
}

Point READ_P(){
    int x,y;
    cin >>x >>y;
    return Point(x,y);
}

double ang_to_rad(double a){
    return a/360*2*PI;
}

int V;
vector<vector<int>> gg;

vector<int> tlist;
vector<bool> vis;
void dfs(int x){
    if(vis[x]) return;
    vis[x] = true;
    for(int e:gg[x]) dfs(e);
    tlist.pb(x);
}

bool covered(Point c, double a, double lt, double rt, Point to, double tor){
    Point v(to.X-c.X, to.Y-c.Y);

    double dir = acos(v.X / hypot(v.X,v.Y));
    if(v.Y<0) dir = dir + 2*(PI-dir);

    // 半径内に入っている
    if( LE(abs(v)+tor, a) ){
        // 角度チェック
        Point pl = c + polar(a,lt), pr = c + polar(a,rt);

        bool angle_ok = false;
        for(int i=-1; i<=1; ++i){
            angle_ok |= (LE(lt+i*2*PI,dir)&&LE(dir,rt+i*2*PI));
        }
        if( angle_ok ){
            for(Point tt:{pl,pr}){
                Point h = proj(c,tt,to);
                if(GE(abs(to-h), tor)) continue;

                for(Point cp:crosspointLC(c,tt,to,tor)){
                    if(ccw(c,tt,cp) == 0) return false;
                }
            }
            return true;
        }
    }
    return false;
}

int main(){
    int n;
    cin >>n;

    V = n+2;

    double ts,as;
    int ps;
    cin >>ts >>as >>ps;
    ts = ang_to_rad(ts);

    VP c(n);
    vector<double> r(n),t(n),a(n),b(n);
    vector<int> p(n);
    rep(i,n){
        c[i] = READ_P();
        cin >>r[i] >>t[i] >>a[i] >>b[i] >>p[i];

        t[i] = ang_to_rad(t[i]);
        b[i] = ang_to_rad(b[i]);
    }

    Point goal;
    double gr;
    goal = READ_P();
    cin >>gr;

    int S = n, G = n+1;
    vector<vector<int>> g(n+2);

    rep(i,n)rep(j,n){
        if(i==j) continue;
        double lt = b[i]-t[i]/2, rt = b[i]+t[i]/2;
        if(covered(c[i],a[i],lt,rt,c[j],r[j])) g[i].pb(j);
    }

    // to goal
    rep(i,n){
        double lt = b[i]-t[i]/2, rt = b[i]+t[i]/2;
        if(covered(c[i],a[i],lt,rt,goal,gr)) g[i].pb(G);
    }

    Point ZERO(0,0);
    vector<double> cand;
    rep(i,n){
        if( LE(abs(c[i]-ZERO),0) ) continue;

        for(Point tp:tangentPoints(c[i],r[i],ZERO)){
            double dir = acos(tp.X / hypot(tp.X,tp.Y));
            if(tp.Y<0) dir = dir + 2*(PI-dir);

            for(double sub:vector<double>({0,-ts})){
                double add = dir+sub;
                if(add<0) add += 2*PI;
                cand.pb(add);
            }
        }
    }
    if( !LE(abs(goal-ZERO),0) ) {
        for(Point tp:tangentPoints(goal,gr,ZERO)){
            double dir = acos(tp.X / hypot(tp.X,tp.Y));
            if(tp.Y<0) dir = dir + 2*(PI-dir);

            for(double sub:vector<double>({0,-ts})){
                double add = dir+sub;
                if(add<0) add += 2*PI;
                cand.pb(add);
            }
        }
    }

    int ans = 0;
    for(double rad:cand){
        gg = g;

        double lt = rad, rt = rad+ts;
        rep(i,n){
            if(covered(ZERO,as,lt,rt,c[i],r[i])) gg[S].pb(i);
        }
        if(covered(ZERO,as,lt,rt,goal,gr)) gg[S].pb(G);


        tlist.clear();
        vis = vector<bool>(V,false);
        rep(i,V) dfs(i);

        reverse(all(tlist));
        vector<int> dp(V);
        dp[S] = ps;
        for(int i:tlist){
            if(i<n) dp[i] = min(dp[i], p[i]);
            for(int e:gg[i]) dp[e] += dp[i];
        }

        ans = max(ans, dp[G]);
    }
    cout << ans << endl;
    return 0;
}
