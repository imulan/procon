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
    int n,r;
    scanf(" %d %d", &n, &r);

    vector<int> x(n);
    rep(i,n) scanf(" %d", &x[i]);
    sort(all(x));
    x.erase(unique(all(x)), x.end());
    n = x.size();

    for(int i=1; i<n; ++i){
        int w = i*r;
        if(x[n-1-i]<=w) return i;
    }
    return n;
}

int main(){
    int q;
    scanf(" %d", &q);
    while(q--) printf("%d\n", solve());
    return 0;
}
