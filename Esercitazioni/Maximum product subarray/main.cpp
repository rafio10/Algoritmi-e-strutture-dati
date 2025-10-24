/*

Given an integer array nums, find a 
subarray
 that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

 

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 

Constraints:

1 <= nums.length <= 2 * 104
-10 <= nums[i] <= 10

Con programmazione dinamica
*/

#include <iostream>
#include <vector>

using namespace std;

#define N 100

int memo[N];

void initmemo(int dim){
    for(int i = 0; i < dim+1; i++){
            memo[i] = -1;
    }
}

int DP(int nums[], int dim, int i, int j){
    if(i>dim || j>dim){
        return 0;
    }

    if(memo[i] != -1){
        return memo[i];
    }

    int prod = nums[i]*nums[j];

    if(prod > 0){
        memo[i] = prod;
    }

    else{
        memo[i] = DP(nums, dim, i+1, j+1);
    }

    return memo[i];

}

int main(){
    int nTest;
    cin >> nTest;

    while(nTest--){
        int dim;
        cin >> dim;

        int nums[N];

        for(int i = 0; i < dim; i++){
            cin >> nums[i];
        }

        initmemo(dim);

        cout << DP(nums, dim-1, 0, 1) << endl;
    }
}