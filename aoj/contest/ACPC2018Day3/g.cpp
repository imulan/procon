#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define pb push_back
#define all(x) (x).begin(),(x).end()

const int mod = 1e9+7;

const int A = 26;
vector<int> pos[A];

int n;

const int N = 2002;
int dp[N][N];
int dfs(int l, int r){
    if(l>=n || r<0) return 0;
    if(dp[l][r]>=0) return dp[l][r];

    // printf(" (%d %d)\n", l,r);
    int ret = 0;

    rep(i,26){
        auto il = lower_bound(all(pos[i]),l);
        if(il == pos[i].end()) continue;

        auto ir = upper_bound(all(pos[i]),r);
        if(ir == pos[i].begin()) continue;
        --ir;

        int nl = *il, nr = *ir;
        if(nl<=nr){
            ++ret;
            if(nl<nr){
                ++ret;
                (ret += dfs(nl+1,nr-1)) %= mod;
            }
        }
    }

    return dp[l][r] = ret;
}

int main(){
    string s;
    cin >>s;
    n = s.size();

    rep(i,n) pos[s[i]-'a'].pb(i);

    memset(dp,-1,sizeof(dp));
    cout << dfs(0,n-1) << endl;
    return 0;
}
