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
    string ok="YES", ng="NO";

    string s;
    cin >>s;

    int S=s.size();
    int now=S-1;

    while(now>3)
    {
        if(s[now]=='r')
        {
            if(now<5) return ng;
            if(s[now-1]!='e') return ng;

            if(s[now-2]=='m')
            {
                if(s.substr(now-6,5)=="dream") now-=7;
                else return ng;
            }
            else if(s[now-2]=='s')
            {
                if(s.substr(now-5,5)=="erase") now-=6;
                else return ng;
            }
            else return ng;
        }
        else if(s[now]=='m')
        {
            if(s.substr(now-4,5)=="dream") now-=5;
            else return ng;
        }
        else if(s[now]=='e')
        {
            if(s.substr(now-4,5)=="erase") now-=5;
            else return ng;
        }
        else return ng;
    }

    return (now==-1)?ok:ng;
}

int main()
{
    cout << solve() << endl;
    return 0;
}
