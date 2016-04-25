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
    int a,b;
    cin >>a >>b;
    
    string s="xxxxxxxxxx";
    rep(i,a)
    {
        int p;
        cin >>p;
        s[p]='.';
    }
    rep(i,b)
    {
        int p;
        cin >>p;
        s[p]='o';
    }

    printf("%c %c %c %c\n",s[7],s[8],s[9],s[0]);
    printf(" %c %c %c\n",s[4],s[5],s[6]);
    printf("  %c %c\n",s[2],s[3]);
    printf("   %c\n",s[1]);
    return 0;
}
