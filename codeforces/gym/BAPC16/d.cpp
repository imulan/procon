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

const int INF = 19191919;

int main(){
    int n;
    cin >>n;
    vector<int> t(n);
    rep(i,n) cin >>t[i];

    vector<int> dp(n+1,INF);
    dp[0] = 0;

    // start i
    rep(i,n){
        int ed = -INF;
        if(i>0) ed = t[i-1]+80;

        // end j
        for(int j=i; j<n; ++j){
            int num = j-i+1;
            int ss = min(t[i]+1800, t[j]+20-20*num);

            int L = ss-60;
            int R = t[j]+80;
            if(ed<=L) dp[j+1] = min(dp[j+1], dp[i]+(R-L));
        }
    }

    cout << dp[n] << endl;
    return 0;
}
