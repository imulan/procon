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
    string n;
    cin >>n;

    int N=n.size();

    int ct[2]={0};
    rep(i,N) ct[(i+1)%2] += n[N-1-i]-'0';

    printf("%d %d\n", ct[0], ct[1]);
    return 0;
}
