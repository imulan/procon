#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back

typedef complex<double> Point;
typedef pair<Point,Point> Line;
typedef vector<Point> VP;
const double PI = acos(-1);
const double EPS = 1e-9;
const double INF = 1e9;
#define X real()
#define Y imag()
#define LE(n,m) ((n)-(m) < EPS)
#define GE(n,m) (EPS > (m)-(n))
#define EQ(n,m) (abs((n)-(m)) < EPS)

namespace std{
    bool operator<(const Point a, const Point b){
        return a.X!=b.X ? a.X<b.X : a.Y<b.Y;
    }
}

double dot(Point a, Point b){
    return a.X*b.X + a.Y*b.Y;
}

double cross(Point a, Point b){
    return a.X*b.Y - a.Y*b.X;
}

int ccw(Point a, Point b, Point c){
    b -= a;
    c -= a;
    if(cross(b,c) >  EPS) return +1;
    if(cross(b,c) < -EPS) return -1;
    if(dot(b,c)   < -EPS) return +2;
    if(norm(b) < norm(c)) return -2;
    return 0;
}

bool isecLS(Point a1, Point a2, Point b1, Point b2){
    return cross(a2-a1, b1-a1)*cross(a2-a1,b2-b1) < EPS;

}

Point crosspointLL(Point a1,Point a2,Point b1,Point b2){
    double d1 = cross(b2-b1, b1-a1);
    double d2 = cross(b2-b1, a2-a1);
    if(EQ(d1,0) && EQ(d2,0)) return a1;
//    assert(!EQ(d2,0));
    return  a1 + d1/d2 * (a2-a1);
}

//convex of left side of vector(a1 -> a2)
VP convexCut(const VP &ps, Point a1, Point a2){
    int n = ps.size();
    VP ret;
    rep(i,n){
        int ccwc = ccw(a1,a2,ps[i]);
        if(ccwc != -1) ret.pb(ps[i]);
        int ccwn = ccw(a1,a2,ps[(i+1)%n]);
        if(ccwc * ccwn == -1) ret.pb(crosspointLL(a1,a2,ps[i],ps[(i+1)%n]));
    }
    return ret;
}

VP convexHull(VP ps){
    int n = ps.size(), k=0;
    sort(all(ps));
    VP ch(2*n);
    for(int i=0; i<n; ch[k++]=ps[i++]){
        while(k>=2 && ccw(ch[k-2], ch[k-1], ps[i])<=0) --k;
    }
    for(int i=n-2, t=k+1; i>=0; ch[k++]=ps[i--]){
        while(k>=t && ccw(ch[k-2], ch[k-1], ps[i])<=0) --k;
    }
    ch.resize(k-1);
    return ch;
}

double area(const VP &ps){
    double a = 0;
    int n = ps.size();
    rep(i,n) a += cross(ps[i],ps[(i+1)%n]);
    return a/2;
}

int inPolygon(Point p, VP &ps){
    int n = ps.size();
    bool in = false;
    rep(i,n){
        Point a = ps[i]-p;
        Point b = ps[(i+1)%n] - p;
        if(EQ(cross(a,b),0) && LE(dot(a,b),0)) return 2;
        if(a.Y > b.Y) swap(a,b);
        if( (a.Y*b.Y<0 || (a.Y*b.Y<EPS && b.Y>EPS)) && LE(cross(a,b),0)){
            in = !in;
        }
    }
    return in;
}

inline bool query(int L, int R){
    printf("check %d %d\n",L,R);
    fflush(stdout);

    char res[10];
    scanf(" %s", res);
    return res[0]=='Y';
}

inline void ans(int x){
    printf("answer %d\n",x);
    fflush(stdout);
}

int main(){
    int P,V;
    cin >>P >>V;

    bool f = query(0,P/2);

    set<int> ux;
    if(f){
        ux.insert(0);
        ux.insert(P/2);
    }
    else{
        ux.insert(P);
        ux.insert(P/2);
    }

    VP h;
    if(P==1){
        for(int x:{0,1})for(int y:{0,V}){
            h.pb(Point(x, y));
        }
    }
    else {
        for (int x:ux) {
            for (int y:{0, V}) {
                h.pb(Point(x, y));
            }
        }
    }
    h = convexHull(h);

    int i = 1;
    while(i<45){
        double ah = area(h);
        if( h.size()<3 || EQ(ah,0) ) break;

//        printf(" --- HULL \n");
//        for(Point pp:h){
//            cout << "  " << pp << endl;
//        }

        auto check = [&](int mid){
            Point p(0,(double)mid/i);
            Point q(100,(double)(mid-100)/i);

            bool cr = false;
            int H = h.size();
            rep(j,H){
                Point a1 = h[j], a2 = h[(j+1)%H];
                if(isecLS(p,q,a1,a2)){
                    cr = true;
                }
            }

            if(!cr){
                return LE(h[0].Y, (mid-h[0].X)/i);
            }
            else{
                VP lh = convexCut(h,q,p);
                return LE( ah, 2*area(lh));
            }
        };

        int ng=-1, ok=P+V;
        while(ok-ng>1){
            int mid = (ng+ok)/2;

            bool res = check(mid);
//            cout << "mid: "<<mid<<endl;
//            cout << "res: "<<res<<endl;

            if(res) ok = mid;
            else ng = mid;
        }

        bool res = query(0,ok);
        Point p(0,(double)ok/i);
        Point q(100,(double)(ok-100)/i);
        if(res) h = convexCut(h,q,p);
        else h = convexCut(h,p,q);

        ++i;
    }

//    printf(" --- HULL \n");
//    for(Point pp:h){
//        cout << "  " << pp << endl;
//    }

    double lx=P,rx=0;
    double ly=V,ry=0;
    for(Point pp:h){
        lx = min(lx,pp.X);
        rx = max(rx,pp.X);
        ly = min(ly,pp.Y);
        ry = max(ry,pp.Y);
    }

    for(int x=lx; x<=rx+1; ++x){
        for(int y=ly; y<=ry+1; ++y){
            Point c(x,y);
            if(inPolygon(c,h)!=0){
                int val = x+i*y;
                bool res = query(val,val);
                ++i;
                if(res){
                    ans(x+i*y);
                    return 0;
                }
            }
        }
    }
//    assert(false);
    return 0;
}