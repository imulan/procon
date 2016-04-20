#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

typedef pair<long,long> pl;

int main()
{
	int i;

	int n,k;
	cin >>n >>k;
	vector<pl> v(n);
	rep(i,n) scanf(" %ld %ld",&v[i].fi,&v[i].sc);

	rep(i,n) swap(v[i].fi,v[i].sc);
	sort(v.begin(),v.end());
	rep(i,n) swap(v[i].fi,v[i].sc);

	//rep(i,n) printf("  %ld,%ld\n",v[i].fi,v[i].sc);

	double l=0,r=100;
	double m=0;
	while(fabs(r-l)>1e-8)
	{
		m=(l+r)/2;
		//printf(" try %.20lf\n",m);

		int ct=0;
		double W=0,G=0;
		for(i=n-1; i>=0; --i)
		{
			if(v[i].sc<m) break;
			if(ct==k) break;
			W+=v[i].fi;
			G+=v[i].fi*v[i].sc/100.0;
			++ct;
		}

		if(ct<k)
		{
			int lim=i;
			vector<pl> t;
			vector<pair<double,int>> vv(lim+1);
			rep(i,lim+1)
			{
				vv[i].fi=v[i].fi*(m-v[i].sc)/100.0;
				vv[i].sc=i;
				t.pb(v[i]);
			}
			sort(t.begin(),t.end());
			sort(vv.begin(),vv.end());
			//rep(i,lim+1) vv[i].fi=-vv[i].fi;

			//rep(i,lim+1) printf(" %.10lf->(%ld,%ld)\n",vv[i].fi,v[vv[i].sc].fi,v[vv[i].sc].sc);

			int now=0;
			while(ct<k)
			{
				//printf(" add %ld %.10lf\n",v[vv[now].sc].fi, vv[now].fi);
				W+=v[vv[now].sc].fi;
				G+=v[vv[now].sc].fi*v[vv[now].sc].sc/100.0;
				++ct;
				++now;
			}
		}

		if(G/W>=m/100) l=m;
		else r=m;
	}

	printf("%.20lf\n",m);
}
