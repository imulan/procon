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

ll dp[1001][1001];
ll nx[1001][1001];
int calc(const vector<int> &m, const vector<int> &e){
    int d = 0;
    for(int i:e) d+=i;

    int M = m.size();

    fill(dp[0],dp[1001],0);
    rep(i,d+1) dp[i][i] = 1;

    for(int i=1; i<M; ++i){
        fill(nx[0],nx[1001],0);
        // 累計 j デス
        rep(j,d+1){
            ll sum = 0;
            rep(k,d+1) (sum += dp[j][k]) %= mod;
            ll pre = 0;

            // i番の人のデス数
            rep(k,d+1){
                if(j+k>d) break;
                (pre += dp[j][k])%=mod;

                ll add = sum;
                if(m[i]==m[i-1]) add = pre;
                (nx[j+k][k] += add) %= mod;
            }
        }
        rep(j,1001)rep(k,1001) dp[j][k]=nx[j][k];
    }

    ll ret = 0;
    rep(i,d+1) (ret+=dp[d][i])%=mod;
    return ret;
}

int main(){
    int n,m;
    cin >>n >>m;
    vector<int> a(n),b(m);
    rep(i,n) cin >>a[i];
    rep(i,m) cin >>b[i];

    ll ans = calc(a,b);
    (ans*=calc(b,a)) %= mod;
    cout << ans << endl;
    return 0;
}
