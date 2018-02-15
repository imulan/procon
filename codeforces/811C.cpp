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

const int N = 5005;
const int INF = -19191919;

int l[N],r[N];

bool appear[N];
int dp[N];

int main(){
    int n;
    cin >>n;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    rep(i,N) l[i]=N;
    rep(i,n){
        l[a[i]] = min(l[a[i]], i);
        r[a[i]] = i;
    }

    // 左端i
    rep(i,n){
        fill(appear, appear+N, false);
        int X = 0;
        int must_l = i, must_r = i;
        // 右端j
        for(int j=i; j<n; ++j){
            int val = a[j];
            must_l = min(must_l, l[val]);
            must_r = max(must_r, r[val]);
            if(!appear[val]){
                appear[val]=true;
                X ^= val;
            }
            if(i<=must_l && must_r<=j){
                dp[j+1] = max(dp[j+1],dp[i]+X);
            }
        }

        dp[i+1] = max(dp[i+1],dp[i]);
    }
    cout << dp[n] << endl;
    return 0;
}
