#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x)
#define fi first
#define se second

typedef pair<int,int> p;

int main()
{
	int n,b;
	cin >>n >>b;
	vector<p> v(n);
	rep(i,n) scanf(" %d %d",&v[i].fi,&v[i].se);

	ll t[200000]={0};

	int now=0;
	ll tt=0;
	queue<int> que;
	while(now<n)
	{
		if(!que.empty())
		{
			int x=que.front();
			que.pop();
			tt+=v[x].se;
			t[x]=tt;
			while(now<n && v[now].fi<tt)
			{
				if(que.size()<b) que.push(now);
				else t[now]=-1;
				++now;
			}
		}
		else
		{
			int x=now;
			tt=v[x].fi+v[x].se;
			t[x]=tt;
			++now;
			while(now<n && v[now].fi<tt)
			{
				if(que.size()<b) que.push(now);
				else t[now]=-1;
				++now;
			}
		}

		//printf("now= %d\n", now);
	}

	//後処理
	while(!que.empty())
	{
		int x=que.front();
		que.pop();
		tt+=v[x].se;
		t[x]=tt;
	}

	//output
	rep(i,n)
	{
		if(i) printf(" ");
		cout <<t[i];
	}
	printf("\n");
}
