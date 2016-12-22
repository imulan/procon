struct StarrySkyTree{
    long n; vector<ll> dat,segAdd;
    // 初期化
    StarrySkyTree(long _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<ll>(2*n-1,0);
        segAdd=vector<ll>(2*n-1,0);
    }
    // 区間和: [a,b)に+x
    void _add(long a, long b, ll x, long k, long l, long r){
        //  交差しない区間であれば終了
        if(r<=a || b<=l) return;

        // 今注目している区間[l,r)が[a,b)に完全に内包される時
        if(a<=l && r<=b){
            segAdd[k] += x;
            return;
        }

        // 子の区間に渡す
        _add(a,b,x,2*k+1,l,(l+r)/2);
        _add(a,b,x,2*k+2,(l+r)/2,r);

        dat[k] = max(dat[2*k+1]+segAdd[2*k+1], dat[2*k+2]+segAdd[2*k+2]);
    }
    void add(long a, long b, ll x)
    {
        _add(a,b,x,0,0,n);
    }
    //内部的に投げられるクエリ
    ll _query(long a, long b, long k, long l, long r){
        if(r<=a || b<=l) return 0;

        if(a<=l && r<=b) return dat[k]+segAdd[k];

        ll vl=_query(a,b,2*k+1,l,(l+r)/2);
        ll vr=_query(a,b,2*k+2,(l+r)/2,r);
        return max(vl,vr)+segAdd[k];
    }
    //[a,b)の最大値を求める
    ll query(long a, long b){
        return _query(a,b,0,0,n);
    }
};
