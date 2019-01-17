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

int euler_phi(int n){
    if(n==0) return 0;
    int ret = n;
    for(int i=2; i*i<=n; ++i){
        if(n%i==0){
            ret -= ret/i;
            while(n%i==0) n/=i;
        }
    }
    if(n!=1) ret -= ret/n;
    return ret;
}

const int N = 1000010;
ll a[N];

int main(){
    a[1] = 2;
    for(int i=2; i<N; ++i) a[i] = a[i-1]+euler_phi(i);

    int t;
    scanf(" %d", &t);
    while(t--){
        int n;
        scanf(" %d", &n);
        printf("%lld\n", a[n]);
    }
    return 0;
}
