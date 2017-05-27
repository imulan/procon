#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const string OK="Valid",NG="Invalid";

string solve()
{
    int n;
    string s;
    cin >>n >>s;

    int f=0;
    rep(i,n)
    {
        if(s[i]=='H')
        {
            if(f==1) return NG;
            f=1;
        }
        if(s[i]=='T')
        {
            if(f==0) return NG;
            f=0;
        }
    }

    return f?NG:OK;
}

int main()
{
    int R;
    cin >>R;
    while(R--) cout << solve() << endl;
    return 0;
}
