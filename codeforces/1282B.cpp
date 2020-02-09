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
    int n,p,k;
    scanf(" %d %d %d", &n, &p, &k);
    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);
    sort(all(a));

    int ans = 0;

    vector<int> s(k);
    rep(i,k) s[i] = a[i];
    rep(i,k-1) s[i+1] += s[i];
    s[k-1] = a[k-1];

    rep(i,n){
        if(i>=k) s[i%k] += a[i];
        if(s[i%k] <= p) ans = i+1;
    }
    return ans;
}

int main(){
    int t;
    scanf(" %d", &t);
    while(t--) printf("%d\n", solve());
    return 0;
}
