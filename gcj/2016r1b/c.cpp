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

typedef pair<string,string> ps;

int main()
{
    int times;
    cin >>times;
    rep(T,times)
    {
        int n;
        cin >>n;
        vector<ps> w(n);
        rep(i,n) cin >>w[i].fi >>w[i].se;

        sort(all(w));

        int ans=0;
        rep(i,1<<n)
        {
            set<string> a,b;
            vector<ps> v;
            //偽物がどれかを仮定
            rep(j,n)
            {
                if(i>>j&1) v.pb(w[j]);
                else
                {
                    a.insert(w[j].fi);
                    b.insert(w[j].se);
                }
            }

            bool valid=true;
            //偽物に対して
            rep(j,v.size())
            {
                //既存の本物から作れるかどうか
                bool ok=true;
                if(a.find(v[j].fi)==a.end()) ok=false;
                if(b.find(v[j].se)==b.end()) ok=false;

                if(!ok)
                {
                    valid=false;
                    break;
                }
            }

            if(valid) ans=max(ans,__builtin_popcount(i));
        }

        printf("Case #%d: %d\n",T+1,ans);
    }
    return 0;
}
