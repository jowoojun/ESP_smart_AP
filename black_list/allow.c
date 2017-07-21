#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

int main( void ){
    
    FILE * orgin; // orgin file
    FILE * bak ; // bakup file

    char str[MAX];

    // make the rc_local.bak file
    bak = fopen("/home/pi/changgunLEE/esp_smart_ap/black_list/list.bak" , "w");
    if(!bak){
        printf("bakup file open fail\n");
        return 1;
    }
    
    // open the rc.local
    orgin = fopen("/home/pi/changgunLEE/esp_smart_ap/black_list/list.sh" , "r");
    if(!orgin){
        printf("orgin file open fail\n");
        return 1;
    }

    // write the bakup
    while ( fgets(str , MAX , orgin) != NULL){
        
        if( strncmp( str , "iptables -A" , 11 ) == 0 ){
            // change iptalbes 
            strcpy(str , "");
            fprintf(bak , "%s" , str);
        }else {
            // write to bakup file
            fprintf(bak , "%s" , str);
        }
    
    }
    return 0;
}
