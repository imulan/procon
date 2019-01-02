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

int main(){
    int r,c,q;
    while(scanf(" %d %d %d", &r, &c, &q),r){
        vector<int> a(q),b(q),o(q);
        rep(i,q) scanf(" %d %d %d", &a[i], &b[i], &o[i]);

        ll ans = 0;
        int R = r, C = c;
        vector<int> y(r,-1), x(c,-1);
        for(int i=q-1; i>=0; --i){
            if(a[i]==0){
                if(y[b[i]] != -1) continue;
                if(o[i]==1) ans += C;
                --R;
                y[b[i]] = o[i];
            }
            else{
                if(x[b[i]] != -1) continue;
                if(o[i]==1) ans += R;
                --C;
                x[b[i]] = o[i];
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
