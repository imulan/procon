#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

int gen(int p){
  int ret=p/2;
  if(p%2==1) ++ret;
  return ret;
}

int main(int argc, char const *argv[]) {
  int i;

  string s;
  cin >>s;

  //入力される数の桁数
  int n=s.size();

  //答えとなる数の桁数(n or n-1 ?)
  int m;

  bool found=false;
  vector<int> a;

  //まずn-1と仮定したら:
  m=n-1;
  //絶対に最上位で桁上りをするので最上位は1
  if(m>0 && s[0]=='1'){
    a.resize(m);

    int carry=0;
    //9じゃなければ繰り上がる
    if(s[n-1]!='9') carry=1;

    int val=10*carry+(s[n-1]-'0');
    //最上位と最下位決定
    a[0]=gen(val);
    a[m-1]=val-a[0];

    int left=1;
    int right=n-1;

    if(m==1){
      if(a[0]*2==atoi(s.c_str())) found=true;
    }
    else if(m==2){
      if(a[0]*11+a[1]*11==atoi(s.c_str())) found=true;
    }
    else{
      bool end=false;
      for(i=1; i<(m+1)/2; ++i){
        int nc=0;
        if(s[left]==s[right]) nc=0;
        else{
          if(s[right]=='9' && s[left]=='0') nc=1;
          else if(s[left]-s[right]==1) nc=1;
          else break;
        }

        int b=s[n-1-i]-'0'-carry;
        if(b<0) break;

        val=10*nc+b;
        //printf("i=%d, val=%d : carry=%d\n",i,val,carry);

        int t1=gen(val);
        int t2=val-t1;

        if(i==m-1-i && t1!=t2) break;
        else{
          a[i]=t1;
          a[m-1-i]=t2;
        }

        carry=nc;
        ++left;
        --right;

        if(i==(m+1)/2-1) end=true;
      }

      if(end) found=true;
    }
  }


  if(!found){
    //次にnと仮定したら:
    m=n;

    a.resize(m);

    int val=(s[n-1]-'0');
    //最上位と最下位決定
    a[0]=gen(val);
    a[m-1]=val-a[0];

    if(a[0]!=0){
      int carry=0;
      int nc=-1;
      if(s[0]-s[n-1]==0) nc=0;
      else if(s[0]-s[n-1]==1) nc=1;

      int left=1;
      int right=n-2;


      if(m==1){
        if(a[0]*2==atoi(s.c_str())) found=true;
      }
      else if(m==2){
        if(a[0]*11+a[1]*11==atoi(s.c_str())) found=true;
      }
      else{
        bool end=false;
        for(i=1; i<(m+1)/2; ++i){
          int b=s[n-1-i]-'0'-carry;
          if(b<0) break;

          val=10*nc+b;
          printf("i=%d, val=%d : carry=%d\n",i,val,carry);

          int t1=gen(val);
          int t2=val-t1;

          if(i==m-1-i && t1!=t2) break;
          else{
            a[i]=t1;
            a[m-1-i]=t2;
          }

          nc=0;
          if(s[left]==s[right]) nc=0;
          else{
            if(s[right]=='9' && s[left]=='0') nc=1;
            else if(s[left]-s[right]==1) nc=1;
            else break;
          }
          carry=nc;
          ++left;
          --right;

          if(i==(m+1)/2-1) end=true;
        }

        if(end) found=true;
      }
    }
  }

  //出力
  if(found){
    rep(i,(int)a.size()) printf("%d",a[i]);
    printf("\n");
  }
  else printf("0\n");
  return 0;
}
