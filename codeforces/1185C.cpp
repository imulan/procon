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

const int T = 101;

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);
    vector<int> t(n);
    rep(i,n) scanf(" %d", &t[i]);

    vector<int> x(T);
    rep(i,n){
        int rem = m-t[i];
        int ct = 0;
        for(int j=1; j<T; ++j){
            int num = min(x[j],rem/j);
            ct += num;
            rem -= j*num;
        }
        ++x[t[i]];

        int ans = i-ct;
        printf("%d%c", ans, " \n"[i==n-1]);
    }
    return 0;
}
