//
//  main.c
//  LeetCode-C
//
//  Created by GiantAxe on 18/4/13.
//  Copyright © 2018年 GiantAxe. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}

// leetcode 371-1
int getSum(int a, int b) {
    if (b == 0) {
        return a;
    }
    return getSum(a^b,(a&b)<<1);
}

// leetcode 371-2
int getSum1(int a, int b) {
    int tmp = (a&b)<<1;
    if (tmp == 0) {
        return a^b;
    }
    return getSum(a^b,tmp);
}


// leetcode 1-1
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int *result = (int*)malloc(2*sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        for (int j = i+1; j < numsSize; j++) {
            int tmp1 = nums[i];
            int tmp2 = nums[j];
            if (tmp1 + tmp2 == target) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return result;
}


// leetcode 1-2
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum2(int* nums, int numsSize, int target) {
    int min = 0x1.fffffep+127f;
    for (int i = 0; i < numsSize; i++) { // 找到最小值
        if (min > nums[i]) {
            min = nums[i];
        }
    }
    int remainder = target - min;
    int length = remainder - min + 1;
    
    int *result = (int *)malloc(2 * sizeof(int));
    int *table = (int *)malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) { // 初始化
        table[i] = -1;
    }
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i]-min < length) {
            if (table[target - nums[i] - min] != -1) {
                result[0] = table[target - nums[i] - min];
                result[1] = i;
                return result;
            }
            table[nums[i]-min] = i;
        }
    }
//    free(table);
    return result;
}
