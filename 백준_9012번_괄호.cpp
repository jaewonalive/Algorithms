//problem: https://www.acmicpc.net/problem/9012

#include <iostream>
#include <string>
#include <vector>

int main(){

    int input_num;
    std::string line;


    std::getline(std::cin, line);
    input_num = std::stoi(line);
    
    for(int i=0; i<input_num; i++){
        std::getline(std::cin ,line);
        bool yes = true;
        std::vector<char> vec_str;



        for(int j=0; j<line.length(); j++){

            if(line[j] == '('){
                vec_str.push_back('(');
            }
            else{
                if(vec_str.empty()){
                    yes = false;
                    break;
                }
                else{
                    vec_str.pop_back();
                }
            }
        }

        if(yes){
            if(!vec_str.empty()){
                yes = false;
            }
            else{
            }
        }

        if(yes)
            std::cout << "YES" << std::endl;
        else
            std::cout << "NO" << std::endl;
   
   }

}
