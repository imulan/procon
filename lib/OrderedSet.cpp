#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

template<class Key>
using ordered_set = __gnu_pbds::tree<Key, __gnu_pbds::null_type, less<Key>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

// multisetではないので注意．適当にindex貼ったりする必要がある．あと定数倍重い．
// find_by_order(idx)
// order_of_key(key)  ... lower_bound
