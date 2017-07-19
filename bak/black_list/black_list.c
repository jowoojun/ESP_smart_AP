#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    char flag[3];

    printf("internet on ot off :");
    scanf("%s",flag);
    printf("choose the ip address\n");
    system("arp -a");

    if( strcmp(flag , "on") == 0 ){
        
        // turn on the internet
        system("sudo ./allow.sh " );
        printf("turn on the internet\n");

    }else if( strcmp(flag , "off") == 0 ) {
        
        // turn off the internet
        system("sudo ./cut_off.sh " );
        printf("turn off the internet\n");
  
    }else {
        // error
        printf("error\n");
    }

    return 0;
}
