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
    ll a,b;
    cin >>a >>b;

    string ans;

    if(a==0 || b==0) ans="Zero";
    else
    {//a!=0 && b!=0
        if(a>0) ans="Positive";
        else
        {
            //間に0がある
            if(b>=0) ans="Zero";
            else
            {
                ll A=abs(a), B=abs(b);
                if((A-B)%2==0) ans="Negative";
                else ans="Positive";
            }
        }
    }

    cout << ans << endl;
    return 0;
}
