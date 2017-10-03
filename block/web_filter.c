#include <stdio.h>
#include <string.h>
// 필터링을 할부분과 
// 필터링에서 제외할 할수가 필요함
// 두가지 유형이 있는데 
// 지금은 한가지 유형만 만들어 놓은 상태
// 따리서 신호가 두가지 여야됨
// 빼는 친구들 
// 더하는 친구들이 있어야함

void inster_filter(char * category){
    
    FILE * bannedsitelist;
    bannedsitelist = fopen("/usr/local/etc/e2guardian/list/bannedlistsite","r+a");
    


}

void delete_filter(char * category){



}



int main(int argc ,char * argv[]){
    
    for(int i  = 1 ; i < argc ; i++){
        change_filter(argv[i]);
    }

    return 0;
}
