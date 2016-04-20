#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

int main()
{
	int i;

	int n,k;
	cin >>n >>k;

	std::vector<string> a(n);
	rep(i,n) cin >>a[i];

	sort(a.begin(),a.end(),greater<string>());
	rep(i,n) cout <<a[i];
	cout <<endl;
}
