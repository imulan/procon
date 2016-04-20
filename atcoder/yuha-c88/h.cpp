//TLE

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

typedef pair<int,int> p;
typedef pair<p,p> pi;

int main()
{
	int i,j;

	int n;
	cin >>n;
	vector<string> s(n);
	rep(i,n) cin >>s[i];

	if(n>=2)
	{
		for(int T=0; T<1000; ++T)
		{
			int r=rand()%(n-1);
			swap(s[r],s[r+1]);
		}
	}

	int m;
	cin >>m;
	vector<string> r(m);
	rep(i,m) cin >>r[i];

	//候補となる位置
	vector<pi> c;
	rep(i,m)rep(j,m)
	{
		if(r[i][j]=='.')
		{
			//右に伸びるタイプの先頭になる
			if( (j==0&&r[i][j+1]=='.') || (0<j&&j<m-1&&r[i][j-1]!='.'&&r[i][j+1]=='.'))
			{
				c.pb( pi(p(i,j),p(0,0)) );
			}
			//下に伸びるタイプの先頭になる
			if( (i==0&&r[i+1][j]=='.') || (0<i&&i<m-1&&r[i-1][j]!='.'&&r[i+1][j]=='.'))
			{
				c.pb( pi(p(i,j),p(1,0)) );
			}
		}
	}

	int df[2]={0,1}, ds[2]={1,0};

	//始めに各マスの長さを求めておく
	rep(i,n)
	{
		int nf=c[i].fi.fi, ns=c[i].fi.sc;
		int dir=c[i].sc.fi;
		int len=0;
		while(nf<m&&ns<m&&r[nf][ns]!='#')
		{
			++len;
			nf+=df[dir];
			ns+=ds[dir];
		}
		c[i].sc.sc=len;
	}

	//総当り
	vector<int> a(n);
	rep(i,n) a[i]=i;

	vector<string> ans(m);
	do{
		vector<string> t(r);
		bool valid=true;

		//順番に埋めていく
		rep(i,n)
		{
			int nf=c[i].fi.fi, ns=c[i].fi.sc;
			int dir=c[i].sc.fi;
			int len=c[i].sc.sc;

			//枠に合わない
			if(len!=s[a[i]].size())
			{
				valid=false;
				break;
			}
			else
			{
				rep(j,len)
				{
					nf=c[i].fi.fi+df[dir]*j;
					ns=c[i].fi.sc+ds[dir]*j;

					if(t[nf][ns]=='.') t[nf][ns]=s[a[i]][j];
					else
					{//既に文字が入っている場合は一致しているか調べる
						if(t[nf][ns]!=s[a[i]][j])
						{
							valid=false;
							break;
						}
					}
				}
			}

			if(!valid) break;
		}

		if(valid)
		{
			ans=t;
			break;
		}
		else{
			/*
			rep(j,n) printf(" %d",a[j]);
			printf("\n");
			*/
			//この並びは途中で失敗したのでこれ以下の順列を試すのは無意味
			sort(a.begin()+i+1,a.end());
			reverse(a.begin()+i+1,a.end());
		}

	}while(next_permutation(a.begin(),a.end()));

	std::cout << m << std::endl;
	rep(i,m) std::cout << ans[i] << std::endl;
}
