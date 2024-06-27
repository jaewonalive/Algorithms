// problem : https://www.acmicpc.net/problem/2839
#include <iostream>
#include <vector>
#include <climits>


int main(){
    int N_kg;

    std::cin >> N_kg;

    std::vector<int> memo(N_kg+1, INT_MAX); // Not to confuse index.

    memo[0] = 0;
    memo[3] = 1;
    memo[5] = 1;

    int remainder = N_kg;
    int answer_1;
    int answer_2;

    for(int cur_amount=0; cur_amount<=N_kg; cur_amount++){
        if((memo[cur_amount] != INT_MAX)){
            if(cur_amount+3 <= N_kg){
                if(memo[cur_amount+3] > memo[cur_amount] + 1)
                    memo[cur_amount+3] = memo[cur_amount] + 1;
            }

            if(cur_amount+5 <= N_kg){
                if(memo[cur_amount+5] > memo[cur_amount] + 1)
                    memo[cur_amount+5] = memo[cur_amount] + 1;
            }
        }

    }

    if(memo[N_kg] == INT_MAX){
        std::cout << -1;
    }
    else{
        std::cout << memo[N_kg];
    }
}