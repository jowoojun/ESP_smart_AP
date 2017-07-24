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
    
    // change static to dynamic ip
    while ( fgets(str , MAX ,origin) != NULL ){
        if( !strncmp("iface wlan0 inet static", str, 21 ) ){
            
            strcpy(str,"iface wlan0 inet");
            strcat(str," dhcp");
            fprintf(bak,str);
            break;

        }else {
     
            fprintf(bak,str);
        
        }
    }

    //print the log for client
    printf("고정ip에서 유동ip로 변경 하였습니다\n");

    return 0;
}
