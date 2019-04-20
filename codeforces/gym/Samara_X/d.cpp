#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define pb push_back

int main(){
    int n,x;
    cin >>n >>x;
    x = abs(x);

    vector<int> a(n);
    rep(i,n) cin >>a[i];

    int g = a[0];
    rep(i,n) g = __gcd(g,a[i]);

    string ans = "NO";
    if(x%g==0) ans = "YES";
    cout << ans << "\n";
    return 0;
}