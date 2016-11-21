#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const ll INF=12345678901234567LL;

typedef pair<ll,int> P;

inline ll ab(ll x)
{
    return (x>0)?x:-x;
}

int main()
{
    int n;
    while(scanf(" %d", &n),n)
    {
        int A=(n+1)/2, B=n-A;
        vector<ll> a(A), b(B);

        rep(i,A) scanf(" %lld", &a[i]);
        rep(i,B) scanf(" %lld", &b[i]);

        ll ans=ab(a[0]);
        int num=1;

        map<ll,int> mpa;
        for(int i=1; i<(1<<A); ++i)
        {
            ll sum=0;
            rep(j,A) if(i>>j&1) sum+=a[j];

            // Aだけ
            if(ab(sum)<ans)
            {
                ans=ab(sum);
                num=__builtin_popcount(i);
            }
            if(ab(sum)==ans && __builtin_popcount(i)<num) num=__builtin_popcount(i);

            if(mpa.find(sum)==mpa.end()) mpa[sum]=__builtin_popcount(i);
            else mpa[sum] = min(mpa[sum],__builtin_popcount(i));
        }

        for(int i=1; i<(1<<B); ++i)
        {
            ll sum=0;
            rep(j,B) if(i>>j&1) sum+=b[j];

            // Bだけ
            if(ab(sum)<ans)
            {
                ans=ab(sum);
                num=__builtin_popcount(i);
            }
            if(ab(sum)==ans && __builtin_popcount(i)<num) num=__builtin_popcount(i);

            // AとB
            map<ll,int>::iterator itr=mpa.lower_bound(-sum);

            ll tsum;
            int tnum;
            if(itr!=mpa.end())
            {
                tsum=ab(sum+itr->fi);
                tnum=__builtin_popcount(i)+itr->se;
                if(tsum<ans)
                {
                    ans=tsum;
                    num=tnum;
                }
                if(tsum==ans && tnum<num) num=tnum;
            }
            if(itr!=mpa.begin())
            {
                --itr;
                tsum=ab(sum+itr->fi);
                tnum=__builtin_popcount(i)+itr->se;
                if(tsum<ans)
                {
                    ans=tsum;
                    num=tnum;
                }
                if(tsum==ans && tnum<num) num=tnum;
            }
        }

        printf("%lld %d\n",ans,num);
    }
    return 0;
}
