#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <istream>
#include <cassert>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N=300000;

ll x[N],y[N],z[N];

int main()
{
    cin.tie(0);ios::sync_with_stdio(false);
    while(1)
    {
        int n=0;
        string buf;
        while(getline(cin,buf) && !buf.empty())
        {
            int B=buf.size();
            int sep[2]={0};
            int s_idx=0;
            rep(i,B)
            {
                if(buf[i]==' ') sep[s_idx++]=i;
            }

            x[n]=atoll(buf.substr(0,sep[0]).c_str());
            y[n]=atoll(buf.substr(sep[0]+1,sep[1]-sep[0]-1).c_str());
            z[n]=atoll(buf.substr(sep[1]+1).c_str());
            ++n;
        }

        if(n==0) continue;

        assert(n<N);

        ll l=0, r=1LL<<33;
        while(r-l>1)
        {
            ll m=(l+r)/2;
            ll ct=0;
            rep(i,n)
            {
                if(y[i]<m || y[i]<x[i]) continue;

                ll k1=0;
                if(m-x[i]>0) k1=(m-x[i]+z[i]-1)/z[i];
                ll k2=(y[i]-x[i])/z[i];
                // printf(" %d: k1,k2 %lld, %lld\n",i, k1,k2);

                if(k2<k1) continue;
                ct+=k2-k1+1;
            }
            // printf("m=%lld, ct=%lld\n", m,ct);

            if(ct%2==1) l=m;
            else r=m;
        }

        int num=0;
        rep(i,n)
        {
            if(y[i]<x[i]) continue;
            if(l<x[i] || y[i]<l ) continue;

            if((l-x[i])%z[i]==0) ++num;
        }

        if(r==1) cout << "no corruption\n";
        else cout << l << " " << num << '\n';

        if(cin.eof()) break;
    }
    return 0;
}
