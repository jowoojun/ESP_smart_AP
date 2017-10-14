#include <stdio.h>

void makejson(int argc , char * argv[]){
    
    FILE * savetime = fopen("../info/time_set.json","w");
    if(!savetime){
        printf("cat not open time_set.json file\n");
    }
    printf("make time_set.json\n");

    fprintf(savetime ,"{\n");
    fprintf(savetime ,"\"morning_hour\":\"%s\"\n",argv[1]);
    fprintf(savetime ,",\"morning_min\":\"%s\"\n",argv[2]);
    fprintf(savetime ,",\"afternoon_hour\":\"%s\"\n",argv[3]);
    fprintf(savetime ,",\"afternoon_min\":\"%s\"\n",argv[4]);
    fprintf(savetime ,",\"evening_hour\":\"%s\"\n",argv[5]);
    fprintf(savetime ,",\"evening_min\":\"%s\"\n",argv[6]);
    fprintf(savetime ,",\"after_hout\":\"%s\"\n",argv[7]);
    fprintf(savetime ,",\"after_min\":\"%s\"\n",argv[8]);
    fprintf(savetime ,",\"block_status_code\":\"%s\"\n",argv[9]);
    fprintf(savetime ,"}");
    
    fclose(savetime);
    return ;
}

int main( int argc , char * argv[]){
   
    makejson(argc , argv);
    
    return 0;
}
