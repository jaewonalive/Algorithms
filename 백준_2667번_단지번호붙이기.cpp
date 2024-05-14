// problem : https://www.acmicpc.net/problem/2667
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>


class Node{
    public:
        Node(){};
        Node(int input_data, int input_row_idx, int input_col_idx){
            data = input_data;
            row_idx = input_row_idx;
            col_idx = input_col_idx;
        }
        int get_data(){
            return data;
        }

        Node* get_left(){
            return left;
        }

        Node* get_right(){
            return right;
        }

        Node* get_up(){
            return up;
        }

        Node* get_down(){
            return down;
        }

        int get_row_idx(){
            return row_idx;
        }

        int get_col_idx(){
            return col_idx;
        }

        void set_data(int input_data){
            data = input_data;
        }

        void set_left(Node* input_left){
            left = input_left;
        }

        void set_right(Node* input_right){
            right = input_right;
        }

        void set_up(Node* input_up){
            up = input_up;
        }

        void set_down(Node* input_down){
            down = input_down;
        }


        void set_row_idx(int input_row_idx){
            row_idx = input_row_idx;
        }


        void set_col_idx(int input_col_idx){
            col_idx = input_col_idx;
        }



    private:

        int data = -1;
        int row_idx = -1;
        int col_idx = -1;
        Node* left = nullptr;
        Node* right = nullptr;
        Node* up = nullptr;
        Node* down = nullptr;
};

void gen_adj_list(int row_num, int col_num, std::vector<Node*>& input_node_list, std::map<int, std::vector<Node*>>& input_adj_list){
    
    for(int i=0; i<row_num; i++){
        for(int j=0; j<col_num; j++){

            int cur_idx = i*row_num + j;
            int left_idx = cur_idx - 1;
            int right_idx = cur_idx + 1;
            int up_idx = cur_idx - row_num;
            int down_idx = cur_idx + row_num;


            if(input_node_list[cur_idx]->get_data()==0){
                continue;
            }


            if((left_idx>=0)&&(left_idx<=row_num*col_num-1)&&(cur_idx%row_num!=0)){
                if(input_node_list[left_idx]->get_data()==1){
                    input_adj_list[cur_idx].push_back(input_node_list[left_idx]);
                }
            }


            if((right_idx>=0)&&(right_idx<=row_num*col_num-1)&&((cur_idx+1)%row_num !=0)){
                if(input_node_list[right_idx]->get_data()==1){
                    input_adj_list[cur_idx].push_back(input_node_list[right_idx]);
                }
            }


            if((up_idx>=0)&&(up_idx<=row_num*col_num-1)){
                if(input_node_list[up_idx]->get_data()==1){
                    input_adj_list[cur_idx].push_back(input_node_list[up_idx]);
                }
            }



            if((down_idx>=0)&&(down_idx<=row_num*col_num-1)){
                if(input_node_list[down_idx]->get_data()==1){
                    input_adj_list[cur_idx].push_back(input_node_list[down_idx]);
                }
            }

        }
    }
}



void print_adj_list(std::map<int, std::vector<Node*>>& input_adj_list, int row_num){
    for(const auto& elem : input_adj_list){
        std::cout << "key  " << "(" << elem.first/row_num <<    ", "   <<  elem.first - row_num*(elem.first/row_num) <<" ) : ";

        for(const auto& elem2: elem.second){
            std::cout << "(" << elem2->get_row_idx() << ", " << elem2->get_col_idx() << ")" << " " ;
        }
        std::cout << std::endl;
    }

}



int dfs(int src_idx, int row_num, std::vector<Node*>& node_list,std::map<int, std::vector<Node*>>& input_adj_list, bool**& visited_list, std::vector<Node*>& tovisit_list){
    tovisit_list.push_back(node_list[src_idx]);
    int home_num=0;

    while(!tovisit_list.empty()){
        Node* current = tovisit_list.back();
        tovisit_list.pop_back();

        std::vector<Node*> neighbors = input_adj_list[current->get_row_idx()*row_num + current->get_col_idx()];

        for(auto elem: neighbors){

            if(visited_list[elem->get_row_idx()][elem->get_col_idx()]==false){
                tovisit_list.push_back(elem);
            }

            
        }

        if(visited_list[current->get_row_idx()][current->get_col_idx()]==false){
            visited_list[current->get_row_idx()][current->get_col_idx()] = true;
            home_num++;
        }


    }

    return home_num;
}



int main(){

    int row_num;
    int col_num;
    int line_num = 0;
    int total_area = 0;

    std::string line;
    std::vector<Node*> node_list;
    std::vector<Node*> toVisit;
    std::vector<int> home_num_vec;
    
    std::map<int, std::vector<Node*>> adj_list;


    std::getline(std::cin, line);
    row_num = std::stoi(line);
    col_num = row_num;


    int** arr = new int*[row_num];

    
    for(int i=0; i<row_num; i++){
        arr[i] = new int[col_num];
    }

    bool** visited = new bool*[row_num];

    for(int i=0; i<row_num; i++){
        visited[i] = new bool[col_num];
    }


    for(int i=0; i<row_num; i++){
        for(int j=0; j<col_num; j++){
            visited[i][j] = false;
        }
    }



    while(std::getline(std::cin, line)){

        for(int i=0; i<line.size();i++){
            arr[line_num][i] = line[i]-'0';
        }
        line_num++;
        if(line_num > row_num-1){
            break;
        }
    }

    for(int i=0; i<row_num; i++){
        for(int j=0; j<col_num; j++){
            int data = arr[i][j];
            node_list.push_back(new Node(data, i, j));
        }
    }


    gen_adj_list(row_num, col_num, node_list, adj_list);

    // print_adj_list(adj_list, row_num);

    for(int i=0; i<row_num*row_num; i++){
        int row_idx = i/row_num;
        int col_idx = i - (i/row_num)*row_num;

        if((visited[row_idx][col_idx]==false)&&(node_list[i]->get_data()!=0)){
            int home_num=-1;
            home_num = dfs(i, row_num, node_list, adj_list, visited, toVisit);
            home_num_vec.push_back(home_num);
            total_area++;
        }
    }

    std::cout << total_area << std::endl;
    std::sort(home_num_vec.begin(), home_num_vec.end());

    for(auto elem: home_num_vec){
        std::cout << elem << std::endl;
    }


}