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

const int N = 100010;
bool prime[N+1];
vector<int> primes;

void init()
{
    fill(prime,prime+N+1,true);
    prime[0]=prime[1]=false;
    for(int i=2; i<=N; ++i)
    {
        if(prime[i]) for(int j=2*i; j<=N; j+=i) prime[j] = false;
    }

    rep(i,N+1)if(prime[i]) primes.pb(i);
}

int main()
{
    init();

    int n;
    scanf(" %d", &n);

    vector<int> ans(n);
    rep(i,n)
    {
        if(prime[i+2]) ans[i]=1;
        else ans[i]=2;
    }

    printf("%d\n", *max_element(all(ans)));
    rep(i,n) printf("%d%c", ans[i],(i==n-1?'\n':' '));
    return 0;
}
