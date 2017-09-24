#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(int)n; ++i)
#define all(x) (x).begin() (x).end()

#define double long double

using P = complex<double>;

typedef complex<double> Point;
typedef vector<Point> VP;
const double EPS = 1e-3;

#define X real()
#define Y imag()

double dot(Point a,Point b){
    return a.X*b.X+a.Y*b.Y;
}

double cross(Point a,Point b){
    return a.X*b.Y-a.Y*b.X;
}

int ccw(Point a,Point b,Point c){
    b-=a; c-=a;
    if(cross(b,c) > EPS) return 1;
    if(cross(b,c) < -EPS) return -1;
    if(dot(b,c) < -EPS) return 2;
    if(norm(b) < norm(c)) return -2;
    return 0;
}

Point proj(Point a1,Point a2,Point p){
    return a1 + dot(a2-a1,p-a1)/norm(a2-a1) * (a2-a1);
}

namespace std {
    bool operator<(const Point a,const Point b){
        return a.X!=b.X ? a.X<b.X : a.Y<b.Y;
    }
}

VP convexHull(VP& ps){
    int n = ps.size(),k=0;
    sort(ps.begin(),ps.end());
    VP ch(2*n);
    for(int i=0;i<n;ch[k++]=ps[i++])
        while(k>=2 && ccw(ch[k-2],ch[k-1],ps[i]) <= 0) --k;
    for(int i=n-2,t=k+1;i>=0;ch[k++]=ps[i--])
        while(k>=t && ccw(ch[k-2],ch[k-1],ps[i]) <= 0) --k;
    ch.resize(k-1);
    return ch;
}

#define cv_edge(CV,i) CV[i],CV[(i+1)%CV.size()]


bool solve(){
    int N,H,W,R;
    cin>>N>>H>>W>>R;
    H-=R*2;
    W-=R*2;
    if(H>W) swap(H,W);
    //H<=W
    VP p(N);
    rep(i,N) {
        double x,y;
        cin>>x>>y;
        p[i] = Point(x,y);
    }

    if(!(H>=0 && W>=0)){
        return false;
    }

    if(N==1){
        return (H>=0 && W>=0);
    }

    if(N==2){
        return (abs(p[0]-p[1])<=W);
    }

    VP ps = convexHull(p);
    int n = ps.size();
    rep(i,n){
        VP pjs;
        double h=0;
        rep(j,n){
            Point pj = proj(cv_edge(ps, i),ps[j]);
            pjs.push_back(pj);
            h = max(abs(pj-ps[j]),h);
        }
        sort(pjs.begin(),pjs.end());
        double w = abs(pjs[0]-pjs[n-1]);
        if(h>w)swap(h,w);
        if(w<=W+EPS && h<=H+EPS){
            return true;
        }
    }
    return false;
}

int main()
{
    cout<<(solve() ? "Yes" : "No")<<endl;
    return 0;
}
