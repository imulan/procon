#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

string solve()
{
    string NG="NO", OK="YES";


    int n;
    cin >>n;

    vector<int> t(n);
    vector<string> d(n);
    rep(i,n) cin >>t[i] >>d[i];

    int h=0;
    rep(i,n)
    {
        if(h==0)
        {
            if(d[i]!="South") return NG;

            if(h+t[i]>20000) return NG;
            h+=t[i];
        }
        else if(h==20000)
        {
            if(d[i]!="North") return NG;

            if(h-t[i]<0) return NG;
            h-=t[i];
        }
        else
        {
            if(d[i]=="South")
            {
                if(h+t[i]>20000) return NG;
                h+=t[i];
            }
            else if(d[i]=="North")
            {
                if(h-t[i]<0) return NG;
                h-=t[i];
            }
        }
    }

    if(h==0) return OK;
    return NG;
}

int main()
{
    cout << solve() << endl;
    return 0;
}
