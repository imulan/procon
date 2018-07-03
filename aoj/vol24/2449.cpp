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
    int r,c;
    cin >>r >>c;
    vector<string> s(r);
    vector<int> L(r);
    rep(i,r){
        cin >>s[i];
        L[i] = s[i].size();
    }

    int U = (1<<c)-1;
    vector<int> cm(c), pm(c);
    rep(i,c){
        rep(j,i) cm[i] |= (1<<j);
        pm[i] = cm[i]^U;
    }

    vector<int> dp(1<<c, -INF);
    dp[0] = 0;
    rep(i,r)rep(j,c){
        int nr = i;
        int nc = j+1;
        if(nc == c){
            ++nr;
            nc = 0;
        }

        vector<int> nx(1<<c,-INF);
        rep(mask,1<<c)if(dp[mask]>=0){
            // printf(" %d %d %d\n",i,j,mask);
            int idx = __builtin_popcount(mask&cm[j]);
            if(idx<=L[i]){
                // not put
                int nmask = (mask<<1)&U;
                if( !(i!=nr && idx<L[i]) ) nx[nmask] = max(nx[nmask], dp[mask]);

                // put
                if(idx<L[i]){
                    nmask |= 1;

                    int add = 0;
                    // left
                    if(idx>0 && j>0 && (mask&1)) add += (s[i][idx]==s[i][idx-1]);
                    // up
                    if( (mask>>(c-1))&1 ){
                        int ct = __builtin_popcount(mask&pm[j]);
                        int pre_idx = L[i-1]-ct;
                        if(pre_idx<0) continue;

                        add += (s[i][idx]==s[i-1][pre_idx]);
                    }

                    if( !(i!=nr && idx<L[i]-1) ) nx[nmask] = max(nx[nmask], dp[mask]+add);
                }
            }
        }

        dp = nx;
    }

    int ans = 0;
    rep(i,1<<c) ans = max(ans, dp[i]);
    cout << ans*2 << endl;
    return 0;
}
