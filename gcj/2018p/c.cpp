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

double solve(){
    int d,n;
    cin >>d >>n;

    double max_t = 0;
    rep(i,n){
        int k,s;
        cin >>k >>s;

        double D = d-k;
        max_t = max(max_t, D/s);
    }

    return d/max_t;
}

int main(){
    int T;
    cin >>T;
    rep(i,T) printf("Case #%d: %.10f\n", i+1, solve());
    return 0;
}
