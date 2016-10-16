#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int INF=1234567890;
typedef pair<int,int> pi;

int main()
{
    int n;
    scanf(" %d", &n);

    bool full=false;
    set<pi> s;
    while(n--)
    {
        int x;
        scanf(" %d", &x);

        if(full)
        {
            printf("No\n");
            continue;
        }
        if(s.size()==0)
        {
            s.insert(pi(x,x));
            printf("Yes\n");
            continue;
        }

        bool suc=true;

        auto r = s.lower_bound(pi(x,INF));
        pi R = *r;

        if(r == s.begin())
        {
            // 左側に区間がない
            // rと結合 or 新しく作る
            if(R.fi-1 == x)
            {
                // printf(" connect (%d,%d)\n", R.fi, R.se);
                pi nx(x,R.se);
                s.erase(r);
                s.insert(nx);
            }
            else
            {
                // printf(" made (%d,%d)\n", x,x);
                s.insert(pi(x,x));
            }
        }
        else
        {
            // 左に区間がある
            r--;
            auto l=r;
            r++;

            pi L=*l;

            if(L.fi<=x && x<=L.se)
            {
                // 区間内
                // printf("区間内\n");
                if(L.fi==1)
                {
                    if(x<L.se) suc=false;
                    else if(x==L.se)
                    {
                        if(s.size()==1)
                        {
                            // printf(" ---FULL---\n");
                            full=true;
                        }
                        else suc=false;
                    }
                }
                else
                {
                    // L.fi!=1なので安全にマージできる

                    if(l!=s.begin())
                    {
                        auto ll=l;
                        ll--;

                        pi LL = *ll;
                        // printf(" L=(%d,%d)\n", L.fi,L.se);
                        // printf(" LL=(%d,%d)\n", LL.fi,LL.se);
                        if(LL.se == L.fi-2)
                        {
                            s.erase(ll);
                            s.insert(pi(LL.fi,L.fi-1));
                        }
                        else s.insert(pi(L.fi-1,L.fi-1));
                    }
                    else s.insert(pi(L.fi-1,L.fi-1));

                    if(x!=L.se) s.insert(pi(x+1,L.se));

                    s.erase(l);
                }
            }
            else
            {
                //区間外
                int newl=x, newr=x;
                if(L.se==x-1)
                {
                    newl=L.fi;
                    s.erase(l);
                }
                if(x+1==R.fi)
                {
                    newr=R.se;
                    s.erase(r);
                }

                // printf(" outrange: insert(%d,%d)\n", newl,newr);
                s.insert(pi(newl,newr));
            }

        }

        if(suc) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
