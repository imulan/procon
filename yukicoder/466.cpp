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

void solve(int A, int B, int C, int D)
{
    vector<pi> e;

    if(C<A && C<B)
    {
        int b=0;
        for(int i=2; i<=A; ++i)
        {
            e.pb(pi(b,i));
            b=i;
        }

        b=1;
        for(int i=A+1; i<A+B-C; ++i)
        {
            e.pb(pi(b,i));
            b=i;
        }

        if(C>0) e.pb(pi(b,A-C+1));
    }
    else if(C==A && C==B)
    {
        if(C==1)
        {
            printf("-1\n");
            return;
        }
        rep(i,C) e.pb(pi(i,(i+1)%C));
    }
    else
    {
        // C==A or C==B
        int R=1;
        if(C==B)
        {
            R=0;
            swap(A,B);
        }
        // C==A

        e.pb(pi(R,!R));
        for(int i=2; i<=A; ++i) e.pb(pi(!R,i));
        if(C==B) e.pb(pi(!R,R));
        else
        {
            for(int i=A+1; i<B; ++i) e.pb(pi(R,i));
        }

    }

    // judge
    if(e.size()<=D)
    {
        int n=2;
        rep(i,e.size()) n=max({n,e[i].fi+1,e[i].se+1});

        printf("%d %d\n", n, e.size());
        rep(i,e.size()) printf("%d %d\n", e[i].fi, e[i].se);
    }
    else printf("-1\n");

}

int main()
{
    int A,B,C,D;
    cin >>A >>B >>C >>D;
    solve(A,B,C,D);
    return 0;
}
