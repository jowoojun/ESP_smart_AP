#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100


void tojson(){
    
    FILE * log; // log txt
    FILE * json; // log.json

    char str[MAX][MAX] = {""};
    
    int i;
    int k;
    
    // open the file log.txt
    log = fopen("/home/ap_log/ap_system.log" , "r");
    if(!log){
        printf("can't open the filei\n");
        return ;
    }

    // open the file log.json
    json = fopen("/home/ap_log/log.json" , "w");
    if(!json){
        printf("can't open the json file\n");
        return ;
    }
    
    // have to choose the way fscanf or fgets
    for( i = 0 ; fscanf( log, "%s", str[i]) != EOF  ;i++);
   
    // write the log.json file
    fprintf( json ,"{\n");
    fprintf( json ,"\t\"log\": [\n");

    for( k = 0 ; k < i-1 ; k++){
        
        fprintf(json ,"\t\t%s,\n", str[k]);

    }
    
    fprintf(json ,"\t\t%s\n", str[k]);
    fprintf(json ,"\t]\n");
    fprintf(json ,"}\n");

    // clean the ap_system.log file
//    fprintf(log,"");

    fclose(log);
    fclose(json);
   
    return ;

}

int main(void){

    tojson();

    return 0;

}
