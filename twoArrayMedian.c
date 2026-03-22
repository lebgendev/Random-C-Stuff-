#include <stdio.h>
#include <stdlib.h>

void findMedianSortedArrays(int nums1[], int nums1Size, int nums2[], int nums2Size);
int main(){

    int nums1[3] = {1, 2, 3};
    int nums1Size = 3;
    int nums2[3] = {4, 5, 6};
    int nums2Size = 3;
    findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);

    return 0;
}


void findMedianSortedArrays(int nums1[], int nums1Size, int nums2[], int nums2Size){
    int *mergedList = malloc( (nums1Size + nums2Size) * sizeof(int));
    int sum = 0;
    float newSize = nums1Size + nums2Size;
    for(int i = 0; i < newSize; i++){
        if(i < nums1Size){
            mergedList[i] = nums1[i];
        } else {
            mergedList[i] = nums2[i - nums1Size];
        }
    }

    for(int i = 0; i < newSize; i++){
        printf("%d ", mergedList[i]);
    }

    for(int i =0; i < newSize; i++){
        sum += mergedList[i];
        printf("%d ", sum);
    }
    int median = sum/newSize;
    printf("\n%.2f", median);
    free(mergedList);
    mergedList = NULL;
}