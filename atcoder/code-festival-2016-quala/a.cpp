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
    string s;
    cin >>s;

    rep(i,4) printf("%c", s[i]);
    printf(" ");
    for(int i=4; i<s.size(); ++i) printf("%c", s[i]);
    printf("\n");

    return 0;
}
