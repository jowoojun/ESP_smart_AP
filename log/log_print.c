#include <stdio.h>
#include <string.h>
#include <time.h>
#define MAX 100

void print_log(char * log){
    FILE * read;
    char str[MAX];
    time_t time;

    read = fopen("~/project/log/log.txt","a");
    if(!read){
        printf("can't open the file\n");
    }

    strcpy(str,log);
    strcat(str," : ");
    strcat(str,ctime(&time));
    
    fprintf( read , "%s\n" , str );
    
    fclose(read);
   
    return ;
}

int main( int argc , char * argv[] ){
    
    print_log(argv[1]);

    return 0;
}
