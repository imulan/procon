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

using pi = pair<int,int>;

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);

    vector<int> k(n);
    int sumK=0;
    rep(i,n){
        scanf(" %d", &k[i]);
        sumK += k[i];
    }

    vector<pi> v(m);
    rep(i,m){
        int d,t;
        scanf(" %d %d", &d, &t);
        v[i] = {d,t-1};
    }

    auto check = [&](int x){
        vector<int> last_sale(n);
        for(const auto &p:v)if(p.fi<=x) last_sale[p.se] = max(last_sale[p.se], p.fi);

        vector<vector<int>> sale(x+1);
        rep(i,n)if(last_sale[i]>0) sale[last_sale[i]].pb(i);

        int now = 0;
        vector<int> rem(k);
        for(int i=1; i<=x; ++i){
            ++now;
            for(int j:sale[i]){
                int buy = min(now,rem[j]);
                rem[j] -= buy;
                now -= buy;
            }
        }

        rep(i,n){
            int cost = rem[i]*2;
            if(now >= cost){
                now -= cost;
                rem[i] = 0;
            }

            if(rem[i]>0) return false;
        }return true;
    };

    int ng=0, ok=2*sumK;
    while(ok-ng>1){
        int mid = (ok+ng)/2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    printf("%d\n", ok);
    return 0;
}
