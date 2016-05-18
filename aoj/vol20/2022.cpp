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

typedef vector<int> vi;

int main()
{
    int n;
    while(cin >>n,n)
    {
        vector<string> s(n);
        rep(i,n) cin >>s[i];

        sort(all(s));
        s.erase(unique(all(s)),s.end());
        n=s.size();

        //s[i]がs[j]の部分列になっているかを調べる
        vector<bool> rm(n,false);
        rep(i,n)rep(j,n)
        {
            if(i==j) continue;

            int a=s[i].size(), b=s[j].size();
            if(a>b) continue;

            rep(k,b-a+1)
            {
                string tmp=s[j].substr(k,a);
                /*
                printf("%d %d %d:",i,j,k);
                cout <<tmp <<endl;
                */
                if(tmp==s[i]) rm[i]=true;
            }
        }

        vector<string> t(s);
        s.clear();
        rep(i,t.size())
        {
            if(rm[i]) --n;
            else s.pb(t[i]);
        }

        //s[i],s[j]の順に並べるときの文字被りの数
        vector<vi> cov(n,vi(n,0));
        rep(i,n)rep(j,n)
        {
            if(i==j) continue;

            int lim=min(s[i].size(),s[j].size());
            int ct=0;
            for(int k=1; k<=lim; ++k)
            {
                string a=s[i].substr(s[i].size()-k,k);
                string b=s[j].substr(0,k);
                /*
                printf("%d, %d, %d :", i,j,k);
                cout <<" a: "<<a<<" , b: "<<b<<endl;
                */
                if(a==b) ct=k;
            }
            cov[i][j]=ct;
        }

        //rep(i,n)rep(j,n) printf(" cov[%d][%d]=%d\n", i,j,cov[i][j]);

        string INF="";
        rep(i,100) INF+="z";

        //initialize
        string dp[10][1024];
        fill(dp[0],dp[10],INF);
        rep(i,n) dp[i][1<<i]=s[i];

        //現在の状態
        for(int mask=1; mask<(1<<n); ++mask)
        {
            //次に使おうと思ってるもの
            rep(i,n)
            {
                //already used
                if(mask>>i&1) continue;

                //どこからの遷移か(dp[j][mask])
                rep(j,n)
                {
                    //not used
                    if((mask>>j&1)==0) continue;

                    string nx=dp[j][mask];
                    string add=s[i].substr(cov[j][i]);
                    nx+=add;

                    if(dp[i][mask+(1<<i)].size()>nx.size())
                        dp[i][mask+(1<<i)]=nx;
                    else if(dp[i][mask+(1<<i)].size()==nx.size())
                        dp[i][mask+(1<<i)]=min(dp[i][mask+(1<<i)],nx);
                }
            }
        }

        string ans=INF;
        rep(i,n)
        {
            /*
            printf("dp[%d][%d]= ", i,(1<<n)-1);
            cout << dp[i][(1<<n)-1] <<endl;
            */

            if(dp[i][(1<<n)-1].size()<ans.size()) ans=dp[i][(1<<n)-1];
            else if(dp[i][(1<<n)-1].size()==ans.size()) ans=min(ans,dp[i][(1<<n)-1]);
        }

        cout << ans << endl;
    }
    return 0;
}
