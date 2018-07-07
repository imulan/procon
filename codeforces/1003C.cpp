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
    int n,k;
    cin >>n >>k;

    vector<int> a(n+1);
    rep(i,n) cin >>a[i+1];

    vector<int> pre(a);
    rep(i,n) pre[i+1] += pre[i];

    double ans = 0;
    for(int i=1; i<=n; ++i){
        for(int j=i+k-1; j<=n; ++j){
            double L = j-i+1;
            double s = pre[j]-pre[i-1];
            ans = max(ans, s/L);
        }
    }

    printf("%.10f\n", ans);
    return 0;
}
