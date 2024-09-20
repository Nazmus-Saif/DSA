#include <stdio.h>

int main(){
    int i, id, server[5][2] = {{1, 168},
                               {2, 0},
                               {3, 16},
                               {4, 60},
                               {5, 254}};
    printf("Enter Server ID : ");
    scanf("%d", &id);
    for(i = 0; i < 5; i++){
        if(id == server[i][0]){
            printf("Total User %d", server[i][1]);
        }
    }
    return 0;
}