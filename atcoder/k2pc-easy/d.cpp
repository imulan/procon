#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

typedef pair<ll,ll> pl;

int main()
{
	ll i;

	ll k,n;
	cin >>k >>n;

	vector<pl> v(n);
	set<pl> S;

	rep(i,n)
	{
		cin >>v[i].fi >>v[i].sc;
		S.insert(v[i]);
	}

	//2の累乗
	ll pw[52];
	pw[0]=1;
	rep(i,51) pw[i+1]=pw[i]*2;

	ll ans=pw[k+1]-1;

	rep(i,n)
	{

		//根まで辿り着けるか調べる
		bool valid=true;

		pl now=v[i];
		while(now.fi>0)
		{
			now.fi = now.fi-1;
			now.sc = (now.sc+1)/2;

			if(S.find(now)!=S.end())
			{
				valid=false;
				break;
			}
		}

		if(valid)
		{
			ans-=pw[k-v[i].fi+1]-1;
			//cout<<" minus : "<<pw[k-v[i].fi+1]-1<<endl;
		}
	}

	std::cout << ans << std::endl;
}
