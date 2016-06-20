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
    int n,k;
    scanf(" %d %d",&n,&k);

    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    vector<int> sorted(a);
    sort(all(sorted));

    int ans=0;
    bool valid=true;

    rep(i,n)
    {
        int focus=sorted[i];

        int idx=i;
        while(idx<n)
        {
            if(a[idx]==focus) break;
            ++idx;
        }

        if((idx-i)%k!=0)
        {
            valid=false;
            break;
        }
        else
        {
            while(idx>i && idx-k>=0)
            {
                swap(a[idx],a[idx-k]);
                idx-=k;
                ++ans;
            }
        }
    }

    if(!valid) ans=-1;
    cout << ans << endl;
    return 0;
}
