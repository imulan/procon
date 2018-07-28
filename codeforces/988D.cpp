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

void solve(){
    const int P = 32;
    ll pw[P];
    pw[0] = 1;
    rep(i,P-1) pw[i+1] = pw[i]*2;

    int n;
    scanf(" %d", &n);

    vector<ll> x(n);
    rep(i,n) scanf(" %lld", &x[i]);
    sort(all(x));

    set<ll> s;
    rep(i,n) s.insert(x[i]);

    // 3つ
    rep(i,n){
        rep(j,P){
            ll y = x[i]-pw[j], z = x[i]+pw[j];
            if(s.count(y) && s.count(z)){
                printf("3\n%lld %lld %lld\n", x[i],y,z);
                return;
            }
        }
    }

    // 2つ
    rep(i,n){
        rep(j,P){
            for(int k:{-1,1}){
                ll y = x[i]+k*pw[j];
                if(s.count(y)){
                    printf("2\n%lld %lld\n", x[i],y);
                    return;
                }
            }
        }
    }

    // 1つ
    printf("1\n%lld\n",x[0]);
}

int main(){
    solve();
    return 0;
}
