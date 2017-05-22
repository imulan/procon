#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

#include <message.h>
#include "query_of_death.h"

int main()
{
    ll N = NumberOfNodes();
    ll ID = MyNodeId();

    ll L = GetLength();

    if(ID==1)
    {
        int broken = -1;
        rep(i,L)
        {
            int v = GetValue(i);

            rep(j,100)
            {
                int g = GetValue(i);
                if(g!=v)
                {
                    broken=i;
                    break;
                }
            }

            if(broken!=-1) break;
        }

        PutLL(0,broken);
        Send(0);
    }

    if(ID==0)
    {
        Receive(1);
        int b = GetLL(1);
        // printf(" broken  %d\n", b);

        ll ans=0;
        rep(i,L)
        {
            if(i!=b) ans += GetValue(i);
        }

        ans += GetValue(b);
        cout << ans << endl;
    }

    return 0;
}
