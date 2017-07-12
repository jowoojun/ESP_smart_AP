#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    char temp[10];
    
    // input
    printf("internet control(enable or disable): ");
    scanf("%s",temp);

    // 
    if( strcmp( temp , "enable" ) == 0 ){
        
        // enable
        system("sudo ./enable_internet.sh");
        printf("enalbe internet\n");

    }else if(strcmp( temp , "disable" ) == 0){
        
        // disable
        system("sudo ./disable_internet.sh");
        printf("disable internet\n");

    }else {
        printf("input error\n");
    }

    return 0;
}
