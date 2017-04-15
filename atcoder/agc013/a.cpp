#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main()
{
    int n;
    scanf(" %d", &n);
    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    int ans=0;
    int now=0;
    while(now<n)
    {
        ++ans;
        // printf("now = %d\n", now);

        int dir=0;
        while(now+1<n)
        {
            // printf(" now = %d, dir= %d\n", now,dir);

            if(dir==1)
            {
                if(a[now]>a[now+1])
                {
                    ++now;
                    break;
                }
            }
            else if(dir==-1)
            {
                if(a[now]<a[now+1])
                {
                    ++now;
                    break;
                }
            }
            else
            {
                if(a[now]<a[now+1]) dir=1;
                else if(a[now]>a[now+1]) dir=-1;
            }
            ++now;
        }

        if(now==n-1)
        {
            if(dir==1 && a[now-1]>a[now]) ++ans;
            if(dir==-1 && a[now-1]<a[now]) ++ans;
            break;
        }
    }

    printf("%d\n", ans);
    return 0;
}
