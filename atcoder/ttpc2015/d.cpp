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

bool isPrime(long x)
{
	if(x==1) return false;
	for(long i=2; i*i<=x; ++i)
	{
		if(x%i==0) return false;
	}
	return true;
}

int main()
{
	string s;
	cin >>s;

	set<char> w;
	rep(i,s.size()) w.insert(s[i]);

	long ans=-1;

	if(w.size()<=5)
	{
		string num="13579";

		do
		{
			int now=0;
			map<char,char> dict;
			for(const auto &x : w) dict[x]=num[now++];

			string tmp="";
			rep(i,s.size()) tmp+=dict[s[i]];

			long z=stol(tmp);
			if(isPrime(z))
			{
				ans=z;
				break;
			}
		}
		while(next_permutation(all(num)));
	}

	std::cout << ans << std::endl;
	return 0;
}
