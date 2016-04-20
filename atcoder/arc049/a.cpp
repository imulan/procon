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

int main()
{
	string s;
	cin >>s;
	int a,b,c,d;

	cin >>a >>b >>c >>d;
	b+=1;
	c+=2;
	d+=3;

	s=s.substr(0,a)+"\""+s.substr(a);
	s=s.substr(0,b)+"\""+s.substr(b);
	s=s.substr(0,c)+"\""+s.substr(c);
	s=s.substr(0,d)+"\""+s.substr(d);

	std::cout << s << std::endl;
	return 0;
}
