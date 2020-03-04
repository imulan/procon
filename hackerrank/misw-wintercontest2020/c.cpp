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

const int N = 5000000;
bool prime[N];
vector<int> p;

int main(){
    fill(prime,prime+N,true);
    prime[0] = prime[1] = false;
    for(int i=2; i<N; ++i)if(prime[i]){
        for(int j=2*i; j<N; j+=i) prime[j] = false;
    }
    rep(i,N)if(prime[i]) p.pb(i);

    const int P = p.size();
    vector<ll> s(P+1);
    rep(i,P) s[i+1] = s[i]+p[i];

    int q;
    scanf(" %d", &q);
    while(q--){
        int a,b;
        scanf(" %d %d", &a, &b);
        printf("%lld\n", s[b]-s[a-1]);
    }
    return 0;
}
