#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl;

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);

    vector<int> deg(n);
    vector<int> a(m),b(m);
    rep(i,m){
        scanf(" %d %d", &a[i], &b[i]);
        --a[i];
        --b[i];
        ++deg[a[i]];
        ++deg[b[i]];
    }

    int idx = -1;
    int min_deg=n+1;
    rep(i,n){
        if(deg[i] < min_deg){
            min_deg = deg[i];
            idx = i;
        }
    }

    vector<int> ans(n,1);
    ans[idx] = 0;
    rep(i,m){
        if(a[i]==idx) ans[b[i]] = 0;
        if(b[i]==idx) ans[a[i]] = 0;
    }

    rep(i,n) printf("%d%c", ans[i], " \n"[i==n-1]);
    return 0;
}