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
    int n;
    cin >>n;

    vector<int> x(n);
    rep(i,n) scanf(" %d", &x[i]);
    sort(all(x));

    int diff=x[1]-x[0];

    bool valid=true;
    if(diff==0) valid=false;
    else
    {
        for(int i=2; i<n; ++i)
        {
            if(x[i]-x[i-1]!=diff)
            {
                valid=false;
                break;
            }
        }
    }

    string ans="NO";
    if(valid) ans="YES";
    cout << ans << endl;
    return 0;
}
