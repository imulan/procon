#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

using P = pair<ll,int>;

const ll INF = LLONG_MAX/3;
const int N = 200002;
ll dp[N];

int main(){
    int n,k;
    string s;
    cin >>n >>k >>s;

    vector<vector<int>> spot(n);
    rep(i,n)if(s[i]=='1'){
        int p = max(i-k,0);
        spot[p].pb(i);
    }

    fill(dp,dp+N,INF);
    dp[0] = 0;

    priority_queue<P, vector<P>, greater<P>> pq;

    rep(i,n){
        pq.push({dp[i],i});

        P p = pq.top();
        ll v = p.fi;

        dp[i+1] = min(dp[i+1], dp[i]+(i+1));

        for(int j:spot[i]){
            int nx = min(j+k,n-1);
            dp[nx+1] = min(dp[nx+1], v+(j+1));

            pq.push({dp[nx+1], nx+1});
        }

        while(!pq.empty()){
            P t = pq.top();
            if(t.se<=i){
                pq.pop();
                continue;
            }
            else break;
        }
    }

    cout << dp[n] << "\n";
    return 0;
}
