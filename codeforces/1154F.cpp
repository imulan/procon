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

const int INF = 1010101010;

int main(){
    int n,m,k;
    scanf(" %d %d %d", &n, &m, &k);

    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);
    sort(all(a));

    vector<int> sale(k+1);
    rep(i,m){
        int x,y;
        scanf(" %d %d", &x, &y);
        if(x<=k) sale[x] = max(sale[x], y);
    }

    vector<int> dp(k+1, INF);
    dp[0] = 0;
    rep(i,k){

        int s = 0;
        vector<int> pre(k+1);
        for(int j=1; j<=k; ++j){
            int idx = i+j-1;
            if(idx>=k) break;

            s += a[idx];
            pre[j] = pre[j-1]+a[idx];

            int cost = s-pre[sale[j]];
            dp[i+j] = min(dp[i+j], dp[i]+cost);
        }
    }

    printf("%d\n", dp[k]);
    return 0;
}
