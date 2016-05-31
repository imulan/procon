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

//sをb進数として解釈した時にxで割り切れるか
bool div(string s, int b, int x)
{
    int now=0;
    rep(i,s.size())
    {
        now = now*b+(s[i]-'0');
        now%=x;
    }

    return (now==0);
}

int main()
{
    int T;
    cin >>T;
    rep(t,T)
    {
        int N,J;
        cin >>N >>J;

        printf("Case #%d:\n", t+1);

        int ct=0;
        set<string> found;
        while(ct<J)
        {
            //ランダムな文字列生成
            string s="1";
            rep(i,N-2)
            {
                if(rand()%2==1) s+="1";
                else s+="0";
            }
            s+="1";

            //すでにある
            if(found.find(s)!=found.end()) continue;

            bool valid=true;
            vector<int> ans;

            //i進数で解釈した時に
            for(int i=2; i<=10; ++i)
            {
                bool ok=false;
                //jで割り切れるか
                for(int j=2; j<=1000; ++j)
                {
                    if(div(s,i,j))
                    {
                        ok=true;
                        ans.pb(j);
                        break;
                    }
                }

                if(!ok)
                {
                    valid=false;
                    break;
                }
            }

            if(valid)
            {
                ++ct;
                found.insert(s);

                cout << s;
                for(const auto& x:ans) cout << " " << x;
                cout << endl;
            }
        }
    }
    return 0;
}
