#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
#include <iterator>
using namespace std;

typedef long long ll;
#define foreach(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)

int main(){
  int n;
  cin >> n;

  vector<int> a(n);
  for(int i=0; i<n; ++i) cin >> a[i];


  //初期化
  int tak=-10000;

  for(int i=0; i<n; ++i){ //高橋くんが丸をつける位置
    //初期化
    int ao=-10000;
    int tak_tmp;
    for(int j=0; j<n; ++j){ //青木くんが丸をつける位置
      if(i==j) continue;

      int p=i, q=j;
      if(p>q) swap(p,q); //必ずp<q

      //切り出す
      vector<int> tmp;
      copy(a.begin()+p, a.begin()+q+1, back_inserter(tmp));

      int t_tak=0, t_ao=0;
      for(int k=0; k<tmp.size(); ++k){
        if(k%2==0) t_tak+=tmp[k];
        else t_ao+=tmp[k];
      }

      if(ao < t_ao){
        ao=t_ao;
        tak_tmp = t_tak;
      }
    }

    tak = max(tak,tak_tmp);
  }

  printf("%d\n", tak);
}
