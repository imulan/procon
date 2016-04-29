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
	int i,j;
	while(1)
	{
		int m;
		cin >>m;
		if(m==0) break;

		vector<pi> a(m);
		rep(i,m) scanf(" %d %d",&a[i].fi,&a[i].sc);

		int n;
		cin >>n;
		vector<pi> b(n);
		set<pi> s;
		rep(i,n){
			scanf(" %d %d",&b[i].fi,&b[i].sc);
			s.insert(b[i]);
		}

		int x=0,y=0;
		//a[0]とb[i]を揃える
		rep(i,n)
		{
			bool valid=true;
			int dx=b[i].fi-a[0].fi;
			int dy=b[i].sc-a[0].sc;
			rep(j,m)
			{
				pi tmp(a[j].fi+dx,a[j].sc+dy);
				if(s.find(tmp)==s.end())
				{
					valid=false;
					break;
				}
			}

			if(valid)
			{
				x=dx;
				y=dy;
				break;
			}
		}

		printf("%d %d\n",x,y);
	}
}
