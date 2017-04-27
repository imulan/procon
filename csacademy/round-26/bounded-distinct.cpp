#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

inline ll add(ll L, ll R, ll w)
{
    if(w<L) return 0;
    return min(w,R)-L+1;
}

int main()
{
    int n,L,R;
    cin >>n >>L >>R;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    ll ans=0;
    map<int,int> ct;
    int st=0;
    rep(i,n)
    {
        ++ct[a[i]];

        if(ct[a[i]]==2)
        {
            while(st<i)
            {
                if(ct[a[st]]==2)
                {
                    --ct[a[st]];
                    ++st;
                    break;
                }
                --ct[a[st]];
                ++st;
            }
        }
        ans+=add(L,R,i-st+1);
    }

    cout << ans << endl;
    return 0;
}
