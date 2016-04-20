#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

const ll A=100000000;
bool p[A+1];
vector<ll> prime;

int main()
{
	fill(p,p+A+1,true);
	p[0]=p[1]=false;
	for(ll i=2; i*2<=A; ++i)
	{
		if(p[i]) for(ll j=2; i*j<=A; ++j) p[i*j]=false;
	}

	rep(i,A+1) if(p[i]) prime.pb(i);
	//std::cout << prime.size() << std::endl;

	int T;
	cin >>T;
	rep(t,T)
	{
		int N,J;
		cin >>N >>J;

		printf("Case #%d:\n",t+1);

		int ct=0;
		rep(i,1<<(N-2))
		{
			string t="1";
			rep(j,N-2)
			{
				if(i>>j&1) t+="1";
				else t+="0";
			}
			t+="1";

			bool valid=true;
			vector<ll> ans;
			for(int j=2; j<=10; ++j)
			{
				ll pw=1;
				ll now=0;
				for(int k=t.size()-1; k>=0; --k)
				{
					if(t[k]=='1') now+=pw;
					pw*=j;
				}

				bool found=false;
				for(ll k=0; prime[k]*prime[k]<=now; ++k)
				{
					if(now%prime[k]==0)
					{
						found=true;
						ans.pb(prime[k]);
						break;
					}
				}

				if(!found)
				{
					valid=false;
					break;
				}
			}

			if(valid)
			{
				++ct;
				cout << t;
				rep(j,ans.size()) cout << " " << ans[j];
				cout << endl;
			}

			if(ct==J) break;
		}
	}
	return 0;
}
