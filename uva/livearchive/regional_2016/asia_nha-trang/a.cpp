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

int solve(){
    int n,m;
    scanf(" %d %d", &n, &m);

    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);
    // dbg(a);
    vector<int> idx;
    rep(i,n)if(a[i]==m) idx.pb(i);
    // dbg(idx);
    int ans = 0;
    for(int i:idx){
        int l=i-1,r=i+1;
        while(l>=0 && a[l]>m) --l;
        while(r<n && a[r]>m) ++r;

        int t=0;
        for(int j=l+1; j<r; ++j) t+=a[j];
        ans = max(ans,t);
    }
    return ans;
}

int main(){
    int T;
    scanf(" %d", &T);
    while(T--) printf("%d\n", solve());
    return 0;
}
