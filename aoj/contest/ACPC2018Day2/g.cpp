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

// const int R = 5;
const int R = 320;

ll add[R][R]={};

const int N = 100010;
ll p[N];

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);


    ll s = 0;
    int d = 0;

    rep(i,m){
        int a,b;
        scanf(" %d %d", &a, &b);

        if(b<R){
            int val = (a+1)%b;
            rep(j,b){
                add[b][j] += val;
                (val += 1) %= b;
            }
        }
        else{
            s += a+1;
            int st = b-a-1;
            for(int j=st; j<n; j+=b) p[j] += b;

            ++d;
        }
    }

    rep(i,N-1) p[i+1] += p[i];

    vector<ll> ans(n);
    rep(i,n){
        ans[i] += s;
        s += d;
        ans[i] -= p[i];
    }
    for(int i=1; i<R; ++i){
        rep(j,n){
            ans[j] += add[i][j%i];
        }
    }

    rep(i,n) printf("%lld\n", ans[i]);
    return 0;
}
