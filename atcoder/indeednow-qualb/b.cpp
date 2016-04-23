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
	string s,t;
	cin >>s >>t;

	int n=s.size();
	int ct=0;
	bool valid=false;

	if(s!=t)
	{
		rep(i,n)
		{
			s=s[n-1]+s;
			s.resize(n);
			++ct;
			if(t==s)
			{
				valid=true;
				break;
			}
		}
	}

	if(!valid && s!=t) ct=-1;
	std::cout << ct << std::endl;
	return 0;
}
