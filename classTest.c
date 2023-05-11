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
            for(int k = 0; k < 600; k++){
                int array[k];
                for(int j = 0; j < k; j++){
                    array[j] = k-1;
                }
                
                for (int x = 1; x < k; x++) {
                    for (int y = 0; y < k - 1; y++) {
                        if (array[y] > array[y + 1]) {
                            int temp = array[y];
                            array[y] = array[y + 1];
                            array[y + 1] = temp;
                        }
                    }
                }
            }
            sleep(250);
            printf(1,"hello, i am son %d class %d \n", i, i%4);    
            exit();
        }
    }

    while(wait() != -1){;}
    exit();
    return 0;
}
