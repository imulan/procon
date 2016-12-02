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

    int w_idx=0;
    while(s[w_idx]=='c') ++w_idx;

    int S=s.size();
    cout << min(w_idx-1, S-w_idx) << endl;
    return 0;
}
