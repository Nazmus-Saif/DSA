#include <stdio.h>
#include <stdlib.h>

int *total_number_of_books;
int **total_number_of_pages;

int main()
{
    int total_number_of_shelfs;
    scanf("%d", &total_number_of_shelfs);
    
    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);
    
    // Initialize total_number_of_books and total_number_of_pages arrays
    total_number_of_books = (int*)malloc(total_number_of_shelfs * sizeof(int));
    total_number_of_pages = (int**)malloc(total_number_of_shelfs * sizeof(int*));
    for (int i = 0; i < total_number_of_shelfs; i++) {
        total_number_of_books[i] = 0;
        total_number_of_pages[i] = NULL;
    }
    
    while (total_number_of_queries--) {
        int type_of_query;
        scanf("%d", &type_of_query);
        
        if (type_of_query == 1) {  // add book
            int x, y;
            scanf("%d %d", &x, &y);
            // Increase the number of books on the shelf x
            total_number_of_books[x]++;
            // Resize the array for pages if necessary
            total_number_of_pages[x] = (int*)realloc(total_number_of_pages[x], total_number_of_books[x] * sizeof(int));
            // Insert the number of pages of the new book at the end of the shelf x
            total_number_of_pages[x][total_number_of_books[x] - 1] = y; 
            // total_number_of_pages[x]: This part of the expression is accessing the array of integers representing the number of pages in each book on shelf x. It's a 1D array (pointer to an array of integers) that holds the page counts for all books on shelf x.
            // [total_number_of_books[x] - 1] : This part of the expression calculates the index of the last book on shelf x. Since array indices start from 0, and total_number_of_books[x] represents the total number of books on shelf x, subtracting 1 ensures that we access the index of the last book in the array.
        } else if (type_of_query == 2) {  // query for 
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", *(*(total_number_of_pages + x) + y));
        } else {
            int x;
            scanf("%d", &x);
            printf("%d\n", *(total_number_of_books + x));
        }
    }

    if (total_number_of_books) {
        free(total_number_of_books);
    }
    
    for (int i = 0; i < total_number_of_shelfs; i++) {
        if (*(total_number_of_pages + i)) {
            free(*(total_number_of_pages + i));
        }
    }
    
    if (total_number_of_pages) {
        free(total_number_of_pages);
    }
    
    return 0;
}


// 1st line no of shelf
// 2nd line no of query

// query type 1, no of shelf, no of page => it add the book on the given shelf with the given page no
// query type 2, no of shelf, no of book => it return the total page no of the given book on the given shelf
// query type 3, no of shelf => it return total number of book on a given shelf