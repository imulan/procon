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

int main()
{
    int n;
    cin >>n;

    vector<int> num;
    //plus,minus
    int p=1,m=0;

    rep(i,n)
    {
        char c;
        scanf(" %c", &c);
        if(c=='+') ++p;
        else if(c=='-') ++m;
        else num.pb(c-'0');
    }
    sort(all(num));

    //作らなきゃいけない数字の個数
    int a=p+m;
    //今持っている数字カードの個数
    int b=num.size();

    //最終的に持つ数字のリスト
    vector<ll> d;

    //小さい方からa-1個取り出す
    rep(i,a-1) d.pb(num[i]);
    //大きい方から取り出してくっつける
    ll add=0;
    for(int i=b-1; i>=a-1; --i)
    {
        add=add*10+num[i];
    }
    d.pb(add);

    //max,min
    ll x=0, y=0;

    //maxの計算
    //小さい方からm個をマイナス
    rep(i,m) x-=d[i];
    for(int i=m; i<p+m; ++i) x+=d[i];

    //minの計算
    if(m>0)
    {
        //小さい方からp個をプラス
        rep(i,p) y+=d[i];
        for(int i=p; i<p+m; ++i) y-=d[i];
    }
    else
    {
        //プラスしか無い時
        //p個に割り振っていく
        vector<int> el(p);
        rep(i,b)
        {
            el[i%p]=10*el[i%p]+num[i];
        }

        rep(i,p) y+=el[i];
    }

    cout << x << " " << y << endl;
    return 0;
}
