// problem : https://www.acmicpc.net/problem/10828
#include <iostream>
#include <vector>
#include <string>


int main(){
    int num_inst;
    std::string line;
    std::vector<int> int_vec;

    std::getline(std::cin, line);
    num_inst = std::stoi(line);

    for(int i=0; i<num_inst; i++){
        std::getline(std::cin, line);

        std::size_t found = line.find("push");

        if(found != std::string::npos){
            std::string target = line.substr(5);
            int target_int = std::stoi(target);
            int_vec.push_back(target_int);

            continue;

        }

        found = line.find("pop");

        if(found != std::string::npos){
            if(int_vec.empty()){
                std::cout << -1 << std::endl;
            }
            else{
                int target = int_vec.back();
                int_vec.pop_back();
                std::cout << target << std::endl;
            }
            continue;
        }


        found = line.find("size");


        if(found != std::string::npos){
            std::cout << int_vec.size() << std::endl;
            continue;
        }


        found = line.find("empty");


        if(found != std::string::npos){
            if(int_vec.empty()){
                std::cout << 1 << std::endl;
            }
            else{
                std::cout << 0 << std::endl;
            }

            continue;
        }


        found = line.find("top");

        if(found != std::string::npos){
            if(int_vec.empty()){
                std::cout << -1 << std::endl;;
            }
            else{
                std::cout << int_vec.back() << std::endl;
            }
            continue;
        }
    }

}
