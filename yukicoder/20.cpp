#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

const int INF=10000000;
int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

typedef pair<int,int> pi;

int main()
{
	int i,j;
	int n,v,ox,oy;
	int f[201][201]={0};
	cin >>n >>v >>ox >>oy;
	rep(i,n)rep(j,n) cin>>f[i+1][j+1];

	bool valid=false;
	string ans="NO";

	//たどりつくまでに消費する体力の最小値を計算
	//オアシスを無視して、とりあえず行けるか
	int d[201][201];
	fill(d[0],d[201],INF);
	d[1][1]=0;
	queue<pi> que;
	que.push(pi(1,1));
	while(!que.empty())
	{
		pi p=que.front();
		que.pop();
		rep(i,4)
		{
			int nx=p.fi+dx[i], ny=p.sc+dy[i];
			if(0<nx&&nx<=n&&0<ny&&ny<=n)
			{
				if(d[ny][nx]>d[p.sc][p.fi]+f[ny][nx])
				{
					d[ny][nx]=d[p.sc][p.fi]+f[ny][nx];
					que.push(pi(nx,ny));
				}
			}
		}
	}

	//直接行ける
	if(d[n][n]<v) valid=true;

	if(!valid && ox*oy!=0)
	{//オアシスがある時
		//オアシスにたどり着いた直後の体力
		int nv=2*(v-d[oy][ox]);
		if(nv>0)
		{
			int d2[201][201];
			fill(d2[0],d2[201],INF);
			d2[oy][ox]=0;
			que.push(pi(ox,oy));
			while(!que.empty())
			{
				pi p=que.front();
				que.pop();
				rep(i,4)
				{
					int nx=p.fi+dx[i], ny=p.sc+dy[i];
					if(0<nx&&nx<=n&&0<ny&&ny<=n)
					{
						if(d2[ny][nx]>d2[p.sc][p.fi]+f[ny][nx])
						{
							d2[ny][nx]=d2[p.sc][p.fi]+f[ny][nx];
							que.push(pi(nx,ny));
						}
					}
				}
			}

			//オアシス経由で行ける
			if(d2[n][n]<nv) valid=true;
		}
	}

	if(valid) ans="YES";
	std::cout << ans << std::endl;
}
