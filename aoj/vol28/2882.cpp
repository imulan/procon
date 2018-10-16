#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))

int main(){
    int n,l,r;
    while(cin >>n >>l >>r,n){
        vector<int> a(n);
        rep(i,n) cin >>a[i];

        auto is_uruu = [&](int x){
            rep(i,n)if(x%a[i]==0) return !(i%2);
            return !(n%2);
        };

        int ans = 0;
        for(int i=l; i<=r; ++i) ans += is_uruu(i);
        cout << ans << endl;
    }
    return 0;
}
