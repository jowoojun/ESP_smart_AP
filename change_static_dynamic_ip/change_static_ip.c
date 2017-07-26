#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int main(void){
    
    FILE * bak;
    FILE * origin;
    char str[MAX];

    // open the bak file
    bak = fopen("/etc/network/interfaces.bak" , "w");
    if(!bak){
        printf("can't open the bakup file\n");
        return 0;
    }

    //open the origin file
    origin = fopen("/etc/network/interfaces","r");
    if(!origin){
        printf("cat't open the origin file\n");
        return 0;
    }
    
    // change dydnamic to static ip
    while ( fgets(str , MAX ,origin) != NULL ){
        if( !strncmp("iface wlan0 inet dhcp", str, 21 ) ){
            
            strcpy(str,"iface wlan0 inet");
            strcat(str," static\n");
            fprintf(bak,str);
            fprintf(bak, "address \n");
            fprintf(bak, "netmask \n");
            fprintf(bak, "gateway \n");
            break;

        }else {
     
            fprintf(bak,str);
        
        }
    }

    //print the log for client
    printf("유동ip에서 고정ip로 변경 하였습니다\n");

    return 0;
}
