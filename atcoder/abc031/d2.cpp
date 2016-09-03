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
using namespace std;

typedef long long ll;
#define foreach(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)

int main(){
  int k,n;
  cin >> k >> n;
  vector< pair<string,string> > dic(n);

  for(int i=0; i<n; ++i){
    string x,y;
    cin >> x >> y;
    dic[i].first = x;
    dic[i].second = y;
  }

  vector<string> s(k+1);

  //それぞれs[i]の長さを決め打ち(1~3)のbitloop
  for(int i=0; i<pow(3,k); ++i){ //全状態
    //初期化
    for(int j=1; j<=k; ++j) s[j]="-";

    //s[j]の長さ
    int len[10]={0};
    int t=i;
    for(int j=1; j<=k; ++j){
      int zz=(t+1)%3;
      if(zz==0) zz=3;
      len[j]=zz;
      t/=3;
    }

    bool valid=true;
    foreach(it,dic){ //まず登録された文字に対して、長さが合致しているか
      string num = it->first;
      string key = it->second;
      int L=0;
      for(int j=0; j<num.size(); ++j){
        L+=len[num[j]-'0'];
      }

      if(L!=key.size()){
        valid=false;
        break;
      }
    }

    if(valid){
      //答え作成
      foreach(it,dic){
        string num = it->first;
        string key = it->second;
        int L=0;
        for(int j=0; j<num.size(); ++j){
          string tt = key.substr(L,len[num[j]-'0']);

          if(s[num[j]-'0'] == "-") s[num[j]-'0'] = tt;
          else{
            if(s[num[j]-'0'] != tt){ //既に登録されていて、一致しないとダメ
              valid=false;
              break;
            }
          }
          L+=len[num[j]-'0'];
        }
        if(!valid) break;
      }

    }

    if(valid) break;
  }

  //出力
  for(int i=1; i<=k; ++i) cout << s[i] << endl;

}
