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
    string ans[12] = {"XII", "I", "II", "III", "IIII", "V", "VI", "VII", "VIII", "IX", "X", "XI"};
    map<string,int> m;
    rep(i,12) m[ans[i]]=i;

    string s;
    int t;
    cin >>s >>t;

    int now=m[s];
    now = (now+t+1200)%12;
    cout << ans[now] << endl;
    return 0;
}
