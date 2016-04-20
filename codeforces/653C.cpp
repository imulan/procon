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

typedef pair<int,int> pi;

int main()
{
	int n;
	cin >>n;
	std::vector<int> t(n);
	rep(i,n) cin >>t[i];

	vector<int> c;
	//候補
	if(t[0]>=t[1]) c.pb(0);
	for(int i=1; i<=n-2; ++i)
	{
		if(i%2==1 && (t[i-1]>=t[i]||t[i]<=t[i+1])) c.pb(i);
		if(i%2==0 && (t[i-1]<=t[i]||t[i]>=t[i+1])) c.pb(i);
	}
	if(n%2==0 && t[n-2]>=t[n-1]) c.pb(n-1);
	if(n%2==1 && t[n-2]<=t[n-1]) c.pb(n-1);

	set<pi> s;
	if(c.size()<=6)
	{
		for(const auto &x: c)
		{
			rep(i,n)
			{
				if(i==x) continue;

				swap(t[i],t[x]);

				bool valid=true;

				//おかしかった部分の前後をチェック
				for(const auto &y: c)
				{
					if(y==0)
					{
						if(t[0]>=t[1]) valid=false;
					}
					else if(y==n-1)
					{
						if(n%2==0 && t[n-2]>=t[n-1]) valid=false;
						if(n%2==1 && t[n-2]<=t[n-1]) valid=false;
					}
					else
					{
						if(y%2==1 && (t[y-1]>=t[y]||t[y]<=t[y+1])) valid=false;
						if(y%2==0 && (t[y-1]<=t[y]||t[y]>=t[y+1])) valid=false;
					}
				}

				//入れ替えた先もチェック
				if(i==0)
				{
					if(t[0]>=t[1]) valid=false;
				}
				else if(i==n-1)
				{
					if(n%2==0 && t[n-2]>=t[n-1]) valid=false;
					if(n%2==1 && t[n-2]<=t[n-1]) valid=false;
				}
				else
				{
					if(i%2==1 && (t[i-1]>=t[i]||t[i]<=t[i+1])) valid=false;
					if(i%2==0 && (t[i-1]<=t[i]||t[i]>=t[i+1])) valid=false;
				}

				if(valid) s.insert(pi(min(i,x),max(i,x)));
				swap(t[i],t[x]);
			}
		}
	}

	std::cout << s.size() << std::endl;
	return 0;
}
