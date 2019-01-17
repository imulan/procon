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
const int INF = INT_MAX/3;

int dist(pi p, pi q){
    return abs(p.fi-q.fi) + abs(p.se-q.se);
}

bool isnumber(string s){
    return isdigit(s[0]);
}

int main(){
    int w,h;
    while(cin >>w >>h,w){
        vector<vector<string>> s(h, vector<string>(w));
        rep(i,h)rep(j,w) cin >>s[i][j];

        int mx = 0;
        rep(i,h)rep(j,w)if(isnumber(s[i][j])) mx = max(mx, stoi(s[i][j]));

        vector<vector<pi>> pos(mx+2);
        rep(i,h)rep(j,w){
            if(isnumber(s[i][j])) pos[stoi(s[i][j])].pb({i,j});
            else if(s[i][j]=="S") pos[0].pb({i,j});
            else if(s[i][j]=="G") pos[mx+1].pb({i,j});
        }

        vector<int> dp(1,0);
        for(int i=1; i<=mx+1; ++i){
            int P = pos[i-1].size();
            int Q = pos[i].size();

            vector<int> nx(Q,INF);
            rep(j,P)rep(k,Q){
                nx[k] = min(nx[k], dp[j]+dist(pos[i-1][j], pos[i][k]));
            }

            dp = nx;
        }
        cout << dp[0] << "\n";
    }
    return 0;
}
