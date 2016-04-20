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

bool km(int a, int b, int c)
{
	if(a==b || b==c || c==a) return false;

	if(max({a,b,c})==b || min({a,b,c})==b) return true;
	else return false;
}

int main()
{
	int t;
	cin >>t;
	rep(T,t)
	{
		int L;
		int a[3][3];

		cin >>L;

		pi p[2];
		int ct=0;
		rep(i,3)rep(j,3)
		{
			cin >>a[i][j];
			if(a[i][j]==0) p[ct++]=pi(i,j);
		}




	}
	return 0;
}
