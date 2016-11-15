#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

inline bool only_number(char s[])
{
    int len=strlen(s);
    rep(i,len)
    {
        if(!('0'<=s[i]&&s[i]<='9')) return false;
    }
    return true;
}

int main()
{
    char f[]="Fizz", b[]="Buzz", fb[]="FizzBuzz";
    int m,n;
    char s[25];
    while(scanf(" %d %d", &m, &n),m)
    {
        list<int> player;
        rep(i,m) player.pb(i+1);

        auto itr=player.begin();
        bool only_one=false;
        for(int i=1; i<=n; ++i)
        {
            scanf(" %s", s);

            if(only_one) continue;

            bool valid=false;
            if(i%15==0)
            {
                if(strcmp(s,fb)==0) valid=true;
            }
            else if(i%3==0)
            {
                if(strcmp(s,f)==0) valid=true;
            }
            else if(i%5==0)
            {
                if(strcmp(s,b)==0) valid=true;
            }
            else
            {
                if(only_number(s) && atoi(s)==i) valid=true;
            }

            if(!valid) itr=player.erase(itr);
            else ++itr;

            if(itr==player.end()) itr=player.begin();

            if(!only_one && player.size()==1) only_one=true;
        }

        bool F=true;
        each(ITR,player)
        {
            if(!F) printf(" ");
            printf("%d", *ITR);
            F=false;
        }
        printf("\n");
    }
    return 0;
}
