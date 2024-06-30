// problem : https://www.acmicpc.net/problem/11724
#include <deque>
#include <iostream>
#include <vector>
#include <map>


void dfs(int src, int& num_connected, std::vector<bool>& visited, std::map<int, std::vector<int>>& adj_list){

    if(visited[src]) return;
    
    num_connected += 1;

    std::deque<int> stack;

    stack.push_back(src);

    while(!stack.empty()){
        int cur_node = stack.back();
        stack.pop_back();

        for(auto& neighbor : adj_list[cur_node]){
            if(!visited[neighbor]){
                stack.push_back(neighbor);
            }
        }

        visited[cur_node] = true;
    }
}



int main(){
    int num_nodes;
    int num_edges;

    std::cin >> num_nodes;
    std::cin >> num_edges;
    
    std::vector<bool> visited(num_nodes+1, false); // 0 idx is redundant. But this is convenient because we can use the index directly.
    std::map<int, std::vector<int>> adj_list;

    for(int i=0; i<num_edges; i++){
        int node_1;
        int node_2;

        std::cin >> node_1;
        std::cin >> node_2;

        adj_list[node_1].push_back(node_2);
        adj_list[node_2].push_back(node_1);
    }

    int num_connected = 0;


    for(int src=1; src<=num_nodes; src++){
        dfs(src, num_connected, visited, adj_list);
    }

    std::cout << num_connected;
}