#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

int main()
{
    int n,L;
    cin >>n >>L;

    //両端に折れたつららがあると見なす
    vector<int> a(n+2,0);
    for(int i=1; i<=n; ++i) scanf(" %d", &a[i]);

    //つららiが折れる時刻
    long t[100002]={0};

    queue<int> que;
    //最初につららが伸びる位置を探す
    for(int i=1; i<=n; ++i)
    {
        //つららが伸び始める
        if(a[i-1]<a[i] && a[i]>a[i+1]) que.push(i);
    }

    vector<int> b(a);

    while(!que.empty())
    {
        int idx=que.front();
        que.pop();

        long tmp=L-a[idx];
        if(b[idx-1]==0) tmp=max(tmp,t[idx-1]+(L-a[idx]));
        if(b[idx+1]==0) tmp=max(tmp,t[idx+1]+(L-a[idx]));
        //折れる
        b[idx]=0;
        t[idx]=tmp;
        //printf("idx=%d, tmp=%ld\n", idx,tmp);

        int nx=idx-1;
        if(b[nx-1]<b[nx] && b[nx]>b[nx+1]) que.push(nx);
        nx=idx+1;
        if(b[nx-1]<b[nx] && b[nx]>b[nx+1]) que.push(nx);
    }

    long ans=0;
    for(int i=1; i<=n; ++i) ans=max(ans,t[i]);
    cout << ans << endl;
    return 0;
}
