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

const int N = 12, TT = 5000;
bool dp[1<<N];
int len[1<<N];
bool match[N][TT];

int main(){
    int n,m;
    while(cin >>n >>m,n){
        vector<string> s(n);
        rep(i,n) cin >>s[i];

        string t="";
        while(m--){
            string tmp;
            cin >>tmp;
            t += tmp;
        }

        vector<int> sz(n);
        int S = 0;
        rep(i,n){
            sz[i] = s[i].size();
            S += sz[i];
        }
        int T = t.size();
        // S <= 240, T <= 5000

        rep(mask,1<<n){
            len[mask] = 0;
            rep(i,n)if(mask>>i&1) len[mask] += sz[i];
        }

        fill(match[0], match[N], false);
        rep(i,n){
            rep(j,T-sz[i]+1){
                match[i][j] = (s[i] == t.substr(j,sz[i]));
            }
        }

        int ans = 0;
        rep(i,T-S+1){
            fill(dp,dp+(1<<N),false);
            dp[0] = true;
            rep(mask,1<<n)if(dp[mask]){
                rep(j,n)if(!(mask>>j&1)){
                    int nx = mask | (1<<j);
                    if(match[j][i+len[mask]]) dp[nx] = true;
                }
            }

            if(dp[(1<<n)-1]) ++ans;
        }
        cout << ans << endl;
    }
    return 0;
}
