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

int main()
{
    int T;
    cin >>T;
    rep(t,T)
    {
        int n;
        cin >>n;

        //BFF
        vector<int> g[1000];
        //逆辺
        vector<int> inv[1000];

        //辺作成
        rep(i,n)
        {
            int f;
            scanf(" %d", &f);
            --f;
            g[i].pb(f);
            inv[f].pb(i);
        }

        int ans=0;
        //ループサイズ2のものを組み合わせた時に出来る円の大きさ
        int twos=0;

        vector<bool> vis(n,false);

        //iから探索を始める
        rep(i,n)
        {
            //既に訪れている場所なので探索は不要
            if(vis[i]) continue;

            //はじめに連結成分を見つけてvisを更新しておく
            vis[i]=true;
            queue<int> que;
            que.push(i);
            while(!que.empty())
            {
                int v=que.front();
                que.pop();
                rep(j,g[v].size())
                {
                    if(!vis[g[v][j]])
                    {
                        vis[g[v][j]]=true;
                        que.push(g[v][j]);
                    }
                }
                rep(j,inv[v].size())
                {
                    if(!vis[inv[v][j]])
                    {
                        vis[inv[v][j]]=true;
                        que.push(inv[v][j]);
                    }
                }
            }

            //iからの連結成分を探すための訪問記録
            vector<bool> tvis(n,false);
            //現在位置
            int now=i;
            while(!tvis[now])
            {
                tvis[now]=true;
                now=g[now][0];
            }

            //この時点でnowには2回目の訪問になった
            //つまりループ内に存在する頂点である
            //このループの大きさを調べる
            set<int> s;
            while(1)
            {
                //既に訪れている
                if(s.find(now) != s.end()) break;
                s.insert(now);
                now=g[now][0];
            }

            //ループの大きさ
            int cycle=s.size();
            if(cycle==2)
            {
                //ループを構成する2頂点
                int l=now;
                int r=g[now][0];

                const int INF=123456;
                vector<int> dl(n,INF);
                vector<int> dr(n,INF);

                //lから出る逆辺をたどる
                dl[l]=0;
                que.push(l);
                while(!que.empty())
                {
                    int v=que.front();
                    que.pop();
                    rep(j,inv[v].size())
                    {
                        int nx=inv[v][j];
                        if(nx==r) continue;

                        if(dl[nx]>dl[v]+1)
                        {
                            dl[nx]=dl[v]+1;
                            que.push(nx);
                        }
                    }
                }

                //rから出る逆辺をたどる
                dr[r]=0;
                que.push(r);
                while(!que.empty())
                {
                    int v=que.front();
                    que.pop();
                    rep(j,inv[v].size())
                    {
                        int nx=inv[v][j];
                        if(nx==l) continue;

                        if(dr[nx]>dr[v]+1)
                        {
                            dr[nx]=dr[v]+1;
                            que.push(nx);
                        }
                    }
                }

                //最も遠い点を選ぶ
                int ml=0,mr=0;
                rep(j,n)
                {
                    if(dl[j]<INF) ml=max(ml,dl[j]);
                    if(dr[j]<INF) mr=max(mr,dr[j]);
                }
                
                twos+=2+ml+mr;
            }
            else ans=max(ans,cycle);

        }

        ans=max(ans,twos);

        printf("Case #%d: %d\n", t+1, ans);
    }
    return 0;
}
