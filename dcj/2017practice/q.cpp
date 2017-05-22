#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

#include <message.h>
#include "oops.h"

const ll INF = LLONG_MAX/3;

int main()
{
    ll N = GetN();
    ll NODE = NumberOfNodes();
    ll ID = MyNodeId();

    ll mx=0,mn=INF;
    for(ll i=ID; i<N; i+=NODE)
    {
        ll v = GetNumber(i);
        mx = max(mx,v);
        mn = min(mn,v);
    }
    PutLL(0,mx);
    Send(0);
    PutLL(0,mn);
    Send(0);

    if(ID == 0)
    {
        ll ans=0;
        ll X=0, Y=INF;
        rep(node,NODE)
        {
            Receive(node);
            mx = GetLL(node);
            Receive(node);
            mn = GetLL(node);

            X = max(X, mx);
            Y = min(Y, mn);
        }

        cout << X-Y << endl;
    }

    return 0;
}
