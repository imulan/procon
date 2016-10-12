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
    int a[5]={5,7,5,7,7};
    while(cin >>n,n)
    {
        vector<int> w(n);
        rep(i,n)
        {
            string s;
            cin >>s;
            w[i]=s.size();
        }

        int ans=-1;
        rep(i,n)
        {
            int ct=0;

            bool valid=false;
            int idx=0;
            for(int j=i; j<n; ++j)
            {
                ct+=w[j];
                if(ct==a[idx])
                {
                    ++idx;
                    ct=0;
                }
                else if(ct>a[idx]) break;


                if(idx==5)
                {
                    valid=true;
                    break;
                }
            }

            if(valid)
            {
                ans=i+1;
                break;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
