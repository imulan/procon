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
typedef vector<pi> v;

map<pi,v> mp;

inline v make(pi p)
{
    int x=p.fi, y=p.se;

    v t(4);
    t[0]=pi(x,y+1);
    t[1]=pi(x+1,y);
    t[2]=pi(x,y-1);
    t[3]=pi(x-1,y);
    return t;
}

int main()
{
    int K;
    char s[200001];
    scanf(" %d %s", &K, s);

    pi now(0,0);

    mp[now] = make(now);
    // 近傍生成
    for(const auto &nb: mp[now]) mp[nb] = make(nb);

    map<char,int> move;
    move['U']=0;
    move['R']=1;
    move['D']=2;
    move['L']=3;

    rep(i,K)
    {
        // 今いる地点を訪問済みにする
        v a=mp[now];
        rep(j,4) mp[a[j]][(j^2)]=a[(j^2)];

        // 移動
        now = mp[now][move[s[i]]];

        // 近傍生成
        for(const auto &nb: mp[now])
        {
            if(mp.find(nb) == mp.end()) mp[nb] = make(nb);
        }
    }

    printf("%d %d\n", now.fi, now.se);
    return 0;
}
