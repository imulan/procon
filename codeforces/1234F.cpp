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

using vi = vector<int>;
using vvi = vector<vi>;

const int N = 20;
const int INF = 19191919;

int main(){
    cin.tie(0);ios::sync_with_stdio(false);

    string s;
    cin >>s;

    int n = s.size();
    vi a(n);
    rep(i,n) a[i] = s[i]-'a';

    vi r(a);
    reverse(all(r));

    auto make_mask = [&](const vi &v){
        vi dp(1<<N,INF);
        rep(i,n){
            int mask = 0;
            for(int j=i; j<min(n,i+N); ++j){
                if(mask>>v[j]&1) break;

                mask |= 1<<v[j];
                dp[mask] = min(dp[mask], j+1);
            }
        }

        vvi ret(1<<N, vi(N+1,INF));
        rep(i,1<<N) ret[i][__builtin_popcount(i)] = dp[i];

        rep(mask,1<<N){
            int L = __builtin_popcount(mask);
            rep(i,N)if(mask>>i&1){
                int nx = mask^(1<<i);
                rep(j,L) ret[mask][j] = min(ret[mask][j], ret[nx][j]);
            }
        }

        return ret;
    };

    vvi pre = make_mask(a), suf = make_mask(r);
    int ans = 1;
    rep(mask,1<<N){
        int pre_len = __builtin_popcount(mask);
        int P = pre[mask][pre_len];
        if(P == INF) continue;

        int rev = ((1<<N)-1)^mask;
        int suf_len = __builtin_popcount(rev);
        while(suf_len>0){
            if(suf[rev][suf_len] <= n-P) break;
            --suf_len;
        }

        ans = max(ans, pre_len+suf_len);
    }

    cout << ans << "\n";
    return 0;
}
