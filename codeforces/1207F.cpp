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

const int B = 708;
const int N = 500000;

ll a[N+1];
ll b[B][B];

int main(){
    int q;
    scanf(" %d", &q);
    while(q--){
        int t,x,y;
        scanf(" %d %d %d", &t, &x, &y);
        if(t==1){
            a[x] += y;
            for(int i=1; i<B; ++i) b[i][x%i] += y;
        }
        else{
            ll ans = 0;
            if(x<B) ans = b[x][y];
            else{
                for(int i=y; i<=N; i+=x) ans += a[i];
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}
