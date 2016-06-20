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

//ハッシュ値を計算
int h(int x)
{
    while(1)
    {
        int t=0;
        while(x>0)
        {
            t+=x%10;
            x/=10;
        }
        x=t;

        if(x<10) break;
    }

    return x;
}

int main()
{
    const int N=200000;
    bool p[N+1];
    fill(p,p+N+1,true);
    p[0]=p[1]=false;
    for(int i=2; i<=N; ++i)
    {
        if(p[i]) for(int j=2; i*j<=N; ++j) p[i*j]=false;
    }

    int k,n;
    cin >>k >>n;

    //素数リスト
    vector<int> a;
    for(int i=k; i<=n; ++i) if(p[i]) a.pb(i);

    //ハッシュ値
    vector<int> b(a);
    rep(i,b.size()) b[i]=h(b[i]);

    //rep(i,b.size()) printf("%d: %d\n",a[i], b[i]);

    int len=0;
    int ans=a[0];

    int st=0;
    int ct[10]={0};
    rep(i,b.size())
    {
        if(ct[b[i]]>0)
        {
            int tlen=i-st;
            //printf(" %d - %d : %d\n",a[st],a[i-1],tlen);
            if(tlen>len || (tlen==len&&a[st]>ans))
            {
                len=tlen;
                ans=a[st];
            }

            while(st<i && ct[b[i]]>0)
            {
                --ct[b[st]];
                ++st;
            }
        }

        ++ct[b[i]];
    }

    int tlen=b.size()-st;
    if(tlen>len || (tlen==len&&a[st]>ans))
    {
        len=tlen;
        ans=a[st];
    }

    cout << ans << endl;
    return 0;
}
