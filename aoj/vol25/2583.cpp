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
    int n;
    while(cin >>n,n)
    {
        vector<string> s(n);
        vector<int> d(n);
        rep(i,n)
        {
            cin >>s[i];

            int ct=0;
            while(s[i][ct]=='.') ++ct;

            if(ct>0)
            {
                s[i][ct-1]='+';
                rep(j,ct-1) s[i][j]=' ';
            }

            d[i]=ct;
        }


        for(int i=1; i<n; ++i)
        {
            int idx=-1;
            for(int j=i+1; j<n; ++j)
            {
                if(d[j]==d[i])
                {
                    idx=j;
                    break;
                }
                if(d[j]<d[i]) break;
            }

            if(idx>0)
            {
                for(int j=i+1; j<idx; ++j) s[j][d[i]-1]='|';
            }
        }

        rep(i,n) cout << s[i] << endl;
    }
    return 0;
}
