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

typedef pair<int,int> pi;

int main()
{
	int n,m,q;
	cin >>n >>m >>q;

	map<char,pi> r;
	rep(i,n)rep(j,m)
	{
		char c;
		scanf(" %c", &c);
		if(c!='*') r[c]=pi(i+1,j+1);
	}

	rep(i,q)
	{
		char c;
		cin >>c;

		if(r.find(c)==r.end()) printf("NA\n");
		else printf("%d %d\n",r[c].fi,r[c].se);
	}

	return 0;
}
