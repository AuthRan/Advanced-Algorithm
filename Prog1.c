/*
Write a program to build a (binary) min-heap for a given set of numbers, A[0: n-1].
Design the following functions:
(a) MIN-HEAPIFY(A, i): to maintaining the min-heap property on ith node.
(b) BUILD-MIN-HEAP(A): produces a min-heap from an unordered input array A.
(c) MIN-HEAP-INSERT(A, x): to insert x into the heap A.
(d) EXTRACT-MIN(A): to extract (return and delete) minimum number (i.e., root)
from the heap A.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct{
    int *a;
    int size;
    int capacity;
}MinHeap;

//Helper functions
int left(int i) {
    return 2*i +1;
}
int right(int i) {
    return 2*i +2;
}
int parent(int i) {
    return (i-1)/2;
}
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Main functions
void min_heapify(MinHeap *h, int);
void build_heap(MinHeap *h);
void insert_heap(MinHeap *h, int);
int extract_min(MinHeap *h);

void print_heap(MinHeap *h) {
    printf("Heap array: ");
    for (int i = 0; i < h->size; i++)
        printf("%d ", h->a[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter how many elements you want to input initially: ");
    scanf("%d", &n);

    // Create heap
    MinHeap *h = (MinHeap*)malloc(sizeof(MinHeap));
    h->capacity = n + 20;
    h->size = n;
    h->a = (int*)malloc(sizeof(int) * h->capacity);

    // Input array
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &h->a[i]);

    // Build min-heap
    build_heap(h);
    printf("\nMin-heap created successfully!\n");
    print_heap(h);

    // Simple menu
    int choice, x;
    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Insert\n");
        printf("2. Extract Min\n");
        printf("3. Print Heap\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value to insert: ");
            scanf("%d", &x);
            insert_heap(h, x);
        }
        else if (choice == 2) {
            int m = extract_min(h);
            if (m != INT_MIN)
                printf("Extracted min = %d\n", m);
        }
        else if (choice == 3) {
            print_heap(h);
        }
        else break;
    }

    free(h->a);
    free(h);
    return 0;
}

void min_heapify(MinHeap *h, int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < h->size && h->a[l]<h->a[smallest]) {
        smallest = l;
    }
    if (r < h->size && h->a[r]<h->a[smallest]) {
        smallest = r;
    }
    if (smallest != i) {
        swap(&h->a[i], &h->a[smallest]);
        min_heapify(h, smallest);
    }
}

void build_heap(MinHeap *h) {
    for (int i = (h->size / 2) -1; i >= 0; i--){    //Problem comes usually here
        min_heapify(h, i);
    } 
}

void insert_heap(MinHeap *h, int x) {
    if (h->size == h->capacity) {
        printf("Heap is full!\n");
        return;
    }
    int i = h->size;
    h->a[i] = x;
    h->size += 1;
    while (i > 0 && h->a[parent(i)] > h->a[i]) {
        swap(&h->a[parent(i)], &h->a[i]);
        i = parent(i);
    }
}   

int extract_min(MinHeap *h) {
    if(h->size < 1) {
        printf("No eleemnt in Heap!");
        return INT_MIN;
    }
    int min = h->a[0];
    h->a[0] = h->a[(h->size-1)];
    h->size -= 1;
    min_heapify(h, 0);
    return min;
}


