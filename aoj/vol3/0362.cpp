#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

bool check(const vector<int> &d)
{
    int n = d.size();
    vector<bool> vis(n);
    vis[0] = true;
    queue<int> que;
    que.push(0);
    while(!que.empty())
    {
        int v = que.front();
        que.pop();
        for(int i=d[v]; i>0; --i)
        {
            int nx = min(n-1,v+i);
            if(vis[nx]) break;

            que.push(nx);
            vis[nx] = true;
        }
    }
    return vis[n-1];
}

int main()
{
    int n;
    cin >>n;
    vector<int> d(n);
    rep(i,n)
    {
        cin >>d[i];
        d[i]/=10;
    }

    string ans = "yes";
    if(!check(d)) ans = "no";

    reverse(all(d));
    if(!check(d)) ans = "no";

    cout << ans << endl;
    return 0;
}
