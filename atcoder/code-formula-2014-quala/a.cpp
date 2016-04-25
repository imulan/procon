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
    int a;
    cin >>a;
    
    bool valid=false;
    for(int i=1; i*i*i<=1000000; ++i)
    {
        if(i*i*i==a) valid=true;
    }
    
    string ans="NO";
    if(valid) ans="YES";
    cout << ans << endl;
    return 0;
}
