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

/* 基本要素 */
typedef complex<double> Point;
typedef pair<Point, Point> Line;
typedef vector<Point> VP;
const double PI = acos(-1);
const double EPS = 1e-7; // 許容誤差^2
const double INF = 1e9;
#define X real()
#define Y imag()
// #define LE(n,m) ((n) < (m) + EPS)
#define LE(n,m) ((n) - (m) < EPS)
// #define GE(n,m) ((n) + EPS > (m))
#define GE(n,m) (EPS > (m) - (n))
#define EQ(n,m) (abs((n)-(m)) < EPS)

// 内積　dot(a,b) = |a||b|cosθ
double dot(Point a, Point b) {
  return a.X*b.X + a.Y*b.Y;
}

// 外積　cross(a,b) = |a||b|sinθ
double cross(Point a, Point b) {
  return a.X*b.Y - a.Y*b.X;
}

// 点の進行方向
// !!! 誤差に注意 !!! (掛け算したものとかなり小さいものを比べているので)
int ccw(Point a, Point b, Point c) {
  b -= a;  c -= a;
  if (cross(b,c) >  EPS) return +1;  // counter clockwise
  if (cross(b,c) < -EPS) return -1;  // clockwise
  if (dot(b,c)   < -EPS) return +2;  // c--a--b on line
  if (norm(b) < norm(c)) return -2;  // a--b--c on line or a==b
  return 0;                          // a--c--b on line or a==c or b==c
}

// 2円の交点
VP crosspointCC(Point a, double ar, Point b, double br) {
  VP ps;
  Point ab = b-a;
  double d = abs(ab);
  double crL = (norm(ab) + ar*ar - br*br) / (2*d);
  if (EQ(d, 0) || ar+EPS < abs(crL)) return ps;

  // 円が接する時、こことEPSの設定をうまくしないとsqrt(sub)がnanになるので注意
  double sub = ar*ar - crL*crL;
  if(EQ(sub,0)) sub = 0;

  Point abN = ab * Point(0, sqrt(sub) / d);
  Point cp = a + crL/d * ab;
  ps.push_back(cp + abN);
  if (!EQ(norm(abN), 0)) ps.push_back(cp - abN);
  return ps;
}

// aからbへの回転角（中心(0,0)）[-pi,+pi]
double angle(Point a,Point b){
  double t = arg(b)-arg(a);
  while(t>+PI) t-=2*PI;
  while(t<-PI) t+=2*PI;
  return t;
}

double solve(int n, double r){
    VP c(n);
    vector<double> cr(n);
    rep(i,n){
        int x,y;
        scanf(" %d %d %lf", &x, &y, &cr[i]);
        c[i] = Point(x,y);
    }

    // 円iを含むために、中心が移動できる範囲
    rep(i,n){
        cr[i] = r - cr[i];
        // dbg(cr[i]);
        if( !LE(0,cr[i]) ) return 0;
    }

    // どれかを内包する円は除去
    vector<bool> inner(n);
    rep(i,n){
        rep(j,n)if(i!=j){
            double D = abs(c[i]-c[j]);
            if( LE(D+cr[i], cr[j]) ) inner[j] = true;
        }
    }

    VP tttc;
    vector<double> tttr;
    rep(i,n){
        if(!inner[i]){
            tttc.pb(c[i]);
            tttr.pb(cr[i]);
        }
    }

    c = tttc;
    cr = tttr;
    n = c.size();

    if(n==1){
        return (cr[0]+r)*2*PI;
    }

    // n >= 2
    // 円iと円jの交点を求める
    using PPI = pair<Point,int>;
    vector<vector<PPI>> cps(n);

    rep(i,n)rep(j,i){
        VP cnd = crosspointCC(c[i], cr[i], c[j], cr[j]);
        if(cnd.size() == 0){
            // 交点がない時点で、2つを同時に包含できないのでおわり
            return 0;
        }
        else if(cnd.size() == 1){
            // 接するような円が見つかった時点で、その点にしか円はおけない
            // 置けるなら半径rの円
            bool ok = true;
            Point op = cnd[0];
            rep(k,n){
                if( !LE(abs(c[k]-op), cr[k]) ) ok = false;
            }

            if(ok) return r*2*PI;
            else return 0;
        }

        for(Point cp:cnd){
            cps[i].pb({cp,j});
            cps[j].pb({cp,i});
        }
    }

    // 偏角ソート
    double ans = 0;
    VP cand_pts;
    rep(i,n){
        vector<PPI> dat = cps[i];
        int sz = dat.size();

        // (偏角, index)
        using pd = pair<double,int>;
        vector<pd> stmp(sz);
        rep(j,sz){
            double theta = atan2(dat[j].fi.Y-c[i].Y, dat[j].fi.X-c[i].X);
            if( theta < -EPS ) theta = 2*PI + theta;
            stmp[j] = {theta, j};
        }

        sort(all(stmp));

        vector<double> cand_theta(sz);
        vector<int> valid(sz,1);
        rep(j,sz){
            double add = stmp[(j+1)%sz].fi - stmp[j].fi;
            if(add < -EPS) add += 2*PI;
            add /= 2;

            cand_theta[j] = stmp[j].fi + add;

            Point cp = c[i]+polar(cr[i],cand_theta[j]);
            // dbg(cp);
            // この点がokかチェック
            rep(k,n){
                if( !LE(abs(c[k]-cp), cr[k]) ) valid[j] = 0;
            }

            if(valid[j]){
                double theta = stmp[(j+1)%sz].fi - stmp[j].fi;
                if(theta < -EPS) theta += 2*PI;

                if(EQ(theta,0)) valid[j] = false;
                else ans += theta * (r+cr[i]);
            }
        }

        // printf(" --- %d \n",i);
        // dbg(dat);
        // dbg(stmp);
        // dbg(valid);

        rep(j,sz){
            if(valid[j]^valid[(j+1)%sz]){
                int idx = stmp[(j+1)%sz].se;
                cand_pts.pb(dat[idx].fi);
            }
        }
    }

    int CPZ = cand_pts.size();
    rep(i,CPZ){
        bool ok = true;
        rep(j,i){
            double dist = abs(cand_pts[j] - cand_pts[i]);
            if(EQ(dist,0)) ok = false;
        }
        if(!ok) continue;
        // dbg(cand_pts[i]);

        double mx_angle = 0;
        rep(ci,n)rep(cj,ci){
            bool valid_pair = false;

            for(Point ppp:crosspointCC(c[ci],cr[ci],c[cj],cr[cj])){
                double ddd = abs(ppp - cand_pts[i]);
                if(EQ(ddd,0)) valid_pair = true;
            }

            if(valid_pair){
                Point center = cand_pts[i];
                Point aaa = c[ci] - center;
                Point bbb = c[cj] - center;

                mx_angle = max(mx_angle, abs(angle(aaa,bbb)));
            }
        }

        ans += mx_angle*r;
    }

    return ans;
}

int main(){
    int n;
    double r;
    while( scanf(" %d %lf", &n, &r),n ){
        printf("%.15f\n", solve(n,r));
    }
    return 0;
}
