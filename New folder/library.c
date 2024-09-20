#include <stdio.h>
# define shelfs_container 10
# define pages_container 2

int main(){
    int library[shelfs_container][pages_container] = {{0,10},{0,0},  // {no_of_shelf, total_pages}
                                                      {0,20},{0,0},
                                                      {0,30},{0,0},
                                                      {0,0},{0,0},
                                                      {0,0},{0,0}}; // initialize with 0

    int type_of_query;
    scanf("%d", &type_of_query);

    while(1){
        if(type_of_query == 1){
            int no_of_shelf, total_pages;
            scanf("%d %d", &no_of_shelf, &total_pages);
            library[no_of_shelf][0] = total_pages;
        } 
        else if(type_of_query == 2){
            int count = 0;
            for (int i = 0; i < shelfs_container; i++){
                for (int j = 0; j < pages_container; j++){
                    if (library[i][j] > 0){
                    count++;
                    }
                }
            }
            printf("Total Books : %d", count);
        }
        else if(type_of_query == 3){
            break;
        }
        else{
            printf("Invalid Input");
        }
        printf("\nStored values in the library array:\n");
        for (int i = 0; i < shelfs_container; i++) {
            for (int j = 0; j < pages_container; j++) {
                if (library[i][j] != 0) {
                    printf("\nShelf %d Book Pages %d", i+1, library[i][j]);
                }
            }
        }
        
    }
}