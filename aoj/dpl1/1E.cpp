#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
	string s1,s2;
	cin >> s1 >> s2;
	
	//d[i][j]:=文字列s1の1文字目~i文字目までの部分文字列と文字列s2の1文字目~j文字目までの部分文字列の編集距離
	//(indexが0の部分は空の文字列を表す)
	int d[1001][1001]={0};
	
	//どちらかの長さが0なら、その時は挿入か削除を続けるのが最適
	for(int i=0; i<=s1.size(); ++i) d[i][0]=i;
	for(int i=0; i<=s2.size(); ++i) d[0][i]=i;
	
	for(int i=1; i<=s1.size(); ++i){
		for(int j=1; j<=s2.size(); ++j){
			int tmp = d[i-1][j-1];
			if(s1[i-1]!=s2[j-1]) tmp++;
			
			d[i][j] = min(tmp, min(d[i-1][j]+1,d[i][j-1]+1));
		}
	}
	
	printf("%d\n", d[s1.size()][s2.size()]);
}