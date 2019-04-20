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

const ll mod = 1e9+7;

const int N = 1010;
ll C[N][N];

ll solve(){
    int n;
    scanf(" %d", &n);

    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);
    sort(all(a));


}

int main(){
    C[0][0] = 1;
    for(int i=1; i<N; ++i){
        C[i][0] = C[i][i] = 1;
        for(int j=1; j<i; ++j) C[i][j] = (C[i-1][j-1]+C[i-1][j])%mod;
    }

    int T;
    scanf(" %d", &T);
    rep(_,T) printf("%lld\n", solve());

    return 0;
}
