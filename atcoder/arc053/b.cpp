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
    string s;
    cin >>s;

    int n=s.size();

    int ct[26]={0};
    rep(i,n) ++ct[s[i]-'a'];

    vector<int> odd,even;
    rep(i,26)
    {
        if(ct[i]%2==1) odd.pb(i);
        else if(ct[i]%2==0 && ct[i]>0) even.pb(i);
    }

    int ans=1;

    int num=odd.size();

    if(num<=1) ans=n;
    else
    {
        int r=n-num;
        if(r%2==0)
        {
            r/=2;
            r/=num;
            ans=1+2*r;
        }
        else ans=1;
    }

    printf("%d\n", ans);
    return 0;
}
