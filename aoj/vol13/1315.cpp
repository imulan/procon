#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pi;

int convert(string date, string time)
{
    int d[12]={31,28,31,30,31,30,31,31,30,31,30,31};

    int month=atoi(date.substr(0,2).c_str());
    int day=atoi(date.substr(3,2).c_str());
    int hour=atoi(time.substr(0,2).c_str());
    int minute=atoi(time.substr(3,2).c_str());

    int ret=0;
    rep(i,month) ret+=60*24*d[i];
    ret+=60*24*(day-1);
    ret+=60*hour+minute;

    return ret;
}

vector<pi> LOG[1000];
int idx[1000];

int main()
{
    int n;
    while(cin >>n,n)
    {
        rep(i,1000)
        {
            LOG[i].clear();
            idx[i]=0;
        }

        rep(i,n)
        {
            string date,time,inout,id;
            cin >>date >>time >>inout >>id;

            int m=convert(date,time);
            int ID=atoi(id.c_str());

            if(inout=="I") LOG[ID].pb(pi(m,-1));
            else LOG[ID][idx[ID]++].se=m;
        }

        int ans=0;
        for(int i=1; i<1000; ++i)
        {
            if(LOG[i].size()==0) continue;

            int tmp=0;
            int god=0,pro=0;
            while(god<idx[0] && pro<idx[i])
            {
                int gl=LOG[0][god].fi, gr=LOG[0][god].se;
                int pl=LOG[i][pro].fi, pr=LOG[i][pro].se;
                if((pl<=gl && gl<pr) || (gl<=pl && pl<gr))
                {
                    int l=max(gl,pl), r=min(gr,pr);
                    tmp+=r-l;
                }

                if(LOG[0][god].se<LOG[i][pro].se) ++god;
                else ++pro;
            }

            ans=max(ans,tmp);
        }
        printf("%d\n", ans);
    }
    return 0;
}
