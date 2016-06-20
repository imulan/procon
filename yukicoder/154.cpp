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

int main()
{
    int T;
    cin >>T;
    rep(times,T)
    {
        string s;
        cin >>s;

        int n=s.size();

        //明らかに不可能な例
        if(n<3)
        {
            printf("impossible\n");
            continue;
        }
        else
        {
            if(s[0]!='W' || s[n-1]!='R')
            {
                printf("impossible\n");
                continue;
            }
        }

        int w=0,g=0,r=0;
        rep(i,n)
        {
            if(s[i]=='W') ++w;
            else if(s[i]=='G') ++g;
            else ++r;
        }

        //この時だけ条件を満たす可能性がある
        if(g==r && w>=g)
        {
            bool valid=true;

            //cg,crは常にcw以下
            //cgがgになったらそれ以降wが来てはいけない
            //crがcgより多くなることはない
            int cw=0,cg=0,cr=0;
            rep(i,n)
            {
                if(s[i]=='W')
                {
                    ++cw;
                    if(cg==g)
                    {
                        valid=false;
                        break;
                    }
                }
                else if(s[i]=='G')
                {
                    ++cg;
                    if(cg>cw)
                    {
                        valid=false;
                        break;
                    }
                }
                else
                {
                    ++cr;
                    if(cr>cg || cr>cw)
                    {
                        valid=false;
                        break;
                    }
                }
            }

            if(valid) printf("possible\n");
            else printf("impossible\n");
        }
        else printf("impossible\n");
    }
    return 0;
}
