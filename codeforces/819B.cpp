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

const int N=2222222;
int m[N]={};

int main()
{
    int n;
    scanf(" %d", &n);
    vector<int> p(n);
    rep(i,n)
    {
        scanf(" %d", &p[i]);
        --p[i];
    }

    int k=0;
    ll ans = 0;

    int P=0,M=0;
    vector<int> d(n);
    rep(i,n)
    {
        d[i] = p[i]-i;
        ans+=abs(d[i]);

        if(d[i]>=0) ++P;
        else
        {
            ++M;
            ++m[-d[i]];
        }
    }

    ll t = ans;
    rep(i,n-1)
    {
        int e = d[i]+i;

        t -= e;
        --P;

        // printf("P,M %d %d\n", P,M);

        t += P;
        t -= M;

        t += abs(p[i]-(n-1));

        // printf(" t= %lld %d\n", t,i+1);

        if(t<ans)
        {
            ans = t;
            k = i+1;
        }

        int nx = p[i]-(n-1)-i-1;
        // printf("nx %d\n", nx);
        if(nx<-(i+1))
        {
            ++M;
            ++m[-nx];
        }
        else ++P;

        M -= m[i+1];
        P += m[i+1];
    }

    if(k>0) k=n-k;
    printf("%lld %d\n",ans,k);
    return 0;
}
