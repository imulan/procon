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

const int ALP = 26;

const int N = 1010;
int dp[N][1<<12];

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    int hp_i, hp_m;
    while(cin >>hp_i >>hp_m, hp_i){
        int h,w;
        cin >>h >>w;
        vector<string> s(h);
        rep(i,h) cin >>s[i];

        int T;
        cin >>T;
        vector<int> trap(ALP,0);
        rep(i,T){
            char c;
            int d;
            cin >>c >>d;
            trap[c-'A'] = d;
        }

        int S;
        cin >>S;
        vector<int> damage;
        int px = 0, py = 0;
        rep(i,S){
            char c;
            int d;
            cin >>c >>d;
            while(d--){
                if(c=='U') --py;
                if(c=='D') ++py;
                if(c=='L') --px;
                if(c=='R') ++px;
                damage.pb(trap[s[py][px]-'A']);
            }
        }

        int P;
        cin >>P;
        vector<int> p(P);
        rep(i,P) cin >>p[i];

        int SZ = damage.size();
        memset(dp,0,sizeof(dp));
        dp[0][0] = hp_i;
        rep(i,SZ)rep(mask,1<<P)if(dp[i][mask]>0){
            // move
            dp[i+1][mask] = max(dp[i+1][mask], dp[i][mask]-damage[i]);

            // use potion
            rep(j,P)if(!(mask>>j&1)){
                int nmask = mask | (1<<j);
                dp[i][nmask] = max(dp[i][nmask], min(hp_m, dp[i][mask]+p[j]) );
            }
        }

        string ans = "NO";
        if(dp[SZ][(1<<P)-1]>0) ans = "YES";
        cout << ans << endl;
    }
    return 0;
}
