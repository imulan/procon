#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main()
{
    ll n[6];
    rep(i,5) cin >>n[i+1];

    ll ans=0;

    //x=5
    ans+=n[5];

    //x=4
    ans+=n[4];
    n[1] = max(0LL, n[1]-61*n[4]);

    //x=3
    ans+=n[3];

    ll a2=7*n[3];
    if(a2<=n[2])
    {
        n[2]-=a2;
        n[1]=max(0LL, n[1]-42*n[3]);
    }
    else
    {
        //1のために空いているスペース
        ll num1=(125-27)*n[3]-8*n[2];
        n[2]=0;
        n[1]=max(0LL, n[1]-num1);
    }

    //x=2
    ll num=n[2]/8;
    if(n[2]%8!=0) ++num;
    ans+=num;

    ll num1=125*num-8*n[2];
    n[1]=max(0LL, n[1]-num1);

    //x=1
    ans+=n[1]/125;
    if(n[1]%125!=0) ++ans;

    cout << ans << endl;
    return 0;
}
