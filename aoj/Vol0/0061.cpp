#include <cstdio>
#include <iostream>
using namespace std;

typedef struct{
	int no;
	int score;
	int rank;
}team;

int main(){
	team t[100];
	int a=0;
	while(1){
		scanf(" %d,%d", &t[a].no, &t[a].score);
		if(t[a].no==0 && t[a].score==0) break;
		a++;
	}
	
	for(int i=0; i<a; ++i){
		for(int j=i; j<a; ++j){
			if(t[i].score < t[j].score) swap(t[i], t[j]);		
		}
	}

	
	int now=1, sc=t[0].score;
	t[0].rank=now;
	for(int i=1 ;i<a; ++i){
		if(t[i].score==sc) t[i].rank=now;
		else{
			++now;
			t[i].rank=now;
			sc=t[i].score;
		}
	}

	//for(int i=0; i<a; ++i) printf("%d: %d, rank=%d\n", t[i].no, t[i].score, t[i].rank);
	
	int x;
	while(cin >> x){
		for(int i=0; i<a; ++i){	
			if(x == t[i].no){
				printf("%d\n", t[i].rank);
				break;
			}
		}
	}

	return 0;
}