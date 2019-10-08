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

const int N = 200002;
vector<int> v[N];

int main(){
    int n,k;
    scanf(" %d %d", &n, &k);
    rep(i,n){
        int a;
        scanf(" %d", &a);

        v[a].pb(0);

        int ct = 0;
        while(a>0){
            ++ct;
            a /= 2;
            v[a].pb(ct);
        }
    }

    int ans = 19191919;
    rep(i,N)if(v[i].size() >= k){
        sort(all(v[i]));

        int t = 0;
        rep(j,k) t += v[i][j];
        ans = min(ans, t);
    }
    printf("%d\n", ans);
    return 0;
}
