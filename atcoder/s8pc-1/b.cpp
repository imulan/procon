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

typedef pair<int,int> pi;

int main()
{
	int h,w,n;
	cin >>h >>w >>n;
	vector<pi> v(n);
	rep(i,n) cin >>v[i].fi >>v[i].se;

	set<pi> ans;
	for(int i=1; i<=w; ++i)
	{
		pi p(i,h);
		int a=0,b=0;
		rep(j,n)
		{
			int A=p.fi*v[j].se;
			int B=p.se*v[j].fi;

			if(A>B) ++a;
			else if(A<B) ++b;
		}

		if(a==b && a+b==n) ans.insert(p);
	}
	for(int i=h-1; i>0; --i)
	{
		pi p(w,i);
		int a=0,b=0;
		rep(j,n)
		{
			int A=p.fi*v[j].se;
			int B=p.se*v[j].fi;

			if(A>B) ++a;
			else if(A<B) ++b;
		}

		if(a==b && a+b==n) ans.insert(p);
	}

	if(ans.size()==0) printf("-1\n");
	else
	{
		for(const auto &t:ans) printf("(%d,%d)\n",t.fi,t.se);
	}
	return 0;
}
