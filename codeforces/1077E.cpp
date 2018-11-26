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
    int n;
    scanf(" %d", &n);

    map<int,int> m;
    rep(i,n){
        int a;
        scanf(" %d", &a);
        ++m[a];
    }

    int M = 0;
    vector<pi> v;
    for(const auto &p:m){
        v.pb({p.se,M});
        ++M;
    }
    sort(all(v));

    int ans = 1;
    for(int i=1; i<=n; ++i){
        int t = i;
        pi now = {t,-1};
        int tmp = 0;
        while(1){
            auto itr = upper_bound(all(v),now);
            if(itr == v.end()) break;

            tmp += t;
            t *= 2;

            now = *itr;
            if(now.fi < t){
                now.fi = t;
                now.se = -1;
            }
        }
        ans = max(ans, tmp);
    }
    printf("%d\n", ans);
    return 0;
}
