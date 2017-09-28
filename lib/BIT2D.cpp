struct BIT2D{
    int H,W;
    vector<vector<ll>> bit;

    BIT2D(int h, int w){
        H = h;
        W = w;
        bit = vector<vector<ll>>(h+1,vector<ll>(w+1));
    }

    void add(int y, int x, ll w){
        for(int j=y; j<=H; j+=j&-j){
            for(int i=x; i<=W; i+=i&-i){
                bit[j][i] += w;
            }
        }
    }

    ll sum(int y, int x){
        ll ret = 0;
        for(int j=y; j>0; j-=j&-j){
            for(int i=x; i>0; i-=i&-i){
                ret += bit[j][i];
            }
        }
        return ret;
    }

    ll sum(int ly, int lx, int ry, int rx){
        return sum(ry,rx) - sum(ry,lx-1) - sum(ly-1,rx) + sum(ly-1,lx-1);
    }
};
