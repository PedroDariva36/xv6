#include "types.h"
#include "stat.h"
#include "user.h"

int main(){
    int n = 36;
    int pids[n];
    //int wpid;

    int i;

    for (i = 0; i < n; i++) {
        if ((pids[i] = fork(i % 4)) < 0) {
            printf(1,"Oh no! \n");
        }

        else if (pids[i] == 0) {
            sleep(250);
            printf(1,"Hello, I am son %d class %d, and I am eating! \n", i, i%4); 
            sleep(250); 
            exit();
        }
    }

    while(wait() != -1){;}
    exit();
    return 0;
}
