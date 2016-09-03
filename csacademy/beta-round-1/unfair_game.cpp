#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const ll INF=123456789012345LL;

int main()
{
    int n;
    scanf(" %d", &n);
    vector<ll> a(n);
    rep(i,n) scanf(" %lld", &a[i]);

    sort(all(a), greater<ll>());

    //大きい方から選んでいくのが最善

    //負の値は数列a内のどこから始まっているか
    int neg_idx=0;
    while(neg_idx<n && a[neg_idx]>=0) ++neg_idx;

    ll ans = -INF;
    if(neg_idx==0)
    {
        //集合の要素が全て負の時
        //初手は1つか2つ
        ll one=0, two=0;

        one=a[0];
        for(int i=2; i<n; i+=2) one+=a[i];
        ans=max(ans,one);

        if(n>=2)
        {
            two=a[0]+a[1];
            for(int i=3; i<n; i+=2) two+=a[i];
            ans=max(ans,two);
        }
    }
    else
    {
        //非負の要素をすべて選ぶか、負の値を1つだけ選ぶ
        ll x=0, y=0;

        rep(i,neg_idx) x+=a[i];
        for(int i=neg_idx+1; i<n; i+=2) x+=a[i];
        ans=max(ans,x);

        if(neg_idx<n-1)
        {
            rep(i,neg_idx+1) y+=a[i];
            for(int i=neg_idx+2; i<n; i+=2) y+=a[i];
            ans=max(ans,y);
        }
    }

    cout << ans << endl;
    return 0;
}
