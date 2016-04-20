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
	int a,b,c;
	cin >>a >>b >>c;

	if(km(a,b,c)) printf("INF\n");
	else
	{
		int lim=max({a,b,c});
		int ct=0;

		for(int p=1; p<=lim; ++p)
		{
			if(km(a%p,b%p,c%p)) ++ct;
		}

		std::cout << ct << std::endl;
	}

	return 0;
}
