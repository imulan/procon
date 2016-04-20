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

inline bool cmp(const string& a, const string& b)
{
	return a+b < b+a;
}

int main()
{
	int n;
	cin >>n;
	vector<string> a(n);
	rep(i,n) cin >>a[i];

	sort(all(a),cmp);
	rep(i,n) cout <<a[i];
	cout <<endl;
}
