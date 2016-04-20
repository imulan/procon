#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

typedef pair<long,long> P;

long cr(P a, P b)
{
	return a.fi*b.sc-a.sc*b.fi;
}

int main()
{
	int i,j;

	int n;
	cin >>n;

	vector<P> v(n);
	map<P,string> d;
	map<string,P> id;
	rep(i,n)
	{
		string s;

		cin >>s >>v[i].fi >>v[i].sc;
		d[v[i]]=s;
		id[s]=v[i];
	}
	sort(v.begin(),v.end());

	//rep(i,n) cout<<" "<<v[i].fi<<","<<v[i].sc<<" : "<<d[v[i]]<<endl;

	int m;
	cin >>m;
	vector<P> t;
	set<P> polygon;
	rep(i,m)
	{
		string tmp;
		cin >>tmp;

		t.pb(id[tmp]);
		polygon.insert(id[tmp]);
	}

	vector<string> ans;
	//内外判定
	rep(i,n)
	{
		//凸多角形に含まれる点は調べる必要が無い
		if(polygon.find(v[i])!=polygon.end()) continue;

		int ct=0;
		rep(j,m)
		{
			P a=t[j], b=t[(j+1)%m];
			//平行移動
			a.fi-=v[i].fi;
			b.fi-=v[i].fi;
			a.sc-=v[i].sc;
			b.sc-=v[i].sc;

			//線分abとx軸正の部分の交差判定
			if(a.sc>b.sc) swap(a,b);
			if(a.sc<=0 && 0<b.sc)
			{
				if(cr(a,b)<0) ++ct;
			}
		}

		if(ct%2==1) ans.pb(d[v[i]]);
	}

	rep(i,ans.size()) cout<<ans[i]<<endl;
}
