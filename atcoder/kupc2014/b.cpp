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

const int N = 1000;

bool query(int x)
{
    printf("? %d\n", x); fflush(stdout);
    char judge[2]; scanf(" %s", judge);
    return judge[0]=='Y';
}

int main()
{
    vector<int> p;
    bool prime[N+1];
    fill(prime,prime+N+1,true);
    prime[0]=prime[1]=false;
    for(int i=2; i<=N; ++i)
    {
        if(prime[i]) for(int j=2*i; j<=N; j+=i) prime[j] = false;
    }

    rep(i,N+1)if(prime[i]) p.pb(i);

    int ans = 1;
    for(int i:p)if(query(i))
    {
        int j = i*i;
        while(j<=1000 && query(j)) j*=i;
        ans *= (j/i);
    }
    printf("! %d\n", ans);
    return 0;
}
