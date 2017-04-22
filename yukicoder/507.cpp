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
    int n,m;
    cin >>n >>m;

    int my;
    cin >>my;

    vector<int> a(n-1);
    rep(i,n-1) cin >>a[i];
    sort(all(a));

    int l=-1,r=n-1;
    while(r-l>1)
    {
        int t=(l+r)/2;
        int score = my + a[t];

        multiset<int> s;
        rep(i,n-1)if(i!=t) s.insert(a[i]);

        int grade=1;
        rep(i,(n-2)/2)
        {
            auto big = s.end();
            --big;

            int A = *big;
            s.erase(big);

            auto itr = s.upper_bound(score-A);

            if(itr == s.end()) break;
            s.erase(itr);
            ++grade;
        }

        if(grade<=m) r=t;
        else l=t;
    }

    if(r==n-1) r=-1;
    else r=a[r];
    cout << r << endl;
    return 0;
}
