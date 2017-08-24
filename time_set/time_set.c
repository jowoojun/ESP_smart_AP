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


int main( int argc, char* argv[] ){
    
    time_t curr;
    struct tm * t;
    curr = time(NULL);
    t = localtime(&curr);

    struct itm  it;
    it.Shour = atoi(argv[1]);
    it.Smin = atoi(argv[2]);
    it.Lhour = atoi(argv[3]);
    it.Lmin = atoi(argv[4]);
    it.Ahour = atoi(argv[5]);
    it.Amin = atoi(argv[6]);
    it.AShour = atoi(argv[7]);
    it.ASmin = atoi(argv[8]);

    char enable_internet[MAX];
    strcpy( enable_internet,"sudo sysctl -w net.ipv4.ip_forward=1" );
    char disable_internet[MAX];
    strcpy( disable_internet,"sudo sysctl -w net.ipv4.ip_forward=0" );

    //time_set
    while(1){
        curr = time(NULL);
        t = localtime(&curr);

        printf("time = %d:%d\n",t->tm_hour,t->tm_min); 
        // time set
        if(       (it.Shour <= t->tm_hour && t->tm_hour <= it.Lhour) && (it.Smin <= t->tm_min && t->tm_min < it.Lmin) ){

            // disalbe internet
            printf("1\n");
            system(disable_internet);

        }else if( (it.Lhour <= t->tm_hour && t->tm_hour <= it.Ahour) && (it.Lmin <= t->tm_min && t->tm_min < it.Amin) ){

            // enable internet
            printf("2\n");
            system(enable_internet);

        }else if( (it.Ahour <= t->tm_hour && t->tm_hour <= it.AShour) && (it.Amin <= t->tm_min && t->tm_min < it.ASmin) ){

            // disalbe internet
            printf("3\n");
            system(disable_internet);

        }else{

            // enable internet
            printf("4\n");
            system(enable_internet);

        }

        sleep(10);

    }

    return 0;
}
