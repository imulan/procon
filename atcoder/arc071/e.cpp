#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

string s,t;

int g[9]={};
int sA[101010]={}, sB[101010]={};
int tA[101010]={}, tB[101010]={};

void query(int a, int b, int c, int d)
{
    int S=((sA[b]-sA[a-1])%3)*3+(sB[b]-sB[a-1])%3;
    int T=((tA[d]-tA[c-1])%3)*3+(tB[d]-tB[c-1])%3;

    if(g[S] == g[T]) printf("YES\n");
    else printf("NO\n");
}

int main()
{
    cin >>s >>t;

    rep(i,s.size())
    {
        sA[i+1] = sA[i]+(s[i]=='A');
        sB[i+1] = sB[i]+(s[i]=='B');
    }
    rep(i,t.size())
    {
        tA[i+1] = tA[i]+(t[i]=='A');
        tB[i+1] = tB[i]+(t[i]=='B');
    }

    g[1]=g[5]=g[6]=1;
    g[0]=g[8]=g[4]=2;
    
    int Q;
    scanf(" %d", &Q);
    while(Q--)
    {
        int a,b,c,d;
        scanf(" %d %d %d %d", &a, &b, &c, &d);
        query(a,b,c,d);
    }

    return 0;
}
