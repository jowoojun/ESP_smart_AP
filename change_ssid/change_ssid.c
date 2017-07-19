#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 100

int main( int argc , char * argv[] ){
    
    FILE * orgin; // orgin file
    FILE * bak; // bakup file
        
    char str[MAX];

    char new_ssid[MAX];
    strcpy( new_ssid , argv[1] );

    // make the hostapd.bak file
    bak = fopen("/etc/hostapd/hostapd.bak","w");
    if( !bak ){
        printf("bakup file open fail\n");
        return 1;
    }
    
    // open the hostapd.conf file
    orgin = fopen("/etc/hostapd/hostapd.conf","r");
    if( !orgin ){
        printf("orgin file open fail\n");
        return 1;
    }
    
    // write the bakup
    while( fgets(str , MAX , orgin) != NULL ){
        
        if(strncmp( str , "ssid=" , 5 ) == 0){
            // change ssid and write to bakup file
            strcpy(str , "ssid=" );
            strcat(str , new_ssid );
            fprintf(bak , "%s" , str);
        }else{
            // write to bakup file
            fprintf(bak , "%s" , str);
        }
    
    }

    fcloseall();

    // write the log
    printf("와이파이 이름 변경\n");

    return 0;
}
