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

int main(){
    int n,t;
    scanf(" %d %d", &n, &t);

    double ans = 0;
    rep(i,n){
        int x,h;
        scanf(" %d %d", &x, &h);
        // x:h = t:ans
        ans = max(ans, (double)h*t/x);
    }
    printf("%.10f\n", ans);
    return 0;
}
