#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using pi = pair<int,int>;

int main(){
    int n;
    scanf(" %d", &n);

    vector<pi> f(n);
    rep(i,n){
        int a,b;
        scanf(" %d %d", &a, &b);
        f[i] = {b,a};
    }

    sort(all(f));

    int p = 0;
    vector<int> ans;
    rep(i,n){
        swap(f[i].se,f[i].fi);

        if(f[i].fi<=p && p<=f[i].se) continue;

        p = f[i].se;
        ans.pb(p);
    }

    int k = ans.size();
    printf("%d\n",k);
    rep(i,k) printf("%d%c", ans[i], " \n"[i==k-1]);
    return 0;
}