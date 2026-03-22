#include <stdio.h>
#include <stdlib.h>



//given an array and a target number, return the first combination of numbers that add up to the target

int main(){
    int numsSize = 0;
    int target = 0;
    printf("Enter the size of the list: ");
    scanf("%d", &numsSize);
    int *nums = malloc(numsSize * sizeof(int));
    int *returnSize = malloc(2 * sizeof(int));
    for(int i = 0; i < numsSize; i++){
        printf("\nEnter number #%d: ", i +1);
        scanf("%d", &nums[i]);
    }
    printf("\nEnter the target: ");
    scanf("%d", &target);
    for(int i = 0; i < numsSize; i++){
        for(int j = i +1; j < numsSize; j++){
            if(nums[i]+nums[j] == target){
                printf("\n");
                printf("%d %d", nums[i], nums[j]);
                return 0;
            }
        }
    }
    
    free(nums);
    nums = NULL;
    free(returnSize);
    returnSize = NULL;



    return 0;
}
