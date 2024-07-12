// problem : https://www.acmicpc.net/problem/1003
#include <iostream>
#include <vector>


int main(){
    int test_num;

    std::cin >> test_num;

    for(int i=1; i<=test_num; i++){
        int target_num;
        std::cin >> target_num;

        std::vector<int> zero_call(target_num + 1,0);
        std::vector<int> one_call(target_num + 1, 0);

        zero_call[0] = 1;
        zero_call[1] = 0;

        one_call[0] = 0;
        one_call[1] = 1;

        if(target_num==0){
            std::cout << zero_call[0] << " " << one_call[0] << std::endl;
            continue;
        }
        else if(target_num==1){
            std::cout << zero_call[1] << " " << one_call[1] << std::endl;
            continue;
        }

        for(int i=2; i<=target_num; i++){
            zero_call[i] = zero_call[i-1] + zero_call[i-2];
            one_call[i] = one_call[i-1] + one_call[i-2];
        }

        std::cout << zero_call[target_num] << " " << one_call[target_num] << std::endl;

    }
}