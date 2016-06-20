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

typedef pair<int,int> pi;

int main()
{
    int n;
    cin >>n;
    vector<int> a(n),b(n);
    rep(i,n) scanf(" %d", &a[i]);
    rep(i,n) scanf(" %d", &b[i]);

    int ans=n;

    //スタート位置
    rep(i,n)
    {
        priority_queue<pi,vector<pi>,greater<pi>> que;

        //(レベル,戦闘回数)
        rep(j,n) que.push(pi(a[j],0));

        //バトルしていく
        rep(j,n)
        {
            pi m=que.top();
            que.pop();

            m.fi+=b[(i+j)%n]/2;
            ++m.se;

            que.push(m);
        }

        //最大の戦闘回数
        int t=0;
        while(!que.empty())
        {
            pi now=que.top();
            que.pop();
            t=max(t,now.se);
        }

        //最小値更新
        ans=min(ans,t);
    }



    cout << ans << endl;
    return 0;
}
