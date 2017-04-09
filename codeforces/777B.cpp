#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int minimum(int n, string a, string b)
{
    int ct[10]={};
    rep(i,n) ++ct[b[i]-'0'];

    int ans=0;
    rep(i,n)
    {
        int x=a[i]-'0';

        bool found=false;
        int idx=x;
        while(idx<=9)
        {
            if(ct[idx]>0)
            {
                --ct[idx];
                found=true;
                break;
            }

            ++idx;
        }

        if(found) continue;

        ++ans;
        idx=0;
        while(idx<x)
        {
            if(ct[idx]>0)
            {
                --ct[idx];
                found=true;
                break;
            }

            ++idx;
        }

        assert(found);
    }

    return ans;
}

int maximum(int n, string a, string b)
{
    int ct[10]={};
    rep(i,n) ++ct[b[i]-'0'];

    int ans=0;
    rep(i,n)
    {
        int x=a[i]-'0';

        bool found=false;
        int idx=x+1;
        while(idx<=9)
        {
            if(ct[idx]>0)
            {
                --ct[idx];
                found=true;
                break;
            }

            ++idx;
        }

        if(found)
        {
            ++ans;
            continue;
        }

        idx=0;
        while(idx<=x)
        {
            if(ct[idx]>0)
            {
                --ct[idx];
                found=true;
                break;
            }

            ++idx;
        }

        assert(found);
    }

    return ans;
}

int main()
{
    int n;
    string a,b;
    cin >>n >>a >>b;
    cout << minimum(n,a,b) << endl;
    cout << maximum(n,a,b) << endl;
    return 0;
}
