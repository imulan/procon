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

const int INF = 10101010;

int main(){
    int cc = 0;
    int n;
    while(cin >>n,n){
        vector<string> s(n);
        vector<int> p(n),l(n);
        rep(i,n){
            cin >>s[i] >>p[i];
            l[i] = s[i].size();
        }

        string t;
        cin >>t;
        int T = t.size();

        vector<int> dp(T+1,-INF);
        dp[0] = 0;
        rep(i,T){
            rep(j,n){
                if(i+l[j] > T) continue;
                if(s[j] == t.substr(i,l[j])){
                    dp[i+l[j]] = max(dp[i+l[j]], dp[i]+p[j]);
                }
            }
        }

        int V = dp[T];
        dp = vector<int>(V+1, INF);
        dp[0] = 0;
        rep(i,V){
            rep(j,n){
                int ni = i+p[j];
                if(ni > V) continue;
                dp[ni] = min(dp[ni], dp[i]+l[j]);
            }
        }

        cout << "Case " << cc+1 << ": " << dp[V] << "\n";
        ++cc;
    }
    return 0;
}
