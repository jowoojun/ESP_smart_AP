#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 100

// input time
struct itm
{
    int Shour;
    int Smin;
    int Lhour;
    int Lmin;
    int Ahour;
    int Amin;
    int AShour;
    int ASmin;
};


void time_set(struct tm * t , struct itm it){
    time_t curr;
    curr = time(NULL);
    t = localtime(&curr);

    //time_set
    while(1){
        curr = time(NULL);
        t = localtime(&curr);

        printf("time = %d:%d\n",t->tm_hour,t->tm_min); 
        // time set
        if(       (it.Shour <= t->tm_hour && t->tm_hour <= it.Lhour) && (it.Smin <= t->tm_min && t->tm_min < it.Lmin) ){
            
            printf("차단\n");
            system("sudo cp /usr/local/etc/e2guardian/lists/bannedsitelist_time /usr/local/etc/e2guardian/lists/bannedsitelist");

        }else if( (it.Lhour <= t->tm_hour && t->tm_hour <= it.Ahour) && (it.Lmin <= t->tm_min && t->tm_min < it.Amin) ){

            printf("허용\n");
            system("sudo cp /usr/local/etc/e2guardian/lists/bannedsitelist_off /usr/local/etc/e2guardian/lists/bannedsitelist");

        }else if( (it.Ahour <= t->tm_hour && t->tm_hour <= it.AShour) && (it.Amin <= t->tm_min && t->tm_min < it.ASmin) ){

            // disalbe internet
            printf("차단\n");
            system("sudo cp /usr/local/etc/e2guardian/lists/bannedsitelist_time /usr/local/etc/e2guardian/lists/bannedsitelist");

        }else{

            // enable internet
            printf("허용\n");
            system("sudo cp /usr/local/etc/e2guardian/lists/bannedsitelist_off /usr/local/etc/e2guardian/lists/bannedsitelist");
        }

        system("sudo e2guardian -q");
        system("sudo e2guardian");

        sleep(10);

    }
}

void makejson(int argc , char * argv[]){
    
    FILE * savetime = fopen("../info/time_set.json","w");
    if(!savetime){
        printf("cat not open time_set.json file\n");
    }

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

    return ;
}

int main( int argc, char* argv[] ){
    struct tm * t;

    struct itm  it;
    it.Shour = atoi(argv[1]);
    it.Smin = atoi(argv[2]);
    it.Lhour = atoi(argv[3]);
    it.Lmin = atoi(argv[4]);
    it.Ahour = atoi(argv[5]);
    it.Amin = atoi(argv[6]);
    it.AShour = atoi(argv[7]);
    it.ASmin = atoi(argv[8]);

    time_set(t,it);

    makejson(argc , argv);

    return 0;
}
