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
    int n,a,b;
    string s;
    cin >>n >>a >>b >>s;

    int x=0,y=0;
    rep(i,n)
    {
        if(s[i]=='a')
        {
            if(x+y<a+b)
            {
                printf("Yes\n");
                ++x;
            }
            else printf("No\n");
        }
        else if(s[i]=='b')
        {
            if(x+y<a+b && y<b)
            {
                printf("Yes\n");
                ++y;
            }
            else printf("No\n");
        }
        else printf("No\n");
    }

    return 0;
}
