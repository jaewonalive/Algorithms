// problem : https://www.acmicpc.net/problem/9095
#include <vector>
#include <iostream>

int main(){
    int test_num;

    std::cin >> test_num;

    for(int i=0; i<test_num; i++){
        int target_num;

        std::cin >> target_num;
        
        std::vector<int> memo(target_num+1, 0);
        
        memo[1] = 1;

        if(target_num == 1){
            std::cout << 1 << std::endl;
            continue;
        }
        else if(target_num==2){
            std::cout << 2 << std::endl;
            continue;
        }
        else if(target_num==3){
            std::cout << 4 << std::endl;
            continue;
        }

        memo[2] = 2;
        memo[3] = 4;

        for(int n=4; n<=target_num; n++){
            memo[n] = memo[n-1] + memo[n-2] + memo[n-3];
        }
        std::cout << memo[target_num] << std::endl;
    }
}