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
    int n,s;
    cin >>n >>s;
    int mx = 0;
    rep(i,n){
        int t;
        cin >>t;
        mx = max(mx,t*s);
    }
    
    int ans = (mx+999)/1000;
    cout << ans << endl;
    return 0;
}

