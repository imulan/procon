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
typedef pair<pi,stack<int>> p;

int n,m;
vector<int> a,b;

map<p,int> m;
int rec(int x, int y, stack<int> st)
{

}


int main()
{
	cin >>n >>m;
	a.resize(n);
	b.resize(m);
	rep(i,n) cin >>a[i];
	rep(i,m) cin >>b[i];

	return 0;
}
