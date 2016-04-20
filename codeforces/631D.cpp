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

typedef pair<ll,char> p;

struct KMP
{
	vector<int> fail;
	vector<p> x;
	KMP(){}
	KMP(const vector<p> &y) :x(y)
	{
		int m=x.size();
		fail=vector<int>(m+1);
		int j=fail[0]=-1;
		for(int i=1; i<=m; i++)
		{
			while (j>=0 && x[j]!=x[i-1]) j=fail[j];
			fail[i] = ++j;
		}
	}
	vector<int> match(const vector<p> &t) {
		int n=t.size(), m=x.size();
		vector<int>ret;
		for(int i=0, k=0; i<n; i++)
		{
			while (k>=0 && x[k]!=t[i]) k=fail[k];
			if(++k >= m)
			{
				ret.push_back(i); // match at t[i-m+1 .. i]
				k=fail[k];
			}
		}
		return ret;
	}
};


int main(int argc, char const *argv[]) {
	int n,m;
	cin >>n >>m;

	vector<p> t,s;

	//input
	rep(i,n)
	{
		ll l;
		char c;
		scanf(" %lld-%c",&l,&c);

		if(t.size()==0) t.pb(p(l,c));
		else
		{
			if(t[t.size()-1].se==c) t[t.size()-1].fi+=l;
			else t.pb(p(l,c));
		}
	}
	rep(i,m)
	{
		ll l;
		char c;
		scanf(" %lld-%c",&l,&c);

		if(s.size()==0) s.pb(p(l,c));
		else{
			if(s[s.size()-1].se==c) s[s.size()-1].fi+=l;
			else s.pb(p(l,c));
		}
	}

	//solve
	ll ans=0;
	if(t.size()>=s.size())
	{
		if(s.size()==1)
		{
			rep(i,t.size())
			{
				if(t[i].se==s[0].se) ans+=max(0LL,t[i].fi-s[0].fi+1);
			}
		}
		else if(s.size()==2)
		{
			rep(i,t.size()-1)
			{
				if(t[i].se==s[0].se && t[i+1].se==s[1].se)
				{
					if(t[i].fi>=s[0].fi && t[i+1].fi>=s[1].fi) ++ans;
				}
			}
		}
		else
		{
			vector<p> u;
			//先頭と末尾を除いた部分
			u.assign(s.begin()+1, s.end()-1);

			KMP kmp(u);
			for(const auto &i : kmp.match(t))
			{
				int l=i-u.size();
				int r=i+1;
				if(l>=0 && r<n && t[l].se==s[0].se && t[r].se==s[s.size()-1].se)
				{
					if(t[l].fi>=s[0].fi && t[r].fi>=s[s.size()-1].fi) ++ans;
				}

			}
		}
	}
	std::cout << ans << std::endl;
	return 0;
}
