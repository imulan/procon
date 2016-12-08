#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N=10000;
int l[N]={}, r[N]={};
int L=0,R=0;

// i文字目から左側で最も近い*の位置、i文字目から右側で最も近い*の位置
int astl[N], astr[N];

// ^の個数の累積和
int hat[N]={};

int main()
{
    string s;
    cin >>s;

    int S=s.size();
    rep(i,S)
    {
        if(s[i]=='(') l[L++]=i;
        else if(s[i]==')') r[R++]=i;
        else if(s[i]=='^') ++hat[i];
    }

    for(int i=1; i<N; ++i) hat[i]+=hat[i-1];

    memset(astl,-1,sizeof(astl));
    memset(astr,-1,sizeof(astr));

    if(s[0]=='*') astl[0]=0;
    for(int i=1; i<S; ++i)
    {
        if(s[i]=='*') astl[i]=i;
        else astl[i]=max(astl[i],astl[i-1]);
    }

    if(s[S-1]=='*') astr[S-1]=S-1;
    for(int i=S-2; i>=0; --i)
    {
        if(s[i]=='*') astr[i]=i;
        else
        {
            if(astr[i+1]!=-1) astr[i]=astr[i+1];
        }
    }

    ll x=0,y=0;
    rep(i,L)rep(j,R)if(l[i]<r[j])
    {
        // *の位置,間にある^の個数
        int a_pos,hats;

        // 左向き
        a_pos = astl[r[j]];
        if(a_pos!=-1)
        {
            hats = hat[a_pos] - hat[l[i]];
            if(hats>=2) ++x;
        }

        // 右向き
        a_pos = astr[l[i]];
        if(a_pos!=-1)
        {
            hats = hat[r[j]] - hat[a_pos];
            if(hats>=2) ++y;
        }
    }

    printf("%lld %lld\n", x,y);
    return 0;
}
