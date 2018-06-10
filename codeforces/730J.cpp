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

const int N = 110;
const int V = 10010;
const int INF = 19191919;
int dp[N][V];
int nx[N][V];

int main(){
    int n;
    cin >>n;
    vector<int> a(n),b(n);
    rep(i,n) cin >>a[i];
    rep(i,n) cin >>b[i];

    int suma = 0;
    rep(i,n) suma += a[i];

    int sumb = 0;
    vector<int> sb(b);
    sort(all(sb));

    int k = 0;
    while(sumb<suma){
        sumb += sb[n-1-k];
        ++k;
    }

    rep(i,N)rep(j,V) dp[i][j]=INF;
    dp[0][0] = 0;
    rep(i,n){
        rep(j,N)rep(l,V) nx[j][l]=INF;
        for(int j=k; j>=0; --j)rep(l,V){
            // つかう
            if(j+1<=k && l+b[i]<V) nx[j+1][l+b[i]] = min(nx[j+1][l+b[i]], dp[j][l]);
            // つかわない
            nx[j][l] = min(nx[j][l], dp[j][l]+a[i]);
        }

        rep(j,N)rep(l,V) dp[j][l]=nx[j][l];
    }

    int ans = INF;
    for(int i=suma; i<V; ++i) ans = min(ans, dp[k][i]);

    printf("%d %d\n", k, ans);
    return 0;
}
