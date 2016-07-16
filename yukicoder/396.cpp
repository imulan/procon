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

int n,m;

int classnum(int a)
{
    --a;

    int r=a%(2*m);
    if(r>=m) r=2*m-1-r;

    return r+1;
}

int main()
{
    cin >>n >>m;

    int x,y;
    cin >>x >>y;

    string ans="NO";
    if(classnum(x)==classnum(y)) ans="YES";
    cout << ans << endl;
    return 0;
}
