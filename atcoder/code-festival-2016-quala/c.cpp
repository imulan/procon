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
    int k;
    cin >>s >>k;

    string t=s;

    rep(i,s.size())
    {
        int toa=(26-(t[i]-'a'))%26;

        if(k-toa>=0)
        {
            k-=toa;
            t[i]='a';
        }
    }

    if(k>0)
    {
        int T=t.size();
        int res=(t[T-1]-'a'+k)%26;
        t[T-1]=res+'a';
    }

    cout << t << endl;
    return 0;
}
