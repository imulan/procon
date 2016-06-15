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

typedef pair<ll,int> p;

int main()
{
    ll n;
    int q;
    cin >>n >>q;

    vector<ll> a(q);
    rep(i,q) cin >>a[i];

    queue<p> que;
    que.push(p(1,q));
    while(1)
    {
        p now=que.front();
        if(now.se==0) break;
        que.pop();

        if(now.fi*a[now.se-1]<=n) que.push(p(now.fi*a[now.se-1],now.se-1));

        if(now.fi%a[now.se-1]!=0) que.push(p(now.fi,now.se-1));
    }

    cout << que.size() << endl;
    return 0;
}
