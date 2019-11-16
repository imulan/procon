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
    cin >>n;
    vector<int> x(n),y(n);
    rep(i,n) cin >>x[i] >>y[i];

    vector<int> p(n);
    rep(i,n) p[i] = i;

    auto dist = [&](int a, int b){
        int X = x[a]-x[b];
        int Y = y[a]-y[b];
        return sqrt(X*X+Y*Y);
    };

    int ct = 0;
    double ans = 0;
    do{
        ++ct;
        rep(i,n-1) ans += dist(p[i],p[i+1]);
    }while(next_permutation(all(p)));
    ans /= ct;
    printf("%.15f\n", ans);
    return 0;
}
