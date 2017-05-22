#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

#include <message.h>
#include "weird_editor.h"

const ll mod=1e9+7;

inline ll mod_pow(ll x, ll n)
{
    ll pw[60];
    pw[0]=x%mod;
    for(int i=1; i<60; ++i) pw[i]=(pw[i-1]*pw[i-1])%mod;

    ll ret=1;
    rep(i,60)
    {
        if(n>>i&1) (ret*=pw[i])%=mod;
    }
    return ret;
}

inline ll mod_inv(ll x)
{
    return mod_pow(x,mod-2);
}

int main()
{
    ll N = NumberOfNodes();
    ll ID = MyNodeId();

    ll L = GetNumberLength();

    ll ct[10]={};
    if(L>N)
    {
        ll start = ID * L/N;
        ll end = (ID+1) * L/N;
        if(ID==N-1) end=L;

        int max_d=0;
        // printf(" NODEID: %d,  %lld ~ %lld\n", ID,start,end-1);
        for(ll i=start; i<end; ++i)
        {
            int d = GetDigit(i);
            rep(j,d) ct[j]=0;
            ++ct[d];
        }

        // 前のノードの情報を受け取り、統合
        if(ID<N-1)
        {
            ll b[10]={};
            for(int i=1; i<10; ++i)
            {
                Receive(ID+1);
                b[i] = GetLL(ID+1);
            }

            int max_b=0;
            rep(i,10)
            {
                if(b[i]>0) max_b=i;
            }

            // ctを更新
            rep(i,max_b) ct[i]=0;
            rep(i,10) ct[i]+=b[i];
        }

        // 各数字が何個あるかの情報を上位桁に送る
        if(ID>0)
        {
            for(int i=1; i<10; ++i)
            {
                PutLL(ID-1,ct[i]);
                Send(ID-1);
            }
        }
    }
    else
    {
        int max_d=0;
        for(ll i=0; i<L; ++i)
        {
            int d = GetDigit(i);
            rep(j,d) ct[j]=0;
            ++ct[d];
        }
    }

    if(ID==0)
    {
        // 答えを求める
        ll ans = 0;

        ll B = L-1;
        for(int i=9; i>0; --i)
        {
            ll n=ct[i];
            if(n==0) continue;

            ll A = B - (n-1);

            ll add=i;
            (add*=mod_inv(9))%=mod;
            (add*=mod_pow(10, A))%=mod;
            (add*=(mod_pow(10, n)-1+mod)%mod)%=mod;

            (ans+=add)%=mod;
            B -= n;
        }
        cout << ans << endl;
    }
    return 0;
}
