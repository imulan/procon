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
	char s[50][51];

	cin >>n;
	rep(i,n)rep(j,n) scanf(" %c",&s[i][j]);

	rep(i,n)
	{
		for(int j=n-1; j>=0; --j) printf("%c",s[j][i]);
		printf("\n");
	}

	return 0;
}
