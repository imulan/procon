#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl;

const int INF = 1000010000;

int main(){
    int n;
    scanf(" %d", &n);

    int max_l = -INF;
    vector<int> l(n),r(n);
    rep(i,n){
        scanf(" %d %d", &l[i], &r[i]);
        max_l = max(max_l,l[i]);
    }

    int ans = 0;
    rep(i,n){
        if(l[i]<=max_l && max_l<=r[i]) ++ans;
    }
    printf("%d\n", ans);
    return 0;
}