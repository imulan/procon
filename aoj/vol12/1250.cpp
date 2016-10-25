#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

string convert(string s)
{
    while(s.size()<8) s="0"+s;
    string ret="";
    rep(i,s.size())
    {
        int num=s[i]-'0';
        if('a'<=s[i] && s[i]<='f') num=s[i]-'a'+10;
        int a=8;
        rep(j,4)
        {
            if(num>=a)
            {
                num-=a;
                ret+="1";
            }
            else ret+="0";
            a/=2;
        }
    }
    return ret;
}

int main()
{
    ll pw[32];
    pw[0]=1;
    for(int i=1; i<32; ++i) pw[i]=pw[i-1]*2;

    int T;
    cin >>T;
    while(T--)
    {
        vector<string> s(9);
        rep(i,9)
        {
            string tmp;
            cin >>tmp;
            s[i]=convert(tmp);
        }

        string key(32,'u');
        vector<int> carry(32,0);

        for(int i=31; i>=0; --i)
        {
            int a=0;
            rep(j,8) a+=s[j][i]-'0';

            int b=a+carry[i];

            if(b%2==s[8][i]-'0') key[i]='0';
            else
            {
                key[i]='1';
                b=8-a+carry[i];
            }

            if(b%2==1) --b;

            for(int j=30; j>0; --j)
            {
                if(b<pw[j]) continue;

                b-=pw[j];
                if(i-j>=0) ++carry[i-j];
            }
        }

        ll ans=0;
        rep(i,32)
        {
            if(key[i]=='1') ans+=pw[31-i];
        }
        printf("%llx\n", ans);
    }
    return 0;
}
