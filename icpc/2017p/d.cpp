#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);i++)
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back((a))
#define all(x) begin(x),end(x)
#define uniq(x) sort(all(x)),(x).erase(unique(all(s)),end(x))
#define dbg(x) cout<<#x" = "<<((x))<<endl

int check(int n, int x, const vector<int> &s)
{
    int ct = 0;

    // 次倒すモンスター
    int idx = 0;
    int L = 1;
    while(1)
    {
        if(s[n-1]<L+x)
        {
            ++ct;
            break;
        }

        while(idx<n-1 && s[idx]<=L) ++idx;

        int add =1;
        for(int j=-1; j<1; ++j)
        {
            int ss = idx+j;
            if(0<=ss && ss<n && s[ss]<L+x) add=max(add,x-abs(L-s[ss]));
        }

        L += add;
        ++ct;
    }
    return ct;
}

int main() {
    int n,m;
    while(cin >>n >>m, n)
    {
        vector<int> s(n);
        rep(i,n) cin >>s[i];

        int l=s[0], r=1000000;
        while(r-l>1)
        {
            int x = (l+r)/2;

            if(check(n,x,s)>=m) l=x;
            else r=x;
        }

        if(check(n,l,s)<m) l=-1;
        printf("%d\n", l);
    }
    return 0;
}
