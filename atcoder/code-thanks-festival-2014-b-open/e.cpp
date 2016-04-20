#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

typedef pair<int,int> pi;

int main()
{
	int i,j,k;

	int R,C;
	cin >>R >>C;
	pi s,g;
	cin >>s.fi >>s.sc;
	cin >>g.fi >>g.sc;

	//フィールド形成
	int n;
	cin >>n;

	int f[50][50]={0};
	rep(i,n)
	{
		int r,c,h,w;
		scanf(" %d %d %d %d",&r,&c,&h,&w);

		for(j=r; j<r+h; ++j)
		for(k=c; k<c+w; ++k)
		f[j][k]=1;
	}

	string ans="NO";
	if(f[s.fi][s.sc]*f[g.fi][g.sc]==1){
		//BFS
		int df[4]={1,-1,0,0}, ds[4]={0,0,-1,1};

		bool vis[50][50];
		fill(vis[0],vis[50],false);
		vis[s.fi][s.sc]=true;

		queue<pi> que;
		que.push(s);
		while(!que.empty())
		{
			pi vp=que.front();
			que.pop();
			rep(i,4)
			{
				int nf=vp.fi+df[i], ns=vp.sc+ds[i];
				if(0<nf&&nf<=R&&0<ns&&ns<=C && f[nf][ns]==1 && !vis[nf][ns])
				{
					vis[nf][ns]=true;
					que.push(pi(nf,ns));
				}
			}
		}

		if(vis[g.fi][g.sc]) ans="YES";
	}
	std::cout << ans << std::endl;
}
