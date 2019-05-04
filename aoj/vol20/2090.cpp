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

using pi = pair<int,int>;
const int INF = 101010;

string LCS(const string &x, const string &y){
    int X = x.size(), Y = y.size();

    vector<vector<int>> dp(X+1, vector<int>(Y+1,-INF));
    vector<vector<pi>> par(X+1, vector<pi>(Y+1));

    dp[0][0] = 0;
    rep(i,X+1)rep(j,Y+1){
        if(i<X && j<Y && x[i]==y[j]){
            if(dp[i+1][j+1] < dp[i][j]+1){
                dp[i+1][j+1] = dp[i][j]+1;
                par[i+1][j+1] = {-1,-1};
            }
        }
        if(i<X){
            if(dp[i+1][j] < dp[i][j]){
                dp[i+1][j] = dp[i][j];
                par[i+1][j] = {-1,0};
            }
        }
        if(j<Y){
            if(dp[i][j+1] < dp[i][j]){
                dp[i][j+1] = dp[i][j];
                par[i][j+1] = {0,-1};
            }
        }
    }

    string ret = "";
    int px = X, py = Y;
    while(px!=0 || py!=0){
        pi p = par[px][py];
        if(p == pi(-1,-1)) ret += x[px-1];
        px += p.fi;
        py += p.se;
    }
    reverse(all(ret));
    return ret;
}

int main(){
    string s;
    while(cin >>s,(s!="#END")){
        int n = s.size();

        string ans = "";
        for(int i=1; i<n; ++i){
            string F = s.substr(0,i), R = s.substr(i);
            string t = LCS(F,R);
            if(t.size() > ans.size()) ans = t;
        }

        cout << ans << "\n";
    }
    return 0;
}
