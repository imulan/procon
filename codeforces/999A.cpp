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

int main(){
    int n,k;
    cin >>n >>k;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    int l=0;
    while(l<n && a[l]<=k) ++l;

    int r=n-1;
    while(r>=0 && a[r]<=k) --r;

    int ans = l + n-1-r;
    if(l==n) ans = n;
    cout << ans << endl;
    return 0;
}
