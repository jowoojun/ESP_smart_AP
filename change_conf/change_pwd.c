#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 100

int main( int argc , char * argv[] ){
    
    FILE * orgin; // orgin file
    FILE * bak; // bakup file
        
    char str[MAX];

    char new_pwd[MAX];
    strcpy( new_pwd , argv[1] );

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
        
        if(strncmp( str , "wpa_passphrase=" , 15 ) == 0){
            // change ssid and write to bakup file
            strcpy(str , "wpa_passphrase=" );
            strcat(str , new_pwd );
            fprintf(bak , "%s\n" , str);
        }else{
            // write to bakup file
            fprintf(bak , "%s" , str);
        }
    
    }

    fclose(bak);
    fclose(orgin);
    
    system("sudo service hostapd restart");

    return 0;
}
