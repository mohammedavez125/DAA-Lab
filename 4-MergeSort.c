#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

void mergesort(int a[], int low, int high);
void merge(int a[], int low, int mid, int high);

int main() {
    int a[SIZE], n;
    clock_t start, end;
    
    start = clock();
    
    printf("MERGE SORT\n\nEnter the number of elements: ");
    scanf("%d", &n);

    printf("Elements of the array before sorting:\n");
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 1000;
        printf("%d\t", a[i]);
    }
    
    mergesort(a, 0, n - 1);
    
    printf("\nElements of the array after sorting:\n");
    for (int i = 0; i < n; i++)
        printf("%d\t", a[i]);
    
    end = clock();
    printf("\nTime taken = %.2f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    
    return 0;
}

void mergesort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

void merge(int a[], int low, int mid, int high) {
    int b[SIZE], i = low, j = mid + 1, k = low;
    
    while (i <= mid && j <= high) {
        b[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];
    }
    
    while (i <= mid) b[k++] = a[i++];
    while (j <= high) b[k++] = a[j++];
    
    for (i = low; i <= high; i++) a[i] = b[i];
}
