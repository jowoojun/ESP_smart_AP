#include <stdio.h>
#include <string.h>
#include <time.h>
#define MAX 100

void print_log(char * log_title){
    FILE * log;
    FILE * log_bak;
    char  nowtime[MAX];
    char str[MAX];
    time_t now_time;
    
    time(&now_time); 
    
    strcpy(nowtime , ctime(&now_time));
    nowtime[strlen(nowtime) -1 ] = '"';
    
    
    log = fopen("/home/pi/project/esp_smart_ap/info/log.json","r");
    if(!log){
        printf("log file can't open the file\n");
    }

    log_bak = fopen("/home/pi/project/esp_smart_ap/info/log.bak","w");
    if(!log_bak){
        printf("log_bak file can't open the file\n");
    }
    
    while(fgets()){
    }

    fclose(log);
    fclose(log_bak);
   
    return ;
}

int main( int argc , char * argv[] ){
    
    print_log(argv[1]);

    return 0;
}
