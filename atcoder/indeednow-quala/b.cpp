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

int main()
{
	string base="indeednow";
	sort(all(base));
	int n;
	cin >>n;
	rep(i,n)
	{
		string s;
		cin >>s;
		sort(all(s));
		string ans="NO";
		if(base==s) ans="YES";
		std::cout << ans << std::endl;
	}
	return 0;
}
