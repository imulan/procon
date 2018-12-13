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
    int n;
    cin >>n;
    vector<int> a[2];
    rep(i,2){
        a[i] = vector<int>(n);
        rep(j,n) cin >>a[i][j];
    }

    int ans = 0;
    rep(i,n){
        int t = 0;
        rep(j,i+1) t += a[0][j];
        for(int j=i; j<n; ++j) t += a[1][j];
        ans = max(ans, t);
    }
    cout << ans << endl;
    return 0;
}
