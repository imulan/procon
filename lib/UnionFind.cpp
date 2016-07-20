struct UF{
    int n;
    //正だったらその頂点の親,負だったら根で連結成分の個数
    vector<int> d;
    UF() {}
    UF(int N):n(N), d(N,-1){}
    int root(int v){
        if(d[v]<0) return v;
        return d[v]=root(d[v]);
    }
    bool unite(int X,int Y){
        X=root(X); Y=root(Y);
        if(X==Y) return false;
        if(size(X) < size(Y)) swap(X,Y);
        d[X]+=d[Y];
        d[Y]=X;
        return true;
    }
    int size(int v){ return -d[root(v)]; }
};
