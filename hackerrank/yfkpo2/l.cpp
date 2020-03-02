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

const int N = 1010;
// num with power i seeing power j as rival
int see_as_rival[N][N];

int main(){
    int n;
    scanf(" %d", &n);

    int self_rival = 0;
    vector<int> p(n),l(n),r(n);
    rep(i,n){
        scanf(" %d %d %d", &p[i], &l[i], &r[i]);
        if(l[i]<=p[i] && p[i]<=r[i]) ++self_rival;

        ++see_as_rival[p[i]][l[i]];
        --see_as_rival[p[i]][r[i]+1];
    }

    rep(i,N){
        rep(j,N-1) see_as_rival[i][j+1] += see_as_rival[i][j];
    }

    ll ans = 0;
    rep(i,n){
        for(int j=l[i]; j<=r[i]; ++j) ans += see_as_rival[j][p[i]];
    }
    printf("%lld\n", (ans-self_rival)/2);
    return 0;
}
