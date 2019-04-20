#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int D;
int win[501];

int dfs(int x)
{
    if(win[x]>=0) return win[x];
    if(x<=5) return 0;

    int ret=0;
    for(int a=1; a<=x; ++a)
    {
        for(int b=a+1; a+b<x; ++b)
        {
            int c=x-b-a;

            if(a!=c && b!=c && max({a,b,c})-min({a,b,c})<=D)
            {
                printf(" x=%d : a,b,c %d %d %d\n", x,a,b,c);

                if(!dfs(a) && !dfs(b) && !dfs(c)) ret=1;
            }
        }
    }

    return win[x]=ret;
}

int main()
{
    int L;
    cin >>L >>D;
    memset(win,-1,sizeof(win));

    string ans="matsu";
    if(dfs(L)) ans="kado";

    cout << ans << endl;
    return 0;
}
