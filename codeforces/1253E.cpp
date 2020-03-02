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

using pi = pair<int,int>;

int main(){
    int n,m;
    cin >>n >>m;
    vector<int> x(n),s(n);
    rep(i,n) cin >>x[i] >>s[i];

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    vector<int> dp(m+1,m);
    dp[0] = 0;
    for(int i=-m; i<m; ++i){
        int val = 0;
        if(i>=0) val = dp[i];
        while(!pq.empty()){
            pi t = pq.top();
            if(t.se < i) pq.pop();
            else break;
        }
        if(!pq.empty()) val = min(val,pq.top().fi);

        int L = i+1;
        rep(j,n)if(L<=x[j]){
            int l = x[j]-s[j];
            int cost = max(0,l-L);

            int R = x[j]+(x[j]-L);
            R = max(0,min(m,R));

            int nv = val+cost;
            if(dp[R] > val+cost){
                dp[R] = nv;
                pq.push({dp[R],R});
            }
        }
    }

    cout << dp[m] << "\n";
    return 0;
}
