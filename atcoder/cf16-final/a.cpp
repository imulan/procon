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
    int h,w;
    cin >>h >>w;
    string s[26][26];
    rep(i,h)rep(j,w) cin >>s[i][j];

    rep(i,h)rep(j,w)
    {
        if(s[i][j]=="snuke")
        {
            printf("%c%d\n", j+'A',i+1);
            break;
        }
    }

    return 0;
}
