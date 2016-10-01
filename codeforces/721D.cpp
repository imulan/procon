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
typedef pair<ll,pi> P;

const int INF=1000000002;

int main()
{
    int n,k;
    ll x;
    cin >>n >>k >>x;

    int minus=0;
    int minus_max_val=-INF, minus_idx=-1;
    int plus_min_val=INF, plus_idx=-1;

    vector<ll> a(n);
    rep(i,n)
    {
        scanf(" %lld", &a[i]);
        if(a[i]<0)
        {
            ++minus;
            if(minus_max_val<a[i])
            {
                minus_idx=i;
                minus_max_val=a[i];
            }
        }
        else
        {
            if(a[i]<plus_min_val)
            {
                plus_min_val=a[i];
                plus_idx=i;
            }
        }
    }

    if(minus%2==0)
    {
        if(minus_idx!=-1 && plus_idx!=-1)
        {
            if(abs(minus_max_val)<abs(plus_min_val))
            {
                while(k>0 && a[minus_idx]<=0)
                {
                    --k;
                    a[minus_idx]+=x;
                }
            }
            else
            {
                while(k>0 && a[plus_idx]>=0)
                {
                    --k;
                    a[plus_idx]-=x;
                }
            }
        }
        else
        {
            if(minus_idx==-1)
            {
                while(k>0 && a[plus_idx]>=0)
                {
                    --k;
                    a[plus_idx]-=x;
                }
            }
            if(plus_idx==-1)
            {
                while(k>0 && a[minus_idx]<=0)
                {
                    --k;
                    a[minus_idx]+=x;
                }
            }
        }
    }

    priority_queue<P,vector<P>,greater<P>> pq;
    rep(i,n)
    {
        int sgn=1;
        if(a[i]<0) sgn=-1;

        pq.push(P(abs(a[i]), pi(sgn,i)));
    }

    while(k>0)
    {
        --k;
        P t=pq.top();
        pq.pop();

        t.fi+=x;
        pq.push(t);
    }

    while(!pq.empty())
    {
        P p=pq.top();
        pq.pop();

        int sgn=p.se.fi;
        int idx=p.se.se;
        a[idx] = sgn*p.fi;
    }

    rep(i,n)
    {
        if(i) printf(" ");
        printf("%lld", a[i]);
    }
    printf("\n");
    return 0;
}
