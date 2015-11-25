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
  int n;
  int nums[100002]={0};

  //input
  cin >> n;

  vector< pair<int,int> > t(n); //(終了時刻,開始時刻)<-終了が早い順にソートしたい

  for(int i=0; i<n; ++i){
    scanf(" %d %d", &t[i].second, &t[i].first);
    nums[t[i].first]--;
    nums[t[i].second]++;
    //t[i].second = -t[i].second;
  }

  int big=0;
  for(int i=0; i<=100000; ++i){
    nums[i+1] += nums[i];
    big = max(big,nums[i+1]);
  }

  int bigL=100000,bigR=0;
  for(int i=1; i<=100000; ++i){
    if(big == nums[i]){
      bigL = min(bigL,i);
      bigR = max(bigR,i);

    }
  }

  //printf("big=%d, L=%d, R=%d\n", big, bigL, bigR);

  //これを包括する区間があればそれを除けば良い、２つ以上あるとダメ、なければbigが答え？
  bool found=false;
  bool elim=true;
  for(int i=0; i<n; ++i){
    if(t[i].second<=bigL && bigR+1<=t[i].first){
      if(!found) found=true;
    }
  }

  if(found) big--;
  printf("%d\n", big);

  //sort(t.begin(), t.end());

  /*
  int kanou[100000]={0};

  int ans=n-1;
  //必要人数を2分探索
  int left=1, right=n-1;
  int mid;
  int prev=-1;
  while(right-left>=0){
    mid=(left+right)/2;

    if(prev==mid) break;
    //mid人でn-1点獲得できるかシミュレーションする
    int tmp=0;
    bool trash=false;
    bool ok=true;

    queue< pair<int,int> > que; //今ボタンを押している人がその場を離れられる時間を入れておく
    for(int i=0; i<n; ++i){
      if(que.size()==mid){ //全員ボタンを押した状態の時
        if(que.front().first <= t[i].second){ //一番早く終わる人が手を回せる
          que.pop();
          que.push(t[i]);
        }
        else{ //無理なら捨てる、既に捨てられていたら不可
          if(!trash) trash=true;
          else{
            ok=false;
            break;
          }
        }
      }
      else{ //手が空いている人がいるので押す
        que.push(t[i]);
      }
    }

    if(ok){
      kanou[mid] = 1;
      right=mid;
    }
    else{
      kanou[mid] = 123;
      left=mid+1;
    }

    if(ok) ans=min(ans,mid);
    //printf("%d : %d\n",mid, ok);
    prev=mid;
  }

  int output;
  for(int i=1; i<n; ++i){
    if(kanou[i]==1){
      output=i;
      break;
    }
  }
  printf("%d\n", output);
  */

}
