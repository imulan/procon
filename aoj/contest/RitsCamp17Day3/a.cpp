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
    cin >>s;

    int ct[26]={};
    rep(i,s.size()) ct[s[i]-'a']++;

    int odd=0,even=0;
    rep(i,26)
    {
        if(ct[i]>0)
        {
            if(ct[i]%2==0) ++even;
            else ++odd;
        }
    }

    printf("%d\n",odd/2);
    return 0;
}
