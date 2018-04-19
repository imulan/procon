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
const int M = 1<<12;
bool dp[N][M]={};

using pi = pair<int,int>;
vector<pi> Q[N];

int main(){
    string s;
    cin >>s;

    int n = s.size();

    // finally len(s) becomes F
    int F = n;

    int m = 0;
    while(1){
        int sub = 1<<m;
        if(F - sub <= 0) break;
        F -= sub;
        ++m;
    }

    // calcurate prefix lemgth for states
    rep(i,n)rep(mask,1<<m){
        int L = i;
        rep(j,m)if(mask>>j&1) L -= (1<<j);
        if(0<=L && L<F) Q[L].pb({i,mask});
    }

    dp[0][0] = true;

    string ans = "";
    // decide ans[i]
    rep(i,F){
        // propagete dp state
        for(const auto &p: Q[i]){
            int idx = p.fi, mask = p.se;
            if(!dp[idx][mask]) continue;

            // erase operateion
            rep(j,m)if(!(mask>>j&1)){
                int nidx = idx+(1<<j);
                int nmask = mask|(1<<j);
                dp[nidx][nmask] = true;
            }
        }

        // decide answer
        char c = 'z';
        for(const auto &p: Q[i])if(dp[p.fi][p.se]) c = min(c, s[p.fi]);
        ans += c;

        // propagete to next state
        for(const auto &p: Q[i])if(dp[p.fi][p.se]){
            if(c == s[p.fi]) dp[p.fi+1][p.se] = true;
        }
    }

    cout << ans << endl;
    return 0;
}
