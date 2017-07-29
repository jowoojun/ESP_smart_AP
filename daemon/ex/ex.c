#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

int main(){
    FILE * run;
    char str[MAX];
    run = fopen("/home/pi/changgunLEE/esp_smart_ap/daemon/ex/date.json","r");

    while(fscanf(run,"%s",str)){
        printf("%s\n",str);
        if(strcmp(str,"}") == 0){
            break;   
        }
    }

    return 0;
}
