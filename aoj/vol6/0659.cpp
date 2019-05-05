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

using pi = pair<int,int>;

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);

    vector<pi> p(n);
    rep(i,n){
        int s,v;
        scanf(" %d %d", &s, &v);
        p[i] = {v,s};
    }
    sort(all(p), greater<pi>());

    vector<int> c(m);
    rep(i,m) scanf(" %d", &c[i]);
    sort(all(c), greater<int>());

    int pidx = 0, cidx = 0;
    int ans = 0;
    while(pidx<n && cidx<m){
        if(p[pidx].se <= c[cidx]){
            ++pidx;
            ++cidx;
            ++ans;
        }
        else ++pidx;
    }
    printf("%d\n", ans);
    return 0;
}
