#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int check(string t)
{
    int n=t.size();
    int ret=0;
    int idx=0;
    while(idx<n-1)
    {
        if(t[idx]=='2' && t[idx+1]=='5')
        {
            int ct=1;
            idx+=2;
            while(idx<n-1)
            {
                if(t[idx]=='2' && t[idx+1]=='5')
                {
                    ++ct;
                    idx+=2;
                }
                else break;
            }
            ret = max(ret,ct*2);
        }
        else ++idx;
    }
    return ret;
}

int main()
{
    string t;
    cin >>t;

    int n=t.size();
    string a=t, b=t;
    rep(i,n)
    {
        if(t[i]=='?')
        {
            if(i%2==0)
            {
                a[i]='2';
                b[i]='5';
            }
            else
            {
                a[i]='5';
                b[i]='2';
            }
        }
    }

    cout << max(check(a),check(b)) << endl;
    return 0;
}
