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

int n;

const int N = 51;
ll s[N],p[N];

ll dfs(int lv, ll &r){
    if(r<=0) return 0;

    if(s[lv]<=r){
        r -= s[lv];
        return p[lv];
    }

    ll ret = 0;
    --r;

    ret += dfs(lv-1,r);
    if(r<=0) return ret;

    --r;
    ++ret;

    ret += dfs(lv-1,r);

    --r;
    return ret;
}

int main(){
    s[0] = 1;
    p[0] = 1;
    for(int i=1; i<N; ++i){
        s[i] = 2*s[i-1] + 3;
        p[i] = 2*p[i-1] + 1;
    }

    ll x;
    cin >>n >>x;
    cout << dfs(n,x) << endl;
    return 0;
}
