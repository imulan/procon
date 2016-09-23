#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

string translate(string s)
{
    string ret="";
    int S=s.size();

    rep(i,18-S) ret+="0";
    rep(i,S)
    {
        if((s[i]-'0')%2==0) ret+="0";
        else ret+="1";
    }

    return ret;
}

int main()
{
    int T;
    cin >>T;

    map<string,int> ct;

    while(T--)
    {
        char op;
        string s;
        cin >>op >>s;

        string t=translate(s);

        if(op=='+')
        {
            if(ct.find(t) == ct.end()) ct[t]=0;
            ++ct[t];
        }
        else if(op=='-') --ct[t];
        else printf("%d\n", ct[t]);
    }

    return 0;
}
