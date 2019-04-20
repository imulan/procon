#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main(){
    string p;
    cin >>p;

    int P = p.size();

    int n;
    cin >>n;
    vector<string> ss(n);
    rep(i,n) cin >>ss[i];

    for(string s:ss){
        int S = s.size();
        vector<vector<bool>> dp(P+1,vector<bool>(S+1));
        dp[0][0] = true;
        rep(i,P){
            rep(j,S)if(dp[i][j]){
                if(p[i]=='*'){
                    dp[i][j+1] = true;
                    dp[i+1][j] = true;
                    dp[i+1][j+1] = true;
                }
                else{
                    if(j<S && p[i]==s[j]) dp[i+1][j+1] = true;
                }
            }
        }

        if(dp[P][S]) cout << s << endl;
    }

    return 0;
}


