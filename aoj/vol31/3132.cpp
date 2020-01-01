#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

int main(){
    int n;
    scanf(" %d", &n);

    vector<int> t(n),a(n);
    rep(i,n) scanf(" %d %d", &t[i], &a[i]);

    vector<double> p(n+1,1);
    rep(i,n) p[i] = (100-10*a[i])*0.01;
    for(int i=1; i<n; ++i) p[i] *= p[i-1];

    int q;
    scanf(" %d", &q);
    rep(qqq,q){
        int l,r;
        scanf(" %d %d", &l, &r);

        int lidx = lower_bound(all(t), l) - t.begin();
        int ridx = lower_bound(all(t), r) - t.begin();
        --ridx;

        double x = p[ridx];
        if(lidx > 0) x /= p[lidx-1];
        printf("%.10f\n", 1e9*x);
    }
    return 0;
}
