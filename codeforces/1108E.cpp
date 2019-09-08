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

const int INF = 19191919;

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);

    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    vector<int> l(m),r(m);
    vector<int> u;
    u.pb(0);
    u.pb(n);
    rep(i,m){
        scanf(" %d %d", &l[i], &r[i]);
        --l[i];
        --r[i];
        u.pb(l[i]);
        u.pb(r[i]+1);
    }

    sort(all(u));
    u.erase(unique(all(u)), u.end());
    int U = u.size();
    --U;

    vector<int> mn(U,INF),mx(U,-INF);
    rep(i,U){
        for(int j=u[i]; j<u[i+1]; ++j){
            mn[i] = min(mn[i], a[j]);
            mx[i] = max(mx[i], a[j]);
        }
    }

    // check x-th segment includes y-th range
    auto IN = [&](int x, int y){
        return (l[x]<=u[y] && u[y]<=r[x]);
    };

    int ans = 0;
    vector<int> b;
    rep(i,U)rep(j,U){
        int d = mx[i]-mn[j];
        vector<int> t;
        rep(k,m){
            if(!IN(k,i) && IN(k,j)){
                ++d;
                t.pb(k);
            }
        }

        if(ans < d){
            ans = d;
            b = t;
        }
    }

    int B = b.size();
    printf("%d\n%d\n", ans, B);
    rep(i,B){
        if(i) printf(" ");
        printf("%d", b[i]+1);
    }
    printf("\n");
    return 0;
}
