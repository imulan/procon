#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int G[1000][1000];

int main()
{
    int T;
    cin >>T;
    while(T--)
    {
        int n,m;
        scanf(" %d %d", &n, &m);

        memset(G,0,sizeof(G));
        rep(i,m)
        {
            int a,b;
            scanf(" %d %d", &a, &b);
            --a;
            --b;

            G[a][b]=G[b][a]=1;
        }

        //-1:未定,0:青テーブル,1:赤テーブル
        vector<int> color(n,-1);
        //色の整合性が保たれているか
        bool confuse=false;
        rep(i,n)
        {
            if(color[i]!=-1) continue;

            color[i]=0;

            queue<int> que;
            que.push(i);
            while(!que.empty())
            {
                int v=que.front();
                que.pop();
                rep(j,n)
                {
                    if(j==v) continue;

                    //繋がっていないのでvとiは違う色でないといけない
                    if(!G[v][j])
                    {
                        if(color[j]==-1)
                        {
                            color[j] = !color[v];
                            que.push(j);
                        }
                        else
                        {
                            if(color[j] == color[v])
                            {
                                confuse=true;
                                break;
                            }
                        }
                    }
                }

                if(confuse) break;
            }
            if(confuse) break;
        }

        // rep(i,n) printf("%d color: %d \n", i+1, color[i]);
        // if(confuse) printf("confuse\n");

        string ans="NO";
        if(!confuse)
        {
            ans="YES";
            rep(i,n)rep(j,n)
            {
                if(i==j) continue;

                if(color[i] == color[j])
                {
                    if(!G[i][j]) ans="NO";
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
