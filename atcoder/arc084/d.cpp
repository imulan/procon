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

int f(ll x)
{
    int a = 0;
    while(x>0)
    {
        a += x%10;
        x/=10;
    }
    return a;
}

int check(int k)
{
    if(k==1) return 1;

    int v = 1;
    int step = 0;

    vector<int> b(k,-1);

    while(b[v]<0)
    {
        b[v] = step++;

        v*=10;
        v%=k;
    }
    dbg(b);

    if(b[0]>=0) return 1;
    if(b[k-1]>=0) return 2;

    int ret = 110;
    return ret;
}

void test()
{
    for(ll i=1; i<=20; ++i)
    {
        printf(" %d: %d\n", i,check(i));
        if(i%100==0) dbg(i);

        // if(check(i)!=calc(i))
        // {
        //     printf(" ans = %d  calc = %d\n", check(i), calc(i));
        //     printf(" !!!! %d\n", i);
        //     assert(false);
        // }
    }

}

int main()
{
    test();

    ll k;
    cin >>k;


    return 0;
}
