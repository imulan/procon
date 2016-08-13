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
    string s;
    cin >>s;

    int S=s.size();
    int a=-1, b=-1;

    bool found=false;
    //2文字
    rep(i,S-1)
    {
        if(s[i]==s[i+1])
        {
            a=i+1;
            b=i+2;
            found=true;
            break;
        }
    }

    if(!found)
    {
        //3文字
        rep(i,S-2)
        {
            if(s[i]==s[i+2])
            {
                a=i+1;
                b=i+3;
                found=true;
                break;
            }
        }
    }

    printf("%d %d\n",a,b);
    return 0;
}
