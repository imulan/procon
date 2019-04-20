#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

struct segtree{
	static const int N=1<<18;
	int dp[1<<19];
	int dp2[1<<19];
	int lazy[1<<19];
	segtree(){
		memset(dp,0,sizeof(dp));
		memset(dp2,0,sizeof(dp2));
		memset(lazy,0,sizeof(lazy));
	}
	void add(int k,int v){
		k+=N-1;
		dp[k]+=v;
		while(k>0){
			k=(k-1)/2;
			dp[k]=dp[k*2+1]+dp[k*2+2];
		}
	}

	void lazy_eval(int k){
		if(lazy[k]%2==1){
			swap(dp[k],dp2[k]);
		}
		if(k<N-1){
			lazy[k*2+1]+=lazy[k];
			lazy[k*2+2]+=lazy[k];
		}
		lazy[k]=0;
	}

	void lazy_upd(int k){
		dp[k]=dp[k*2+1]+dp[k*2+2];
		dp2[k]=dp2[k*2+1]+dp2[k*2+2];
	}

	void update(int a,int b,int k=0,int l=0,int r=N){
		lazy_eval(k);
		if(b<=l || r<=a)return;
		if(a<=l && r<=b){
			lazy[k]++;
			lazy_eval(k);
			return;
		}
		update(a,b,k*2+1,l,(l+r)/2);
		update(a,b,k*2+2,(l+r)/2,r);
		lazy_upd(k);
	}

	int query(int a,int b,int k=0,int l=0,int r=N){
		lazy_eval(k);
		if(b<=l || r<=a)return 0;
		if(a<=l && r<=b)return dp[k];
		int vl=query(a,b,k*2+1,l,(l+r)/2);
		int vr=query(a,b,k*2+2,(l+r)/2,r);
		lazy_upd(k);
		return vl+vr;
	}
};

int n,q;
vector<int> G[110001];

segtree seg;
int l[100005],r[100005];
int cnt=0;


void dfs(int v,int c){
	l[v]=cnt++;
	for(int i=0;i<G[v].size();i++){
		if(G[v][i]!=c){
			dfs(G[v][i],v);
		}
	}
	r[v]=cnt++;
}

int main(void){
	scanf("%d%d",&n,&q);
	for(int i=0;i<n-1;i++){
		int a;
		scanf("%d%*c",&a);
		printf("%d\n",a);
		a--;
		G[a].push_back(i+1);
		G[i+1].push_back(a);
	}
	dfs(0,-1);
	for(int i=0;i<n;i++){
		seg.add(l[i],1);
		printf("%d %d\n",l[i],r[i]);
	}
	for(int i=0;i<n;i++){
		char c;
		scanf("%c%*c",&c);
		if(c=='G'){
			seg.update(l[i],l[i]+1);
		}
		//printf("%d\n",seg.query(l[i],l[i+1]));
	}
	int val=seg.query(l[0],r[0]);
		printf("%d %s\n",val,val<=n/2?"cauliflower":"broccoli");
	for(int i=0;i<q;i++){
		int a;
		scanf("%d",&a);
		a--;
		seg.update(l[i],r[i]);
		int val=seg.query(l[0],r[0]);
		printf("%d %s\n",val,val<=n/2?"cauliflower":"broccoli");
	}
	return 0;
}