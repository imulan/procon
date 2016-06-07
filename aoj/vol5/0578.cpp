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
    int n;
    cin >>n;
    string s;
    cin >>s;

    int ans=0;
    int S=s.size();

    rep(i,n)
    {
        string t;
        cin >>t;

        bool ok=false;
        //スタート位置
        rep(j,t.size())
        {
            //幅
            for(int k=1; k<=t.size(); ++k)
            {
                //最後の文字の位置
                int last=j+(S-1)*k;
                if(last>=t.size()) continue;

                bool valid=true;
                rep(l,S)
                {
                    int p=j+l*k;
                    if(s[l]!=t[p]) valid=false;
                }

                if(valid)
                {
                    //printf(" %d, %d, %d\n",i,j,k);
                    ok=true;
                    break;
                }
            }
            if(ok) break;
        }

        if(ok) ++ans;
    }

    cout << ans << endl;
    return 0;
}
