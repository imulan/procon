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

int h,w;
string s[100];

//ここにいるときに勝てるか
bool dp[100][100];
bool rec(int y, int x)
{
	if(dp[y][x]) return true;

	bool ret=false;

	//下か右下か右
	int dy[3]={1,1,0}, dx[3]={0,1,1};
	rep(i,3)
	{
		int ny=y+dy[i], nx=x+dx[i];
		if(0<=ny&&ny<h&&0<=nx&&nx<w && s[ny][nx]=='.') ret|=!rec(ny,nx);
	}

	return dp[y][x]=ret;
}

int main()
{
	cin >>h >>w;
	rep(i,h) cin >>s[i];

	fill(dp[0],dp[100],false);

	string ans="Second";
	if(rec(0,0)) ans="First";
	std::cout << ans << std::endl;
	return 0;
}
