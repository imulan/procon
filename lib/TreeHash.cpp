const int N = 100000;
vector<int> G[N];

map<vector<int>,int> h2id;

int tree_hash(int v, int par){
    vector<int> hs;
    for(int ch:G[v])if(ch!=par){
        hs.pb(tree_hash(ch,v));
    }
    sort(all(hs));

    if(!h2id.count(hs)) h2id[hs] = h2id.size();
    return h2id[hs];
}
