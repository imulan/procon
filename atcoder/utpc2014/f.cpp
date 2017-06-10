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

const int N=100000;
const int INF=123456789;

vector<int> G[N];
int d[N];

int main()
{
    cin.tie(0);ios::sync_with_stdio(false);

    int n;
    cin >>n;

    vector<string> a(n);
    set<string> s;
    rep(i,n)
    {
        cin >>a[i];
        s.insert(a[i]);
    }

    map<string,int> num2id;
    int S=0;
    for(const auto &num:s) num2id[num]=S++;

    rep(i,n)
    {
        int u = num2id[a[i]];

        rep(j,9)if(a[i][j]!=a[i][j+1])
        {
            string t=a[i];
            swap(t[j],t[j+1]);
            if(s.count(t))
            {
                int v = num2id[t];
                G[u].pb(v);
                G[v].pb(u);
            }
        }
    }

    fill(d,d+N,INF);
    rep(i,S)
    {
        if(d[i]!=INF) continue;

        d[i]=0;
        queue<int> que;
        que.push(i);
        while(!que.empty())
        {
            int v = que.front();
            que.pop();
            for(const auto &nx:G[v])
            {
                if(d[nx]>d[v]+1)
                {
                    d[nx]=d[v]+1;
                    que.push(nx);
                }
            }
        }
    }

    rep(i,n) printf("%d\n", d[num2id[a[i]]]%2);
    return 0;
}
