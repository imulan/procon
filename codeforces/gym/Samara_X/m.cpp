#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define pb push_back

using pi = pair<int,int>;

int main(){
    int n;
    cin >>n;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    ll sa = 0;
    rep(i,n) sa += a[i];

    if(sa>=n){
        cout << "NO" << "\n";
        return 0;
    }

    vector<pi> p(n);
    rep(i,n) p[i] = {a[i],i};
    sort(all(p));

    queue<int> que;
    vector<pi> ans;
    rep(i,n){
        int kill = p[i].fi, idx = p[i].se;
        while(kill>0 && !que.empty()){
            int v = que.front();
            que.pop();
            --kill;
            ans.pb({idx,v});
        }

        if(kill>0){
            cout << "NO" << "\n";
            return 0;
        }
        que.push(idx);
    }

    cout << "YES" << "\n";
    for(const auto &x:ans) cout << x.fi+1 << " " << x.se+1 << "\n";
    return 0;
}