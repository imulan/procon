#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main()
{
    string s;
    cin >>s;

    int S=s.size();
    while(S>0 && s[S-1]=='0') --S;

    if(S==0)
    {
        cout << 0 << endl;
        return 0;
    }

    int ans=1;
    int f=1;
    for(int i=S-1; i>=0; --i)
    {
        if(f==1 && s[i]=='0')
        {
            ++ans;
            f=0;
        }

        if(f==0 && s[i]=='1')
        {
            ++ans;
            f=1;
        }
    }

    cout << ans << endl;
    return 0;
}
