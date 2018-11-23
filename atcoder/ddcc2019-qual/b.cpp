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

const double EPS = 1e-8;

int main(){
    int n;
    cin >>n;

    int ans = 0;
    double cx = 0.5, cy = 0.5;
    rep(i,n)rep(j,n){

        int a = 1;
        rep(ii,2)rep(jj,2){
            double x = (double)(i+ii)/n;
            double y = (double)(j+jj)/n;
            double d = abs(x-cx)+abs(y-cy);
            if(d > 0.5+EPS) a = 0;
        }
        ans += a;
    }

    cout << ans << endl;
    return 0;
}
