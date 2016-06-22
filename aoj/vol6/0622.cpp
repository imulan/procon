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

typedef pair<ll,int> p;

const ll INF=3003003003003003003LL;

int main()
{
    int n,q;
    ll t;
    cin >>n >>t >>q;

    vector<p> a(n);
    rep(i,n) cin >>a[i].fi >>a[i].se;

    vector<ll> ans(n,INF);

    //西に行き続ける
    int st=0;
    while(st<n && a[st].se==2)
    {
        ans[st]=a[st].fi-t;
        ++st;
    }

    //東に行き続ける
    int ed=n-1;
    while(ed>=0 && a[ed].se==1)
    {
        ans[ed]=a[ed].fi+t;
        --ed;
    }

    while(st<ed)
    {
        int x=st;
        while(x+1<n && a[x+1].se==1) ++x;
        int y=x;
        while(y+1<n && a[y+1].se==2) ++y;
        //printf(" %d %d %d\n", st,x,y);

        //まずxとx+1が衝突するかどうか調べる
        bool meet=(a[x+1].fi-t < a[x].fi+t);
        if(meet)
        {
            ll point=a[x].fi+(a[x+1].fi-a[x].fi)/2;
            for(int i=st; i<=x; ++i) ans[i]=min(point,a[i].fi+t);
            for(int i=x+1; i<=y; ++i) ans[i]=max(point,a[i].fi-t);
        }
        else
        {
            for(int i=st; i<=y; ++i)
            {
                if(a[i].se==1) ans[i]=a[i].fi+t;
                else ans[i]=a[i].fi-t;
            }
        }

        st=y+1;
    }

    //answer
    rep(i,q)
    {
        int x;
        cin >>x;
        cout << ans[x-1] << endl;
    }

    return 0;
}
