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

const int N=5000000;

bool p[N+1];
vector<int> prime;

int a[10]={0};
int ct[10]={0};

int check()
{
    int ret=0;

    rep(i,10)
    {
        if(a[i]==1)
        {
            if(ct[i]==0) ret=1;
        }
        else
        {
            if(ct[i]>0) return -1;
        }
    }

    return ret;
}

int main()
{
    fill(p,p+N+1,true);
    p[0]=p[1]=false;
    for(int i=2; i<=N; ++i)
    {
        if(p[i]) for(int j=2; i*j<=N; ++j) p[i*j]=false;
    }

    rep(i,N+1) if(p[i]) prime.pb(i);

    int n;
    cin >>n;
    rep(i,n)
    {
        int x;
        cin >>x;
        a[x]=1;
    }

    int ans=-1;
    int P=prime.size();
    int K=1;

    rep(i,P)
    {
        //prime[i]を含む時
        int t=prime[i];
        while(t>0)
        {
            ++ct[t%10];
            t/=10;
        }

        //0:perfect, -1:over, 1:lack
        int state=check();

        if(state==0)
        {
            if(i==P-1) ans=max(ans,N-K);
            else ans=max(ans,prime[i+1]-1-K);
        }
        else if(state==-1)
        {
            rep(j,10) ct[j]=0;
            K=prime[i]+1;
        }
    }

    cout << ans << endl;
    return 0;
}
