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

inline int dist2(const pi &a, const pi &b)
{
	return (a.fi-b.fi)*(a.fi-b.fi) + (a.se-b.se)*(a.se-b.se);
}

int main()
{
	int r;
	pi a,b,c;

	cin >>a.fi >>a.se >>r;
	cin >>b.fi >>b.se >>c.fi >>c.se;

	bool x,y;

	x=(c.se<a.se+r)|(a.se-r<b.se)|(a.fi+r>c.fi)|(a.fi-r<b.fi);

	y=(dist2(a,pi(b.fi,b.se))>r*r)|(dist2(a,pi(b.fi,c.se))>r*r)|(dist2(a,pi(c.fi,b.se))>r*r)|(dist2(a,pi(c.fi,c.se))>r*r);

	if(x) printf("YES\n");
	else printf("NO\n");
	if(y) printf("YES\n");
	else printf("NO\n");

	return 0;
}
