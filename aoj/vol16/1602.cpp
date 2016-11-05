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

int main()
{
    int n;
    while(cin >>n,n)
    {
        int max_level=0;

        vector<pi> a(n);
        rep(i,n)
        {
            string s;
            cin >>s;

            int S=s.size();

            int level=S-1;

            int num=s[S-1]-'0';
            if(s[S-1]=='+') num=-1;
            if(s[S-1]=='*') num=-2;

            a[i]=pi(level,num);
            max_level=max(max_level,level);
        }

        for(int i=max_level-1; i>=0; --i)
        {
            vector<pi> nx;

            int now=0;
            int A=a.size();
            while(now<A)
            {
                if(a[now].se<0 && a[now].fi==i)
                {
                    bool add=true;
                    int val=0;
                    if(a[now].se==-2)
                    {
                        add=false;
                        val=1;
                    }

                    ++now;
                    while(now<A && a[now].fi==i+1)
                    {
                        if(add) val+=a[now].se;
                        else val*=a[now].se;
                        ++now;
                    }

                    nx.pb(pi(i,val));
                }
                else nx.pb(a[now++]);
            }

            a=nx;
        }

        cout << a[0].se << endl;
    }
    return 0;
}
