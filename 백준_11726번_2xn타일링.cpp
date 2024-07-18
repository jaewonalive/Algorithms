// problem : https://www.acmicpc.net/problem/11726
#include <iostream>
#include <vector>

int main(){
    int n;
    int answer;
    std::cin >> n;

    // this contains the number of ways to fill the 2xn rectangular.
    std::vector<int> memo(n+1, 0);

    // we have two blocks (1x2 and 2x1)

    //a_n : the number of ways to fill the 2xn rectangular.
    //a_{n+2} = (a_{n+1}) + (a_{n})
    // a_2 = (a_1) + (a_0) 

    memo[0] = 0; //edge case
    memo[1] = 1;
    memo[2] = memo[1] + 1;

    if(n>=3){
        for(int i=3; i<=n; i++){
            memo[i] = ((memo[i-1]%10007) + (memo[i-2])%10007)%10007;
        }
    }

    answer = memo[n] % 10007;
    std::cout << answer ;

}