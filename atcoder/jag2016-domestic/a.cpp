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
	vector<string> s(n);
	rep(i,n) cin >>s[i];

	int ct=0;
	bool valid=true;
	rep(i,n)
	{
		if(s[i]=="A") ++ct;
		else --ct;
		if(ct<0) valid=false;
	}
	if(ct!=0) valid=false;

	string ans="NO";
	if(valid) ans="YES";
	cout << ans << endl;

	return 0;
}
