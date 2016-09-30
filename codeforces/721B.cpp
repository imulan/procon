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
    int n,k;
    cin >>n >>k;
    vector<string> p(n);
    rep(i,n) cin >>p[i];
    string c;
    cin >>c;

    int ct[101]={0};
    rep(i,n) ct[p[i].size()]++;

    int C=c.size();
    int x=0;
    rep(i,C) x+=ct[i];

    int a,b;
    a = x+1+x/k*5;
    b = x+ct[C]+(x+ct[C]-1)/k*5;

    printf("%d %d\n",a,b);
    return 0;
}
