#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {5,4,3,2};
    int size = nums.size();
    int repeated,missing =0;

    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(i!=j){
                if(nums[i]==nums[j]){
                    repeated = nums[i];
                }
            }
        }
    }
    for (int i=0;i<size;i++){
        if(nums[i]!=i){
            missing = i;
        }
    }

    cout<<repeated<<" " <<missing<<endl;
    
    return 0;
}
