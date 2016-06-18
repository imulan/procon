struct UF{
    int n;
    //正だったらその頂点の親,負だったら根で連結成分の個数
    vector<int> d;
    UF() {}
    UF(int n):n(n), d(n,-1){}
    int root(int v){
        if(d[v]<0) return v;
        return d[v]=root(d[v]);
    }
    bool unite(int x,int y){
        x=root(x); y=root(y);
        if(x==y) return false;
        if(size(x) < size(y)) swap(x,y);
        d[x]+=d[y];
        d[y]=x;
        return true;
    }
    int size(int v){ return -d[root(v)]; }
}
