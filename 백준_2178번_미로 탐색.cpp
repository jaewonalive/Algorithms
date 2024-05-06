// problem : https://www.acmicpc.net/problem/2178
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <limits.h>
#include <queue>


void print_map(std::map<std::pair<int,int>, std::vector<std::pair<int,int>>>& input_adj){
    for(auto& elem1 : input_adj){
        std::cout << "key : " << elem1.first.first << " , " << elem1.first.second << std::endl;

        for(auto& elem2: elem1.second){
            std::cout << "value : ";

            std::cout << elem2.first << ", "  << elem2.second;
           
            std::cout << std::endl;

        }
    }
}

void gen_adj_list(std::map<std::pair<int,int>, std::vector<std::pair<int,int>>>& input_adj, int**& arr_input, int row, int col){

    for(int i=0; i<row ; i++){
        for(int j=0; j<col; j++){
            std::pair<int,int> north_pair = {i-1, j};
            std::pair<int,int> west_pair = {i, j-1};
            std::pair<int,int> east_pair = {i, j+1};
            std::pair<int,int> south_pair = {i+1, j};

            if(arr_input[i][j]==0)
                continue;

            if(north_pair.first >=0){
                if(arr_input[north_pair.first][north_pair.second]==1){
                    if(input_adj[{i, j}].size()==0)
                        input_adj[{i, j}] = {{north_pair.first, north_pair.second}};
                    else{
                        input_adj[{i, j}].push_back({north_pair.first, north_pair.second});
                    }
                }
            }

            if(west_pair.second >=0){

                if(arr_input[west_pair.first][west_pair.second]==1){
                    if(input_adj[{i, j}].size()==0)
                        input_adj[{i, j}] = {{west_pair.first, west_pair.second}};
                    else{
                        input_adj[{i, j}].push_back({west_pair.first, west_pair.second});
                    }
                }

            }


            if(east_pair.second <= col-1){


                if(arr_input[east_pair.first][east_pair.second]==1){
                    if(input_adj[{i, j}].size()==0)
                        input_adj[{i, j}] = {{east_pair.first, east_pair.second}};
                    else{
                        input_adj[{i, j}].push_back({east_pair.first, east_pair.second});
                    }
                }

            }

            if(south_pair.first <= row-1){

                if(arr_input[south_pair.first][south_pair.second]==1){
                    if(input_adj[{i, j}].size()==0)
                        input_adj[{i, j}] = {{south_pair.first, south_pair.second}};
                    else{
                        input_adj[{i, j}].push_back({south_pair.first, south_pair.second});
                    }
                }
            }


        }
    }
    


}


void bfsShortestPaths(std::map<std::pair<int,int>, std::vector<std::pair<int,int>>>& input_adj, int**& dist_arr, bool**& visit_arr,
                     std::map<std::pair<int,int>, std::pair<int,int>>& pred_map, std::pair<int,int>& source){
    std::queue<std::pair<int,int>> toVisit;

    toVisit.push(source);
    dist_arr[source.first][source.second] = 0;
    visit_arr[source.first][source.second] = true;

    while(!toVisit.empty()){
        std::pair<int, int> curr = toVisit.front();
        toVisit.pop();

        std::vector<std::pair<int,int>> neighbors = input_adj[curr];

        for(auto elem : neighbors){
            if(visit_arr[elem.first][elem.second] == false){
                dist_arr[elem.first][elem.second] = dist_arr[curr.first][curr.second] + 1;
                pred_map[{elem.first, elem.second}] = curr;
                toVisit.push(elem);
                visit_arr[elem.first][elem.second] = true;
            }
        }
    }





}


int main(){
    int row, col;
    std::string line;
    std::map<std::pair<int,int>, std::vector<std::pair<int,int>>> adj_list;

    std::getline(std::cin, line);

    std::size_t found = line.find(" ");

    row = std::stoi(line.substr(0, found));
    col = std::stoi(line.substr(found+1, line.size()-found-1));

    int** arr = new int*[row];
    int** dist_arr = new int*[row];
    bool** visit_arr = new bool*[row];
    std::map<std::pair<int,int>, std::pair<int,int>> pred_map;

    for(int i=0; i<row; i++){
        arr[i] = new int[col];
        dist_arr[i] = new int[col];
        visit_arr[i] = new bool[col];
    }


    int j;
    for(int i=0; i<row; i++){
        std::getline(std::cin, line);

        j = 0;

        for (auto elem : line){
            arr[i][j] = elem - '0';

            dist_arr[i][j] = INT_MAX;
            visit_arr[i][j] = false;

            j++;

        }
    }


    gen_adj_list(adj_list, arr, row, col);
    // print_map(adj_list);

    std::pair<int, int> source = {0,0};

    bfsShortestPaths(adj_list, dist_arr, visit_arr, pred_map, source);


    // for(int i=0; i<row; i++){
    //     for(int j=0; j<col; j++){
    //         std::cout << dist_arr[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    std::cout << dist_arr[row-1][col-1]+1;


}