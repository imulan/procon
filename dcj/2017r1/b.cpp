#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

#include <message.h>
#include "pancakes.h"

int main()
{
    ll N = NumberOfNodes();
    ll ID = MyNodeId();

    ll S = GetStackSize();
    // printf(" S= %d\n", S);

    if(S>N)
    {
        ll start = ID * S/N;
        ll end = (ID+1) * S/N;
        if(ID==N-1) end=S-1;

        // printf(" NODEID: %d,  %lld ~ %lld\n", ID,start,end-1);

        ll val=0;
        ll a,b;
        for(ll i=start; i<end; ++i)
        {
            if(i==start)
            {
                a = GetStackItem(i);
                b = GetStackItem(i+1);
            }
            else
            {
                a = b;
                b = GetStackItem(i+1);
            }

            if(a>b) ++val;
        }
        PutLL(0,val);
        Send(0);

        if(ID==0)
        {
            ll ans=1;
            rep(node,N)
            {
                Receive(node);
                ans += GetLL(node);
            }
            cout << ans << endl;
        }
    }
    else
    {
        ll val=0;
        ll a,b;
        for(ll i=0; i<S-1; ++i)
        {
            if(i==0)
            {
                a = GetStackItem(i);
                b = GetStackItem(i+1);
            }
            else
            {
                a = b;
                b = GetStackItem(i+1);
            }

            if(a>b) ++val;
        }

        if(ID==0) cout << val+1 << endl;
    }
    return 0;
}
