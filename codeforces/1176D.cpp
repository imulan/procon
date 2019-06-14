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

const int N = 3000000;
bool prime[N];
vector<int> p;

int second_greatest_divisor(int x){
    assert(!prime[x]);
    for(int i=2; i*i<=x; ++i){
        if(x%i==0) return x/i;
    }
}

int ct[N];

int main(){
    fill(prime, prime+N, true);
    prime[0] = prime[1] = false;
    for(int i=2; i<N; ++i){
        if(prime[i]) for(int j=2*i; j<N; j+=i) prime[j] = false;
    }

    p.pb(0);
    rep(i,N)if(prime[i]) p.pb(i);

    int n;
    scanf(" %d", &n);
    rep(i,2*n){
        int b;
        scanf(" %d", &b);
        ++ct[b];
    }

    vector<int> a;
    for(int i=N-1; i>0; --i)if(!prime[i] && ct[i]){
        int d = second_greatest_divisor(i);
        while(ct[i]){
            a.pb(i);
            --ct[i];
            --ct[d];
        }
    }

    rep(i,N)if(prime[i]){
        while(ct[i]){
            a.pb(i);
            --ct[i];
            --ct[p[i]];
        }
    }

    assert(a.size() == n);
    rep(i,n) printf("%d%c", a[i], " \n"[i==n-1]);
    return 0;
}
