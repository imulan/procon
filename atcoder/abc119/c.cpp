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

const int INF = 10101010;

int n,x[3];
int l[8];

int dfs(int d, vector<int> v){
    if(d==n){
        rep(i,3)if(v[i]==0) return INF;

        int res = 0;
        rep(i,3) res += abs(x[i]-v[i]);
        return res;
    }

    // not use
    int ret = dfs(d+1,v);

    // use
    rep(i,3){
        v[i] += l[d];
        ret = min(ret, dfs(d+1,v)+10);
        v[i] -= l[d];
    }

    return ret;
}

int main(){
    cin >>n;
    rep(i,3) cin >>x[i];
    rep(i,n) cin >>l[i];

    vector<int> v(3);
    cout << dfs(0,v)-30 << "\n";
    return 0;
}
