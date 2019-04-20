#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(int)n; ++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int ct(int n)
{
    if(n==1) return 0;
    if(n==2) return 1;
    if(n==3) return 2;
    if(n==4) return 1;

    if(n%3==0) return 1+n/3;
    return (n+1)/3;
}

// 隣り合うところしか飛べない
int solve(int n, int s, int f)
{
    if(s>f) swap(s,f);

    if(s==f) return -1;

    int l = s-1, m = f-s-1, r=n-f;

    if(abs(s-f)==1)
    {
        if(l==0 || r==0) return 1;
        return -1;
    }

    if(l==0)
    {
        if(r==0) return ct(f-s+1);
        else return ct(m+1)+1;
    }
    else
    {
        if(r==0) return 1 + ct(m+1);
        else return ct(m) +2;
    }
}

int main()
{
    int n,s,f;
    cin >>n >>s >>f;

    cout << solve(n,s,f) << endl;
}
