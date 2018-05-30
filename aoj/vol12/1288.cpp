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

const double eps = 1e-6;

using Point = pair<int,int>;
using Line = pair<Point,Point>;

inline Line read_L(){
    Point p1,p2;
    cin >>p1.fi >>p1.se >>p2.fi >>p2.se;
    if(p1>p2) swap(p1,p2);
    return {p1,p2};
}

double dist(double px, double py, double qx, double qy){
    return sqrt((qx-px)*(qx-px) + (qy-py)*(qy-py));
}

bool on(Line l, Point p){
    Point q1 = l.fi, q2 = l.se;
    int dx = q2.fi - q1.fi, dy = q2.se - q1.se;

    double t;
    if(dx != 0) t = (double)(p.fi-q1.fi)/dx;
    else t = (double)(p.se-q1.se)/dy;

    double px = q1.fi + t*dx;
    double py = q1.se + t*dy;

    if(0<t && t<1){
        return (dist(px,py,p.fi,p.se) < eps);
    }
    return false;
}

int isec(Line l, Line m){
    if(l.fi == m.fi || l.fi == m.se || l.se == m.fi || l.se == m.se) return 1;
    if(on(l,m.fi) || on(l,m.se) || on(m,l.fi) || on(m,l.se)) return 2;
    return 0;
}

int recognize(const vector<Line> &v){
    // 棒の本数
    int V = v.size();

    set<Point> s;
    map<Point,int> ct;
    rep(i,V){
        s.insert(v[i].fi);
        s.insert(v[i].se);
        ++ct[v[i].fi];
        ++ct[v[i].se];
    }

    // 頂点の数
    int S = s.size();

    if(V==4 && S==4) return 0;
    if(V==1 && S==2) return 1;
    if(V==4 && S==6) return 3;
    if(V==3 && S==5) return 4;
    if(V==3 && S==4) return 7;
    if(V==4 && S==5) return 9;

    int two = 0;
    rep(i,V){
        if(ct[v[i].fi]==1 && ct[v[i].se]==1) ++two;
    }
    if(two==1) return 8;

    rep(i,V)rep(j,i){
        if(isec(v[i],v[j])==2) return 6;
    }

    // 2 or 5

    // parallel 3 lines
    map<pair<int,int>,int> d_ct;
    vector<pair<int,int>> d(V);
    rep(i,V){
        Point p1 = v[i].fi, p2 = v[i].se;
        int dx = p2.fi-p1.fi, dy = p2.se-p1.se;
        int G = __gcd(dx,dy);
        dx /= G;
        dy /= G;
        d[i] = {dx,dy};

        ++d_ct[d[i]];
    }

    // printf("d_ct:\n");
    // for(const auto &pp:d_ct) dbg(pp);

    vector<pair<double,Line>> p_l;
    rep(i,V)if(d_ct[d[i]]==3){

        // y-y1 = (y2-y1)/(x2-x1) (x-x1)
        // (y2-y1)(x-x1) - (x2-x1)(y-y1) = 0
        // (y2-y1)x - (x2-x1)y  -(y2-y1)x1 + (x2-x1)y1 = 0
        int x1 = v[i].fi.fi, y1 = v[i].fi.se;
        int x2 = v[i].se.fi, y2 = v[i].se.se;

        int A = y2-y1, B = -(x2-x1);
        int C = -(y2-y1)*x1 + (x2-x1)*y1;

        if(B==0){
            p_l.pb({C/(double)A ,v[i]});
        }
        else{
            p_l.pb({-C/(double)B ,v[i]});
        }
    }

    sort(all(p_l));
    // dbg(p_l);

    Line two_checker(p_l[1].se.se, p_l[2].se.se);
    if(two_checker.fi > two_checker.se) swap(two_checker.fi, two_checker.se);
    // dbg(two_checker);
    rep(i,V)if(v[i] == two_checker) return 2;
    return 5;
}

const int N = 1000;
vector<int> G[N];

int main(){
    int n;
    while(cin >>n,n){
        rep(i,N) G[i].clear();

        vector<Line> l(n);
        rep(i,n) l[i] = read_L();

        rep(i,n)rep(j,i){
            if(isec(l[i],l[j])!=0){
                G[i].pb(j);
                G[j].pb(i);
            }
        }

        int ans[10]={};
        vector<bool> vis(n);
        rep(i,n)if(!vis[i]){
            queue<int> que;
            vector<Line> cc;

            vis[i] = true;
            que.push(i);
            cc.pb(l[i]);
            while(!que.empty()){
                int v = que.front();
                que.pop();
                for(int nx:G[v]){
                    if(!vis[nx]){
                        vis[nx] = true;
                        que.push(nx);
                        cc.pb(l[nx]);
                    }
                }
            }

            int idx = recognize(cc);
            ++ans[idx];
        }

        rep(i,10) cout << ans[i] << " \n"[i==9];
    }
    return 0;
}
