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

void solve()
{
    int n;
    scanf(" %d", &n);

    vector<set<int>> G(n);

    rep(i,n-1)
    {
        int x,y;
        scanf(" %d %d", &x, &y);
        --x;
        --y;
        G[x].insert(y);
        G[y].insert(x);
    }

    multiset<int> deg;
    set<int> rem;
    rep(i,n)
    {
        deg.insert(G[i].size());
        rem.insert(i);
    }

    // この時点でスターの場合、不可能
    if(*deg.rbegin() == n-1)
    {
        printf("-1\n");
        return;
    }

    vector<int> ans;
    rep(i,n-1)
    {
        for(int nx:rem)
        {
            // 直前の頂点と接続していたらダメ
            if(i>0 && G[ans[i-1]].count(nx)) continue;
            // 実際に削除
            for(int j:G[nx])
            {
                deg.erase(deg.find(G[j].size()));
                G[j].erase(nx);
                deg.insert(G[j].size());
            }
            deg.erase(deg.find(G[nx].size()));

            // OK
            if(*deg.rbegin()<n-2-i || i==n-2)
            {
                ans.pb(nx);
                rem.erase(nx);
                break;
            }

            // スターになってしまったのでダメ
            for(int j:G[nx])
            {
                deg.erase(deg.find(G[j].size()));
                G[j].insert(nx);
                deg.insert(G[j].size());
            }
            deg.insert(G[nx].size());
        }
    }

    for(int x:ans) printf("%d ", x+1);
    printf("%d\n", *rem.begin()+1);
}

int main()
{
    int T;
    scanf(" %d", &T);
    while(T--) solve();
    return 0;
}
