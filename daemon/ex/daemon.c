#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#define MAX 100

void signalhandler( int signal){
    FILE *  run;
    char str[MAX];

    run = fopen("/home/pi/changgunLEE/esp_smart_ap/daemon/ex/date.json" ,"r");
    if(!run){
       printf("can't open the JSON file \n");
    }

    while(fscanf){
    
    }
    
    




}

int main(){
    while(1){
        signal( SIGUSR1 , signalhandler );
    }
}
