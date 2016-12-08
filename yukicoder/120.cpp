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
    int T;
    scanf(" %d", &T);
    while(T--)
    {
        int n;
        scanf(" %d", &n);

        map<int,int> ct;
        rep(i,n)
        {
            int L;
            scanf(" %d", &L);
            ++ct[L];
        }

        priority_queue<int> que;
        for(const auto &x:ct) que.push(x.se);

        int ans=0;
        while(que.size()>=3)
        {
            int p[3];
            rep(i,3)
            {
                p[i]=que.top();
                que.pop();
            }
            rep(i,3)
            {
                --p[i];
                if(p[i]>0) que.push(p[i]);
            }
            ++ans;
        }

        printf("%d\n", ans);
    }
    return 0;
}
