#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

string make_code(string s, int k)
{
    string ret="";
    int S=s.size();

    ret+=s[0];
    rep(i,S-1)
    {
        string vowel="aiueo";
        bool flag=false;
        rep(j,5) if(s[i]==vowel[j]) flag=true;

        if(flag) ret+=s[i+1];
    }

    if(ret.size()>k) ret=ret.substr(0,k);
    return ret;
}

int main()
{
    int n;
    while(cin >>n,n)
    {
        vector<string> s(n);
        rep(i,n) cin >>s[i];
        int ans=-1;
        for(int k=1; k<=50; ++k)
        {
            set<string> codes;
            rep(i,n) codes.insert(make_code(s[i],k));
            if(codes.size()==n)
            {
                ans=k;
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
