#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);i++)
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back((a))
#define all(x) begin(x),end(x)
#define uniq(x) sort(all(x)),(x).erase(unique(all(s)),end(x))
#define dbg(x) cout<<#x" = "<<((x))<<endl

typedef complex<double> Point;
typedef pair<Point,Point> Line;
typedef vector<Point> VP;
const double EPS = 1e-7;

#define X real()
#define Y imag()
#define LE(n,m) ((n) < (m)+EPS)
#define GE(n,m) ((n) +EPS > (m))
#define EQ(n,m) (abs(n-m) < EPS)

namespace std{
    bool operator<(const Point a, const Point b){
        return a.X != b.X ? a.X < b.X : a.Y < b.Y;
    }
}

double dot(Point a,Point b){
    return a.X*b.X+a.Y*b.Y;
}

double cross(Point a,Point b){
    return a.X*b.Y-a.Y*b.X;
}

int ccw(Point a,Point b,Point c){
    b-=a;
    c-=a;
    if(cross(b,c)>EPS)return +1;
    if(cross(b,c)<-EPS)return -1;
    if(dot(b,c)<-EPS)return +2;
    if(norm(b)<norm(c))return -2;
    return 0;
}

bool isecSS(Point a1,Point a2,Point b1,Point b2){
    return ccw(a1,a2,b1)*ccw(a1,a2,b2)<=0 &&
    ccw(b1,b2,a1)*ccw(b1,b2,a2)<=0;
}

bool isecSP(Point a1,Point a2,Point b){
    return !ccw(a1,a2,b);
}

Point proj(Point a1,Point a2,Point p){
    return a1+dot(a2-a1,p-a1)/norm(a2-a1)*(a2-a1);
}

double distSP(Point a1,Point a2,Point p){
    Point r=proj(a1,a2,p);
    if(isecSP(a1,a2,r))return abs(r-p);
    return min(abs(a1-p),abs(a2-p));
}

double distSS(Point a1,Point a2,Point b1,Point b2){
    if(isecSS(a1,a2,b1,b2))return 0;
    return min(min(distSP(a1,a2,b1),distSP(a1,a2,b2)),
               min(distSP(b1,b2,a1),distSP(b1,b2,a2)));
}


VP convexHull(VP ps){
    int n=ps.size(),k=0;
    sort(all(ps));
    VP ch(2*n);
    for(int i=0;i<n;ch[k++]=ps[i++])
        while(k>=2 && ccw(ch[k-2],ch[k-1],ps[i])<=0)--k;
    for(int i=n-2,t=k+1;i>=0;ch[k++]=ps[i--])
        while(k>=t && ccw(ch[k-2],ch[k-1],ps[i])<=0)--k;
    ch.resize(k-1);
    return ch;
}

int inConvex(Point p,const VP& ps){
    int n=ps.size();
    int dir = ccw(ps[0],ps[1],p);
    rep(i,n){
        int ccwc = ccw(ps[i],ps[(i+1)%n],p);
        if(!ccwc)return 2;
        if(ccwc != dir)return 0;
    }
    return 1;
}


int main()
{
    int n;
    while(cin>>n, n){
        vector<int> nv(n);
        vector<double> h(n);
        vector<VP> vec(n, VP());
        rep(i,n)
        {
            cin>>nv[i]>>h[i];
            vec[i].resize(nv[i]);
            rep(j,nv[i]){
                double x,y;
                cin>>x>>y;
                vec[i][j] = {x,y};
            }
        }
        double theta, phi;
        cin>>theta>>phi;
        theta *= M_PI / 180.0;
        phi *= M_PI / 180.0;
        double sx,sy,tx,ty;
        cin>>sx>>sy>>tx>>ty;

        Point sp = {sx, sy}, tp ={tx, ty};

        rep(i,n){
            rep(j,nv[i]){
                Point np = vec[i][j] - (Point){h[i]*cos(theta)/tan(phi), h[i]*sin(theta)/tan(phi)};
                vec[i].pb(np);
            }
            vec[i] = convexHull(vec[i]);
            nv[i] = vec[i].size();
        }

        // rep(i,n){
        //     rep(j,nv[i]) cout << vec[i][j];
        //     cout << endl;
        // }

        vector<vector<double>> d(n+2,vector<double>(n+2,1234567890));

        auto inside = [&](int v, int u){
            rep(k,nv[v]){
                if(inConvex(vec[v][k], vec[u]) >= 1) {
                    return true;
                }
            }
            return false;
        };

        rep(i,n+2) d[i][i] = 0;
        rep(i,n)rep(j,i){
            if(inside(i,j) || inside(j,i)) d[i][j] = d[j][i] = 0;
            else {
                double x = 1234567890;
                rep(k,nv[i])rep(l,nv[j]){
                    x = min(x, distSS(vec[i][k], vec[i][(k+1)%nv[i]], vec[j][l], vec[j][(l+1)%nv[j]]));
                }
                d[i][j] = d[j][i] = x;
            }
        }

        rep(i,n){
            double x = 1234567890;
            if(inConvex(sp, vec[i])>=1) x = 0;
            else {
                rep(j,nv[i]){
                    x = min(x, distSP(vec[i][j], vec[i][(j+1)%nv[i]], sp));
                }
            }
            d[n][i] = x;
        }

        rep(i,n){
            double x = 1234567890;
            if(inConvex(tp, vec[i])>=1) x=0;
            else {
                rep(j,nv[i]){
                    x = min(x, distSP(vec[i][j], vec[i][(j+1)%nv[i]], tp));
                }
            }
            d[i][n+1] = x;
        }

        d[n][n+1] = abs(sp - tp);

        n += 2;

        // rep(i,n){
        //     rep(j,n) printf("%.4f ");
        //     cout << endl;
        // }

        rep(k,n)rep(i,n)rep(j,n) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

        printf("%.10f\n", d[n-2][n-1]);

    }


    return 0;
}
