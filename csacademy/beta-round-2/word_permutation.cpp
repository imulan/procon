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
    vector<string> s(n);
    rep(i,n) cin >>s[i];

    vector<string> sorted(s);
    sort(all(sorted));

    map<string,int> mp;
    rep(i,n) mp[s[i]]=i;

    rep(i,n)
    {
        if(i) printf(" ");
        printf("%d", mp[sorted[i]]+1);
    }
    printf("\n");
    return 0;
}
