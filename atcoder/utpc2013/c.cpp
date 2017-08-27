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

const int INF = 19191919;

vector<int> g()
{
    int n,m;
    cin >>n >>m;

    vector<vector<int>> G(n);
    rep(i,m)
    {
        int a,b;
        cin >>a >>b;
        G[a].pb(b);
        G[b].pb(a);
    }

    vector<int> ret(n);
    rep(i,n)
    {
        vector<int> d(n,INF);
        d[i] = 0;
        queue<int> que;
        que.push(i);
        while(!que.empty())
        {
            int v = que.front();
            que.pop();
            for(const auto &e:G[v])
            {
                if(d[e] > d[v]+1)
                {
                    d[e] = d[v]+1;
                    que.push(e);
                }
            }
        }
        ret[i] = *max_element(all(d));
    }
    sort(all(ret));
    return ret;
}

int main()
{
    vector<int> x = g(), y = g();
    int X = x.size(), Y = y.size();

    int a = max({x[0]+y[0]+1, x[X-1], y[Y-1]});
    int b = x[X-1] + y[Y-1] + 1;

    cout << a << " " << b << endl;
    return 0;
}
