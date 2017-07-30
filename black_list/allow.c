#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

void log_print(){
    FILE * log; // log file
    
    // open the log file
    log = fopen("/home/ap_log/ap_system.log" ,"a");
    if(!log){
        printf("log file open fail\n");
        return ;
    }

    fprintf(log,"%s\n","\"블랙리스트설정-허용\"");
    
    fclose(log);

    return ;
}


int main( void ){
    
    FILE * origin; // orgin file
    FILE * bak ; // bakup file

    char str[MAX];

    // make the list.bak  file
    bak = fopen("/home/pi/changgunLEE/esp_smart_ap/black_list/list.bak" , "w");
    if(!bak){
        printf("bakup file open fail\n");
        return 0;
    }
    
    // open the list.sh file
    origin = fopen("/home/pi/changgunLEE/esp_smart_ap/black_list/list.sh" , "r");
    if(!origin){
        printf("orgin file open fail\n");
        return 0;
    }

    // write the bakup
    while ( fgets(str , MAX , origin) != NULL){
        
        if( strncmp( str , "iptables -A" , 11 ) == 0 ){
            // change iptalbes 
            strcpy(str , "");
            fprintf(bak , "%s" , str);
        }else {
            // write to bakup file
            fprintf(bak , "%s" , str);
        }
    
    }

    // close the files
    fclose(origin);
    fclose(bak);

    // log print
    log_print();

    return 0;
}
