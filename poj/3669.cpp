#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <set>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x)
#define fi first
#define se second

typedef pair<int,int> pi;
typedef pair<int,pi> pii;
const int INF=10000;

inline bool in(int x, int y)
{
	return (0<=x&&0<=y);
}

int main()
{
	//フィールドが崩落するタイミング
	int f[302][302]={0};
	fill(f[0],f[301],INF);

	int dx[5]={0,1,-1,0,0}, dy[5]={0,0,0,1,-1};

	int m;
	scanf(" %d", &m);
	rep(i,m)
	{
		int x,y,t;
		scanf(" %d %d %d",&x,&y,&t);

		rep(j,5)
		{
			int nx=x+dx[j];
			int ny=y+dy[j];
			if(in(nx,ny)) f[ny][nx]=min(f[ny][nx],t);
		}
	}

	int ans=INF;

	if(f[0][0]==INF) ans=0;
	else
	{
		//time,point
		queue<pii> que;
		set<pii> S;
		que.push(pii(0,pi(0,0)));
		S.insert(pii(0,pi(0,0)));
		while(!que.empty())
		{
			pii p=que.front();
			que.pop();

			//printf(" %d, (%d,%d)\n",p.fi,p.se.fi,p.se.se);

			rep(i,5)
			{
				int nx=p.se.fi+dx[i];
				int ny=p.se.se+dy[i];
				if(in(nx,ny))
				{
					if(f[ny][nx]>p.fi+1 && p.fi<=1002)
					{
						if(f[ny][nx]==INF) ans=min(ans,p.fi+1);
						else
						{
							pii tmp(p.fi+1,pi(nx,ny));
							if(S.find(tmp)==S.end())
							{
								que.push(tmp);
								S.insert(tmp);
							}
						}
					}
				}
			}
		}
	}

	if(ans==INF) ans=-1;

	printf("%d\n",ans);
	return 0;
}
