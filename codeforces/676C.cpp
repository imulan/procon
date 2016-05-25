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
    int n,k;
    string s;

    cin >>n >>k;
    cin >>s;

    int ans=k;

    int st=0;
    int ct=0;
    rep(i,n)
    {
        if(s[i]=='b')
        {
            ++ct;
            if(ct>k)
            {
                ans=max(ans,i-st);

                while(s[st]=='a') ++st;
                ++st;
                --ct;
            }
        }
    }
    ans=max(ans,n-st);

    st=0;
    ct=0;
    rep(i,n)
    {
        if(s[i]=='a')
        {
            ++ct;
            if(ct>k)
            {
                ans=max(ans,i-st);

                while(s[st]=='b') ++st;
                ++st;
                --ct;
            }
        }
    }
    ans=max(ans,n-st);

    cout << ans << endl;
    return 0;
}
