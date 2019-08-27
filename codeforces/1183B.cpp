#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

int solve(){
    int n,k;
    scanf(" %d %d", &n, &k);
    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);
    sort(all(a));

    int mn = a[0], mx = a[n-1];
    return (mn+k < mx-k) ? -1 : (mn+k);
}

int main(){
    int q;
    scanf(" %d", &q);
    while(q--) printf("%d\n", solve());
    return 0;
}
