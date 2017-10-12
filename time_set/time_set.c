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

            // disalbe internet
            system("sudo e2gaurdian -q");

        }else if( (it.Lhour <= t->tm_hour && t->tm_hour <= it.Ahour) && (it.Lmin <= t->tm_min && t->tm_min < it.Amin) ){

            // enable internet
            system("sudo e2gaurdian");

        }else if( (it.Ahour <= t->tm_hour && t->tm_hour <= it.AShour) && (it.Amin <= t->tm_min && t->tm_min < it.ASmin) ){

            // disalbe internet
            system("sudo e2gaurdian -q");

        }else{

            // enable internet
            system("sudo e2gaurdian");

        }

        sleep(10);

    }
}

void savetime(int ac , char * av[]){

    FILE * timedata; 
    timedata = fopen("./savetime","w");

    int i;

    for( i=1 ; i < ac ; i++){
        fprintf(timedata , "%s\n" , av[i]);
    }

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

    savetime(argc,argv);

    time_set(t,it);

    return 0;
}
