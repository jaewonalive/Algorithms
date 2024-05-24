// problem : https://www.acmicpc.net/problem/1753
#include <iostream>
#include <string>
#include<vector>
#include <map>
#include <climits>
#include <queue>

void gen_adj_list(std::vector<std::vector<int>>& edge_list, std::map<int, std::vector<std::vector<int>>>& input_adj_list){
    for(int i=0; i<edge_list.size() ; ++i){
        input_adj_list[edge_list[i][0]].push_back({edge_list[i][1], edge_list[i][2]});
    }
}


class myComparator{
    public:
        int operator() (const std::pair<int, int>& p1, const std::pair<int, int>& p2){
            return p1.first > p2.first;
        }
};


void shortestPath(int source, std::map<int, std::vector<std::vector<int>>> input_adj_list, int node_num){
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, myComparator> pq;
    
    std::vector<int> distance_vec(node_num+1, INT_MAX);

    pq.push(std::make_pair(0, source));
    distance_vec[source] = 0;


    while(!pq.empty()){
        int cur_node = pq.top().second;
        int distance = pq.top().first;

        pq.pop();
        
        if(distance > distance_vec[cur_node]) continue;

        for(auto& elem : input_adj_list[cur_node]){
            int dest_node = elem[0];
            int weight = elem[1];

            if(distance_vec[dest_node] > distance_vec[cur_node] + weight){

                
                distance_vec[dest_node] = distance_vec[cur_node] + weight;
                pq.push(std::make_pair(distance_vec[dest_node], dest_node));
            }
        }
    }

    
    for(int i=0; i<distance_vec.size(); ++i){
        if(i==0) continue;
    
        if(distance_vec[i] == INT_MAX){
            std::cout << "INF";

            if(i!=distance_vec.size()-1) std::cout << "\n"; 
            
        }
        else{
            std::cout << distance_vec[i];
            if(i!=distance_vec.size()-1) std::cout << "\n"; 
            
        
        }
        
    }



}



int main(){

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

    int node_num;
    int edge_num;

    std::cin >> node_num;
    std::cin >> edge_num;

    int source;

    std::cin >> source;


    std::vector<std::vector<int>> edge_list;


    for(int i=0; i<edge_num; i++){

        int source_u;
        int source_v;
        int weight;


        std::cin >> source_u;
        std::cin >> source_v;
        std::cin >> weight;

        edge_list.push_back({source_u, source_v, weight});
    }


    std::map<int, std::vector<std::vector<int>>> adj_list;

    gen_adj_list(edge_list, adj_list);

    shortestPath(source, adj_list, node_num);
}