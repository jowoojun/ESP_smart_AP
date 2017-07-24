#include<stdio.h>
#include<signal.h>

void signalhandler(int signal){
    FILE *fp;
    int a;

    fp = fopen("./abc.txt","r+");
    fscanf(fp, "%d", &a);
    
    if(a == 1){
        printf("%d\n",a);
    }else{
        printf("와우\n");
    }
    fclose(fp);
    
    //printf("hello\n");
}

int main(void){
    while(1){
        signal( SIGUSR1 , signalhandler );
    }
}

