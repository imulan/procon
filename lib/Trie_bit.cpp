const int SZ = 2;
struct Trie{
    vector<array<int,SZ>> nodes;
    vector<int> rem;

    Trie(){
        nodes.pb({});
        rem.pb(0);
    }

    void add(int x){
        int node_num = 0;
        for(int i=17; i>=0; --i){
            int b = x>>i&1;
            // 行き先が無いのでnodeを作成
            if(!nodes[node_num][b]){
                nodes[node_num][b] = nodes.size();
                nodes.pb({});
                rem.pb(x);
            }
            node_num = nodes[node_num][b];
            rem[node_num] = min(rem[node_num], x);
        }
    }

    // x との XOR を最大化出来る値を見つける
    int query(int x, int lim){
        int ret = 0;
        int node_num = 0;
        for(int i=17; i>=0; --i){
            int b = !(x>>i&1);
            // bと同じ方向にあれば行きたい
            if(!nodes[node_num][b]) b = !b;

            // 無理
            if(!nodes[node_num][b]) return -1;

            // 妥協しないといけない
            if(ret+(b<<i) > lim || rem[ nodes[node_num][b] ]>lim) b = !b;

            // 無理
            if(!nodes[node_num][b] || ret+(b<<i) > lim) return -1;

            node_num = nodes[node_num][b];
            // --rem[node_num];
            ret |= b<<i;
        }
        // printf("x %d ret %d\n", x,ret);
        return ret;
    }
};
