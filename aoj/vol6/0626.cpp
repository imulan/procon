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
    int n;
    cin >>n;
    string s;
    cin >>s;

    vector<int> J(n,0), I(n,0);

    if(s[0]=='J') J[0]=1;
    for(int i=1; i<n; ++i) J[i]=J[i-1]+(s[i]=='J');

    if(s[n-1]=='I') I[n-1]=1;
    for(int i=n-2; i>=0; --i) I[i]=I[i+1]+(s[i]=='I');

    ll def=0;
    for(int i=1; i<n-1; ++i)
    {
        if(s[i]=='O') def+=(ll)J[i-1]*I[i+1];
    }

    ll add=0;
    ll t;
    string ss;

    // 先頭にJ
    t=0;
    ss = "J"+s;
    for(int i=1; i<n; ++i)
    {
        if(ss[i]=='O') t+=I[i];
    }
    add=max(add,t);

    // 末端にI
    t=0;
    ss = s+"I";
    for(int i=1; i<n; ++i)
    {
        if(ss[i]=='O') t+=J[i-1];
    }
    add=max(add,t);

    // Oの位置を全探索
    rep(i,n-1) add=max(add,(ll)J[i]*I[i+1]);

    cout << def+add << '\n';
    return 0;
}
