// problem : https://www.acmicpc.net/problem/1463
#include <iostream>
#include <vector>
#include <climits>

int main(){
    int target;

    std::cin >> target;

    std::vector<int> memo(target+1, INT_MAX);
    memo[1] = 0;

    for(int cur_target=1; cur_target<=target; cur_target++){

        if(2*cur_target <= target){
            if(memo[2*cur_target] > memo[cur_target]+1){
                memo[2*cur_target] = memo[cur_target]+1;
            }
        }

        if(3*cur_target <= target){
            if(memo[3*cur_target] > memo[cur_target]+1){
                memo[3*cur_target] = memo[cur_target]+1;
            }
        }

        if(cur_target+1 <= target){
            if(memo[cur_target+1] > memo[cur_target]+1){
                memo[cur_target+1] = memo[cur_target]+1;
            }
        }
    }

    std::cout << memo[target];
}