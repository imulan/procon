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

typedef bitset<200> v;
typedef vector<v> mat;

int det(mat a)
{
    int n=a.size();
    int ret=1;

    rep(i,n)
    {
        int pv=i;
        while(pv<n && !a[pv][i]) ++pv;

        if(pv==n) return 0;

        swap(a[pv],a[i]);

        ret*=a[i][i];
        for(int j=i+1; j<n; ++j)
        {
            if(a[j][i]) a[j]^=a[i];
        }
    }

    return ret;
}

int main()
{
    int n;
    cin >>n;
    vector<string> s(n);
    rep(i,n) cin >>s[i];

    mat a(n);
    rep(i,n)rep(j,n) a[i][j]=s[i][j]-'0';

    string ans="Even";
    if(det(a)) ans="Odd";
    cout << ans << endl;

    return 0;
}
