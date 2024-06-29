// problem : https://www.acmicpc.net/problem/1012
#include <iostream>
#include <vector>
#include <map>
#include <deque>
#include <bits/stdc++.h>

struct Node{
    int x;
    int y;
    bool visited;
};

void bfs(std::map<std::pair<int, int>, Node*>& node_map, std::map<Node*, std::vector<Node*>>& adj_list, int src_x, int src_y, int& num_call){
    std::deque<Node*> q;

    if(!node_map[std::make_pair(src_y, src_x)]->visited){
        q.push_back(node_map[std::make_pair(src_y, src_x)]);
        num_call += 1;
    }
    else{
        return;
    }

    while(!q.empty()){
        Node* cur_node = q.front();
        q.pop_front();

        int cur_y = cur_node->y;
        int cur_x = cur_node->x;

        for(auto& adj_node : adj_list[cur_node]){
            int adj_x = adj_node->x;
            int adj_y = adj_node->y;

            if(!node_map[std::make_pair(adj_y, adj_x)]->visited){
                if(q.end() == std::find(q.begin(), q.end(), node_map[std::make_pair(adj_y, adj_x)]))
                    q.push_back(adj_node);
            }
        }
        cur_node->visited = true;
    }
}

void get_num_worm(){
    int width;
    int height;
    int num_lettuce;

    std::cin >> width;
    std::cin >> height;
    std::cin >> num_lettuce;

    std::map<Node*, std::vector<Node*>> adj_list;
    std::map<std::pair<int, int>, Node*> node_map; // 1st key is y-coord. 2nd key is x-coord.

    std::vector<std::pair<int,int>> lettuce_node;

    for(int i=0; i<num_lettuce; i++){
        int input_x;
        int input_y;

        std::cin >> input_x;
        std::cin >> input_y;

        lettuce_node.push_back(std::make_pair(input_y, input_x));


        node_map[std::make_pair(input_y, input_x)] = new Node;
        node_map[std::make_pair(input_y, input_x)]->x = input_x;
        node_map[std::make_pair(input_y, input_x)]->y = input_y;
        node_map[std::make_pair(input_y, input_x)]->visited = false;

    }

    for(int i=0; i<num_lettuce; i++){
        std::pair<int, int> cur_pair = lettuce_node[i];

        auto it_1 = node_map.find(std::make_pair(cur_pair.first+1, cur_pair.second));
        if(it_1 != node_map.end()){
            adj_list[node_map[std::make_pair(cur_pair.first+1, cur_pair.second)]].push_back(node_map[std::make_pair(cur_pair.first, cur_pair.second)]);
        }



        auto it_2 = node_map.find(std::make_pair(cur_pair.first-1, cur_pair.second));
        if(it_2 != node_map.end()){
            adj_list[node_map[std::make_pair(cur_pair.first-1, cur_pair.second)]].push_back(node_map[std::make_pair(cur_pair.first, cur_pair.second)]);
        }



        auto it_3 = node_map.find(std::make_pair(cur_pair.first, cur_pair.second+1));
        if(it_3 != node_map.end()){
            adj_list[node_map[std::make_pair(cur_pair.first, cur_pair.second+1)]].push_back(node_map[std::make_pair(cur_pair.first, cur_pair.second)]);
        }


        auto it_4 = node_map.find(std::make_pair(cur_pair.first, cur_pair.second-1));
        if(it_4 != node_map.end()){
            adj_list[node_map[std::make_pair(cur_pair.first, cur_pair.second-1)]].push_back(node_map[std::make_pair(cur_pair.first, cur_pair.second)]);
        }

    }

    int num_call = 0;

    for(auto& elem : node_map){
        bfs(node_map, adj_list, elem.first.second, elem.first.first, num_call);
    }

    std::cout << num_call << std::endl;

    return;

}

int main(){
    int num_test_case;

    std::cin >> num_test_case;

    for(int i=0; i<num_test_case; i++){
        get_num_worm();
    }
}