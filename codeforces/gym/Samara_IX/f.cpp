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

#define X first
#define Y second

using P = pair<double, double>;

P READ(){
    int x,y;
    cin >>x >>y;
    return {x,y};
}

double dist(P a, P b){
    return sqrt( (a.X-b.X)*(a.X-b.X) + (a.Y-b.Y)*(a.Y-b.Y) );
}

int main(){
    P p[2],v[2];
    rep(i,2) p[i] = READ();
    rep(i,2) v[i] = READ();

    auto f = [&](double t){
        P q[2];
        rep(i,2){
            q[i].X = p[i].X + v[i].X*t;
            q[i].Y = p[i].Y + v[i].Y*t;
        }
        return dist(q[0],q[1]);
    };

    double l=0, r=100000;
    rep(loop,100){
        double m1 = (2*l+r)/3, m2 = (l+2*r)/3;
        if(f(m1) > f(m2)) l = m1;
        else r = m2;
    }
    printf("%.10f\n", f(l));
    return 0;
}
