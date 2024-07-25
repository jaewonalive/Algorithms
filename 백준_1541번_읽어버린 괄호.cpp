// problem : https://www.acmicpc.net/problem/1541
#include <iostream>
#include <string>


int main(){

    std::string formula;

    std::getline(std::cin, formula);

    int tmp_result=0;
    std::string tmp_buffer = "";
    bool minus_found = false;

    for(auto& one_char : formula){

        if((one_char == '-')||(one_char =='+')){
        
            if(minus_found){
                tmp_result -= std::stoi(tmp_buffer);
            }
            else{
                tmp_result += std::stoi(tmp_buffer);
            }

            if((one_char == '-')) minus_found = true;
            tmp_buffer = "";
        }
        else{
            tmp_buffer+=one_char; 
        }
    }


    if(minus_found){
        tmp_result -= std::stoi(tmp_buffer);
    }
    else{
        tmp_result += std::stoi(tmp_buffer);
    }
    tmp_buffer = "";

    std::cout << tmp_result;

}

