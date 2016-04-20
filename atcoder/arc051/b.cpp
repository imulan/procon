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
	int f[41]={0};
	f[0]=f[1]=1;
	for(int i=2; i<=40; ++i) f[i]=f[i-1]+f[i-2];

	int k;
	cin >>k;
	printf("%d %d\n",f[k-1],f[k]);
	return 0;
}
