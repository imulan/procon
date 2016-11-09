#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef vector<int> vi;

inline vi normarize(const vi &v)
{
    vector<vi> r(4);
    rep(i,4)
    {
        vi t(4);
        rep(j,4) t[j]=v[(i+j)%4];
        r[i]=t;
    }
    sort(all(r));
    return r[0];
}

inline ll DIM(const vi &v)
{
    if(v[0]==v[1] && v[1]==v[2] && v[2]==v[3]) return 4;
    if(v[0]==v[2] && v[1]==v[3]) return 2;
    return 1;
}

int main()
{
    ll P[401][5]={0};
    for(int i=1; i<=400; ++i)
    {
        P[i][1]=i;
        for(int j=2; j<=min(4,i); ++j) P[i][j]=P[i][j-1]*(i-j+1);
    }

    ll POW[5][5];
    rep(i,5)
    {
        POW[i][0]=1;
        for(int j=1; j<5; ++j) POW[i][j]=POW[i][j-1]*i;
    }

    int n;
    scanf(" %d", &n);

    vector<vi> c(n,vi(4));
    rep(i,n)rep(j,4) scanf(" %d", &c[i][j]);

    map<vi,int> ct;
    rep(i,n)
    {
        c[i]=normarize(c[i]);
        if(ct.find(c[i])==ct.end()) ct[c[i]]=1;
        else ++ct[c[i]];
    }

    ll ans=0;
    // 上面i, 下面j, 下面の向きを設定
    rep(i,n)rep(j,i)rep(k,4)
    {
        vi u(4);
        rep(x,4) u[x]=c[j][(k+x)%4];
        swap(u[1],u[3]);

        vector<vi> sides(4);
        rep(x,4)
        {
            vi t(4);
            t[0]=c[i][(x+1)%4];
            t[1]=c[i][x];
            t[2]=u[x];
            t[3]=u[(x+1)%4];
            sides[x]=normarize(t);
        }
        sort(all(sides));

        ll add=1;
        int idx=0, st=0;
        while(1)
        {
            while(idx<4 && sides[st]==sides[idx]) ++idx;
            vi key=sides[st];
            int value=idx-st;

            // 使ってないタイルのうち当てはめられる個数
            int num=ct[key];
            if(c[i]==key) --num;
            if(c[j]==key) --num;

            if(num<value)
            {
                add=0;
                break;
            }

            // 選び方、向き、位置
            add*=P[num][value]*POW[DIM(key)][value];

            if(idx==4) break;
            st=idx;
        }
        ans+=add;
    }

    // 向かい合う面の個数ぶん重複する
    cout << ans/3 << endl;
    return 0;
}
