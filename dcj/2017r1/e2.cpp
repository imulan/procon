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

    if(ID!=0)
    {
        int broken = -1;
        ll sum=0;

        if(L>N-1)
        {
            int start = (ID-1) * (L/(N-1));
            int end = ID * (L/(N-1));
            if(ID==N-1) end = L;

            printf("%d %d\n", start,end);

            for(int i=start; i<end; ++i)
            {
                int v = GetValue(i);
                sum += v;

                rep(j,30)
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
            PutLL(0,sum);
            Send(0);
        }
        else
        {
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
        }
    }

    if(ID==0)
    {
        ll ans=0;

        if(L>N-1)
        {
            for(int i=1; i<N; ++i)
            {
                Receive(i);
                int b = GetLL(i);
                Receive(i);
                ll s = GetLL(i);

                if(b==-1)
                {
                    ans += s;
                }
                else
                {
                    int start = (i-1) * (L/(N-1));
                    int end = (i-1) * (L/(N-1));
                    if(i==N-1) end = L;

                    for(int i=start; i<end; ++i)
                    {
                        if(i!=b) ans += GetValue(i);
                    }
                    ans += GetValue(b);
                }
            }
        }
        else
        {
            Receive(1);
            int b = GetLL(1);
            // printf(" broken  %d\n", b);

            rep(i,L)
            {
                if(i!=b)
                {
                    ans += GetValue(i);
                    // printf("i= %d\n", i);
                }
            }

            ans += GetValue(b);
        }

        cout << ans << endl;
    }

    return 0;
}
