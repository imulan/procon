#include <stdio.h>
#include <string.h>

typedef struct{
	char name[30];
	int win;
	int prior;
}team;

void swap(team *p, team *q){
	team tmp = *p;
	*p = *q;
	*q = tmp;
}

int main(void){
	int flag=0;


	while(1){
		int n, i, j, x, y, z;
		char c[30];
		team t[10];
						
		scanf(" %d", &n);
		if(n==0) break;
		
		if(flag==1) printf("\n");

	
		for(i=0; i<n; i++){
			scanf(" %s", c);
			strcpy(t[i].name, c);
			t[i].prior=i;

			scanf(" %d %d %d", &x, &y, &z);
			t[i].win = 3*x + z;
		}
		
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				if( (t[i].win > t[j].win) ||  (t[i].win==t[j].win && t[i].prior < t[j].prior) )
					swap(&t[i], &t[j]);
			}
		}
	
		for(i=0; i<n; i++)
			printf("%s,%d\n", t[i].name, t[i].win);
		
		flag=1;
	}

	return 0;
}