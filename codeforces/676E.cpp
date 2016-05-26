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

const long UND = 123456;

inline ll ab(ll x)
{
    return (x>0?x:-x);
}

int main()
{
    int n,k;
    cin >>n >>k;

    //未定係数の数
    int ct=0;
    vector<long> a(n+1);
    rep(i,n+1)
    {
        string s;
        cin >>s;

        if(s=="?")
        {
            a[i]=UND;
            ++ct;
        }
        else a[i]=stol(s.c_str());
    }

    bool valid=true;
    //人間のターンか
    bool man=((n+1-ct)%2==1);

    if(k==0)
    {
        if(a[0]==UND) valid=man;
        else
        {
            if(a[0]==0) valid=true;
            else valid=false;
        }
    }
    else
    {
        //未定係数が無い時
        if(ct==0)
        {
            ll now=a[n];
            for(int i=n-1; i>=0; --i)
            {
                if(ab(now)>1000000000LL) break;
                now=now*k+a[i];
            }

            if(now==0) valid=true;
            else valid=false;
        }
        else valid=(n%2==1);
    }

    string ans="No";
    if(valid) ans="Yes";
    cout << ans << endl;

    return 0;
}
