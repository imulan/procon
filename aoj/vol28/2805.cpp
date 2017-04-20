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
    int n,m;
    cin >>n >>m;

    int here[300];
    fill(here,here+300,1);
    rep(i,m)
    {
        int a;
        cin >>a;
        here[a]=0;
    }

    queue<int> que;
    rep(i,n) que.push(i);

    int ans=0;
    while(que.size()>1)
    {
        int a=que.front(); que.pop();
        int b=que.front(); que.pop();

        if(here[a] && here[b]) ++ans;

        if(!here[a]) que.push(b);
        else que.push(a);
    }

    cout << ans << endl;
    return 0;
}
