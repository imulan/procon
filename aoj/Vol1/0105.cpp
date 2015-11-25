#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

typedef struct{
	string word;	
	int page[100];
	int now;
}list;

int main(){
	list a[100];
	int b=0;
	
	string s;
	int n;
	
	while( cin >> s >> n ){
		
		bool find=false;
		for(int i=0; i<b; ++i){
			if(a[i].word==s){
				a[i].page[ a[i].now ]=n;
				a[i].now++;
				find=true;		
			}
		}	
		
		if( !find ){
			a[b].word=s;
			a[b].page[0]=n;
			a[b].now=1;
			b++;
		}	
		
	}
	
	for(int i=0; i<b; ++i) sort(a[i].page, a[i].page+a[i].now);	
		
	for(int i=0; i<b; ++i){
		for(int j=i; j<b; ++j){
			if(a[i].word > a[j].word) swap(a[i], a[j]);
		}	
	}	
	
	for(int i=0; i<b; ++i){
		cout << a[i].word << endl;	
		for(int j=0; j<a[i].now; ++j){
			if(j>0) printf(" ");
			printf("%d", a[i].page[j]);	
		}
		printf("\n");
	}
	
}