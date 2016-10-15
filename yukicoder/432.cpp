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
    int T;
    cin >>T;
    while(T--)
    {
        string s;
        cin >>s;

        int n=s.size();
        vector<int> a(n);
        rep(i,n) a[i]=s[i]-'0';

        int C=n-1;
        while(C--)
        {
            vector<int> t(n);
            rep(i,n-1)
            {
                int v=a[i]+a[i+1];
                if(v>=10) v=1+v%10;
                t[i]=v;
                // printf("t[%d]=%d\n", i,t[i]);
            }
            a=t;
        }
        cout << a[0] << endl;
    }
    return 0;
}
