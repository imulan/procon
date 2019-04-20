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

const int B = 450;
const int N = 200010;

ll x[N]={};
ll add[B][B]={};

int main(){
    int n,q;
    scanf(" %d %d", &n, &q);

    while(q--){
        int t;
        scanf(" %d", &t);
        if(t==1){
            int a,b,c;
            scanf(" %d %d %d", &a, &b, &c);
            if(b<B){
                add[b][a] += c;
            }
            else{
                for(int i=a; i<=n; i+=b) x[i] += c;
            }
        }
        else{
            int d;
            scanf(" %d", &d);

            ll ans = x[d];
            for(int i=1; i<B; ++i) ans += add[i][d%i];

            printf("%lld\n", ans);
        }
    }

    return 0;
}
