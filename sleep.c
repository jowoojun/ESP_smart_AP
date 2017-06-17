#include <stdio.h>
int main (){
	int i = 0;
	for(i = 0 ; i < 3 ; i++){
		printf("I want to sleep \n");
	} 
	sleep(5);
	printf("good morning\n");
	return 0;
}
