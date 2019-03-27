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

int main(){
    int n;
    cin >>n;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    map<int,vector<pi>> m;
    rep(i,n){
        int now = 0;
        for(int j=i; j<n; ++j){
            now += a[j];
            m[now].pb({j,i});
        }
    }

    vector<pi> ans;
    for(const auto &p:m){
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        for(pi range:p.se) pq.push(range);

        vector<pi> t;
        while(!pq.empty()){
            pi c = pq.top();
            pq.pop();
            t.pb(c);

            while(!pq.empty()){
                pi nx = pq.top();
                if(nx.se <= c.fi) pq.pop();
                else break;
            }
        }

        if(ans.size() < t.size()) ans = t;
    }

    cout << ans.size() << '\n';
    for(const auto &p:ans) cout << p.se+1 << " " << p.fi+1 << '\n';
    return 0;
}
