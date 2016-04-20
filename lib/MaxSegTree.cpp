/******************************
 MaxSegTree.cpp  START
******************************/

/******************************
 区間の最大値を返すSegmentTree
******************************/

struct MaxSegTree{
	long n; vector<ll> dat;
	//初期化
	MaxSegTree(long _n){
		n=1;
		while(n<_n) n*=2;
		dat=vector<ll>(2*n-1,LLONG_MIN);
	}
	//k番目(0-indexed)の値をaに変更
	void update(long k, ll a){
		k+=n-1;
		dat[k]=a;
		//更新
		while(k>0){
		k=(k-1)/2;
		dat[k]=max(dat[2*k+1],dat[2*k+2]);
		}
	}
	//内部的に投げられるクエリ
	ll _query(long a, long b, long k, long l, long r){
		if(r<=a || b<=l) return LLONG_MIN;

		if(a<=l && r<=b) return dat[k];
		else{
			ll vl=_query(a,b,2*k+1,l,(l+r)/2);
			ll vr=_query(a,b,2*k+2,(l+r)/2,r);
			return max(vl,vr);
		}
	}
	//[a,b)の最大値を求める
	ll query(long a, long b){
		return _query(a,b,0,0,n);
	}
};

/******************************
 MaxSegTree.cpp  END
******************************/
