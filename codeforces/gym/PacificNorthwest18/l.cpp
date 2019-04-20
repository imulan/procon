#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout <<#x" = "<<((x))<<endl

int main(){
    int n;
    cin >>n;
    vector<int> a(n), b(n);
    rep(i,n) cin >>a[i] >>b[i];
    for (int i = 0; i < n; ++i) {
        
    }


    int ans = -1;
    for(int i=0; i<=n; ++i){
        int ct = 0;
        rep(j,n){
            if(a[j]<=i && i<=b[j]) ++ct;
        }
        if(ct == i) ans = i;
    }
    cout << ans << endl;
    return 0;
}

