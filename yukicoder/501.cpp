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
    int n,d;
    cin >>n >>d;

    string ans="";
    if(n<=d)
    {
        int b=d-n;
        rep(i,n-b) ans+="A";
        rep(i,b) ans+="B";
    }
    else
    {
        int c=n-d;
        rep(i,n-c) ans+="A";
        rep(i,c) ans+="C";        
    }

    cout << ans << endl;
    return 0;
}
