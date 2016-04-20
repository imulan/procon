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

struct res{int w,l,d;};

int main()
{
	int i;

	int n;
	cin >>n;

	int ct[100001][4]={0};

	std::vector<pi> v(n);
	std::vector<int> a(n);
	rep(i,n)
	{
		cin >>v[i].fi >>v[i].sc;
		--v[i].sc;

		a[i]=v[i].fi;
		++ct[v[i].fi][v[i].sc];
	}

	sort(a.begin(),a.end());

	std::vector<res> r(n);
	rep(i,n)
	{
		r[i]=res{0,0,0};

		int left=lower_bound(a.begin(),a.end(),v[i].fi)-a.begin();
		int right=upper_bound(a.begin(),a.end(),v[i].fi)-a.begin()-1;
		//printf("%d: %d~%d\n",i,left,right);

		//レートの違いによる勝敗
		r[i].w=left;
		r[i].l=n-1-right;

		//レートが同じ時
		r[i].w+=ct[v[i].fi][(v[i].sc+1)%3];
		r[i].l+=ct[v[i].fi][(v[i].sc+2)%3];
		//引き分けは自分を除く
		r[i].d=ct[v[i].fi][v[i].sc]-1;
	}

	rep(i,n) printf("%d %d %d\n",r[i].w,r[i].l,r[i].d);
}
