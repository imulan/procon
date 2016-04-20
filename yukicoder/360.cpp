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

bool km(int a, int b, int c)
{
	if(a==b || b==c || c==a) return false;

	if(max({a,b,c})==b || min({a,b,c})==b) return true;
	else return false;
}


int main()
{
	vector<int> d(7);
	rep(i,7) cin >>d[i];

	sort(all(d));

	bool valid=false;
	do
	{
		bool ok=true;
		for(int i=1; i<=5; ++i)
		{
			ok&=(d[i-1]<d[i+1])&&km(d[i-1],d[i],d[i+1]);
		}
		valid|=ok;
	}
	while(next_permutation(all(d)));


	string ans="NO";
	if(valid) ans="YES";
	std::cout << ans << std::endl;

	return 0;
}
