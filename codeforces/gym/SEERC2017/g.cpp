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

using pi = pair<int,int>;

double calc(const vector<pi> &e){
    int n = e.size();

    double ret = 0;
    double v = 0;
    rep(i,n){
        double a = e[i].fi;
        double s = e[i].se;

        double nv = v+a*s;
        ret += (v+nv)*s*0.5;
        v = nv;
    }
    return ret;
}

int main(){
    int n;
    scanf(" %d", &n);

    vector<pi> p(n);
    rep(i,n) scanf(" %d %d", &p[i].fi, &p[i].se);

    double def = calc(p);

    sort(all(p));
    reverse(all(p));

    double opt = calc(p);

    printf("%.1f\n", opt - def);
    return 0;
}
