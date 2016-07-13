#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

const int N=700;

int main()
{
    int n;
    cin >>n;

    //2つの和がiになる組み合わせ
    ll a2[N]={0};
    rep(i,n+1)rep(j,n+1) ++a2[i+j];

    //4つの和がiになる組み合わせ
    ll a4[N]={0};
    rep(i,6*n+1)rep(j,i+1) a4[i]+=a2[j]*a2[i-j];

    //8つの和が6*nになる組み合わせ
    ll ans=0;
    rep(i,6*n+1) ans+=a4[i]*a4[6*n-i];

    cout << ans << endl;
    return 0;
}
