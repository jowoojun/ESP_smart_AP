#include <stdio.h>
int main(int argc, char * argv[]){
    FILE * adminjson = fopen("../info/admin_conf.json","w");
    if(!adminjson){
        printf("cat not open admin_conf.json file");
        return 0;
    }

    fprintf(adminjson , "{\n");
    fprintf(adminjson , "\"SSID\":\"%s\"\n" , argv[1]);
    fprintf(adminjson , ",\"password\":\"%s\"\n" , argv[2]);
    fprintf(adminjson , "}\n");
    
    return 0;
}
