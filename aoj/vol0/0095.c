#include <stdio.h>

typedef struct{
	int num;
	int sc;
}person;

int main(void){
	int n, i, max=0, ans=0;
	person p[20];

	scanf("%d", &n);
	for(i=0; i<n; i++)
		scanf(" %d %d", &p[i].num, &p[i].sc);
	
	for(i=0; i<n; i++){
		if( (max < p[i].sc) || (max == p[i].sc && p[i].num < p[ans].num) ) {
			max = p[i].sc;
			ans = i;
		}
	}
	
	printf("%d %d\n", p[ans].num, p[ans].sc);

	return 0;
}