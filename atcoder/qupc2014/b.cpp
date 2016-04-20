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
	int n;
	cin >>n;

	int a,b,c;
	c=n%10;
	n/=10;
	b=n%10;
	a=n/10;

	string s[10]={"nil","un","bi","tri","quad","pent","hex","sept","oct","enn"};

	string ans=s[a];

	if(a==9&&b==0) ans.erase(ans.size()-1);
	ans+=s[b];

	if(b==9&&c==0) ans.erase(ans.size()-1);
	ans+=s[c];

	if(ans[ans.size()-1]=='i') ans+="um";
	else ans+="ium";

	ans[0]=ans[0]-'a'+'A';

	std::cout << ans << std::endl;
	return 0;
}
