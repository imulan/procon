#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

// 2^32-1 = 4294967295
const ll X = 4294967295LL;

int wrongSolver(vector<int> p) {
    int n = p.size();

    std::vector <unsigned int> a(n);
    rep(i,n) a[i]=p[i];

	std::vector<unsigned int> prefSum(n), sufSum(n);
	prefSum[0] = a[0];
	for (int i = 1; i < n; i++) {
		prefSum[i] = prefSum[i - 1] + a[i];
	}
	sufSum[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		sufSum[i] = sufSum[i + 1] + a[i];
	}
	unsigned int mn = prefSum[0] + sufSum[0];
	int where = 1;
	for (int i = 1; i < n; i++) {
		unsigned int val = prefSum[i] + sufSum[i];
		if (val < mn) {
			mn = val;
			where = i + 1;
		}
	}
	return where;
}

int Solver(vector<int> p) {
	int n = p.size();

    vector<ll> a(n);
    rep(i,n) a[i]=p[i];

	std::vector<ll> prefSum(n), sufSum(n);
	prefSum[0] = a[0];
	for (int i = 1; i < n; i++) {
		prefSum[i] = prefSum[i - 1] + a[i];
	}
	sufSum[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		sufSum[i] = sufSum[i + 1] + a[i];
	}
	ll mn = prefSum[0] + sufSum[0];
	int where = 1;
	for (int i = 1; i < n; i++) {
		ll val = prefSum[i] + sufSum[i];
		if (val < mn) {
			mn = val;
			where = i + 1;
		}
	}
	return where;
}

void solve()
{
    int n;
    cin >>n;

    vector<int> a(n,X/(n+1));

    rep(i,X%(n+1)+2) ++a[i];
    --a[n-1];

    // dbg(wrongSolver(a));
    // dbg(Solver(a));

    rep(i,n) printf("%d%c", a[i],(i==n-1?'\n':' '));
}

int main()
{
    int T;
    cin >>T;
    while(T--) solve();
    return 0;
}
