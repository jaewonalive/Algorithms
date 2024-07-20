// problem : https://www.acmicpc.net/problem/2775
#include <iostream>
#include <vector>
#include <climits>


int main(){
    int num_test;

    std::cin >> num_test;

    // a_(k,n) = a_(k, n-1) + a_(k-1, n)

    for(int i=0; i<num_test; i++){
        int k;
        int n;

        std::cin >> k;
        std::cin >> n;

        int** mat = new int*[k+1];

        for(int j=0; j<k+1; j++){
            mat[j] = new int[n];
        }

        // initialize 0th floor.
        // 1호부터 n호가 index 관점에서만 0호부터 n-1호로 대응.
        for(int p=0; p<n; p++){
            mat[0][p] = p+1;
        }

        for(int r=1; r<k+1; r++){
            for(int s=0; s<n; s++){
                if(s==0){
                    mat[r][s] = 1;
                }
                else{
                    mat[r][s] = mat[r][s-1] + mat[r-1][s];
                }
            }
        }

        std::cout << mat[k][n-1] << std::endl;
    }
}