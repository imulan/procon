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
using P = pair<string,pi>;

struct edge{
    int to;
    string s;
};

const int N = 450;
const string INF(N,'z');

int main(){
    int n,a,s,g;
    while(cin >>n >>a >>s >>g,n){
        vector<vector<edge>> G(n);
        rep(i,a){
            int x,y;
            string lab;
            cin >>x >>y >>lab;
            G[x].pb({y,lab});
        }

        vector<vector<string>> dp(n,vector<string>(N,INF));
        dp[s][0] = "";
        priority_queue<P,vector<P>,greater<P>> pq;
        pq.push({"",{s,0}});
        while(!pq.empty()){
            P now = pq.top();
            pq.pop();

            int v = now.se.fi, L = now.se.se;
            if(dp[v][L] > now.fi) continue;

            for(const auto &e:G[v]){
                int nv = e.to, nL = L+e.s.size();
                if(nL>=N) continue;
                string nx = dp[v][L]+e.s;
                if(dp[nv][nL] > nx){
                    dp[nv][nL] = nx;
                    pq.push({dp[nv][nL],{nv,nL}});
                }
            }
        }

        string ans = INF;
        rep(i,N) ans = min(ans, dp[g][i]);

        // rep(i,N){
        //     dbg(i);
        //     dbg(dp[g][i]);
        // }
        // dbg(ans.size());

        if(ans.size()>6*(n-1)) ans = "NO";
        cout << ans << "\n";
    }
    return 0;
}
