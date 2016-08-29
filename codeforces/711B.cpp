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

int main()
{
    int n;
    cin >>n;

    ll a[500][500];
    pi emp;
    rep(i,n)rep(j,n)
    {
        cin >>a[i][j];
        if(a[i][j]==0) emp=pi(i,j);
    }

    if(n==1)
    {
        printf("1\n");
        return 0;
    }

    //n>2

    ll sum=0;
    if(emp.fi==0) rep(i,n) sum+=a[1][i];
    else rep(i,n) sum+=a[0][i];

    ll t=0;
    rep(i,n) t+=a[emp.fi][i];

    ll x=sum-t;
    if(x<=0)
    {
        printf("-1\n");
        return 0;
    }

    //x>0
    a[emp.fi][emp.se]=x;
    //全部sumに一致するか調べる
    bool valid=true;

    //i行目
    rep(i,n)
    {
        ll tmp=0;
        rep(j,n) tmp+=a[i][j];
        if(tmp!=sum) valid=false;
    }

    //i列目
    rep(i,n)
    {
        ll tmp=0;
        rep(j,n) tmp+=a[j][i];
        if(tmp!=sum) valid=false;
    }

    //斜め
    ll t1=0, t2=0;
    rep(i,n)
    {
        t1+=a[i][i];
        t2+=a[i][n-1-i];
    }
    if(t1!=sum || t2!=sum) valid=false;

    if(!valid) x=-1;
    cout << x << endl;
    return 0;
}
