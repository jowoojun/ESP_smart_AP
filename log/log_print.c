#include <stdio.h>
#include <string.h>
#include <time.h>
#define MAX 100

void print_log(char * log){
    FILE * read;
    char str[MAX];
    time_t now_time;
    
    time(&now_time); 

    read = fopen("/home/pi/project/esp_smart_ap/log/log.txt","a");
    if(!read){
        printf("log file can't open the file\n");
    }

    strcpy(str,log);
    strcat(str," : ");
    strcat(str,ctime(&now_time));
    
    fprintf( read , "%s\n" , str );
    
    fclose(read);
   
    return ;
}

int main( int argc , char * argv[] ){
    
    print_log(argv[1]);

    return 0;
}
