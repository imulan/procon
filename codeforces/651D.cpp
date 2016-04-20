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
	long i;

	long n,a,b,t;
	string s;
	cin >>n >>a >>b >>t;
	cin >>s;

	//写真iを見るのにかかるコスト
	vector<long> cs(n);
	rep(i,n)
	{
		if(s[i]=='w') cs[i]=b+1;
		else cs[i]=1;
	}

	long ans=0;
	//時計回り
	long tmp=t;
	long now=0;
	long ct=0;
	while(ct<n)
	{
		//写真を見る
		tmp-=cs[now];
		if(tmp<0) break;
		++ct;

		//移動
		tmp-=a;
		++now;
		if(tmp<0) break;
	}
	ans=max(ans,ct);
	//printf(" ct1 = %ld\n",ct);

	//反時計回り
	tmp=t;
	now=0;
	ct=0;
	while(ct<n)
	{
		//写真を見る
		tmp-=cs[now];
		if(tmp<0) break;
		++ct;

		//移動
		tmp-=a;
		now=(now+n-1)%n;
		if(tmp<0) break;
	}
	ans=max(ans,ct);
	//printf(" ct2 = %ld\n",ct);

	if(ans<n){
		//前からpと後ろからq
		long p[500001]={0},q[500001]={0};
		rep(i,n-1) p[i+1]=p[i]+cs[i+1]+a;
		for(i=n; i>0; --i) q[i-1]=q[i]+cs[i-1]+a;

		//rep(i,n) printf("%ld ,p:%ld\n",i,p[i]);

		//まず戻ってから進む
		for(i=n-1; i>=1; --i)
		{
			ct=1+(n-1-i);
			long res=t;
			//行き
			res-=cs[0];
			res-=q[i];
			//帰り
			res-=(n-i)*a;
			if(res<0) continue;

			long pt=upper_bound(p,p+n,res)-p-1;
			//printf("i=%ld: res= %ld, pt=%ld\n",i, res,pt);

			ct+=pt+1;
			if(ct>n) ct=n;
			ans=max(ans,ct);
		}

		//printf("rev\n");

		sort(q,q+n);

		//rep(i,n) printf("%ld ,q:%ld\n",i,q[i]);

		//先に進んで戻る
		for(i=1; i<=n-1; ++i)
		{
			ct=i+1;
			long res=t;
			//行き
			res-=cs[0];
			res-=p[i];
			//帰り
			res-=i*a;
			if(res<0) continue;

			long pt=upper_bound(q,q+n,res)-q-1;
			//printf("i=%ld: res= %ld, pt=%ld\n",i, res,pt);

			ct+=pt+1;
			if(ct>n) ct=n;
			ans=max(ans,ct);
		}

	}

	std::cout << ans << std::endl;
}
