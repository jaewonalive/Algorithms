// problem : https://www.acmicpc.net/problem/1197
#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <map>
#include <algorithm>

class Node{
    public :
        Node(){
            idx = -1;
            key = INT_MAX;
            prev = nullptr;
        }

        Node(int input_idx){
            idx = input_idx;
            key = INT_MAX;
            prev = nullptr;
        }

        Node(int input_key, Node* input_prev){
            key = input_key;
            prev = input_prev;
        }

        int get_idx(){
            return idx;
        }

        int get_key(){
            return key;
        }

        Node* get_prev(){
            return prev;
        }

        void set_key(int input_key){
            key = input_key;
        }

        void set_prev(Node* input_prev){
            prev = input_prev;
        }

    private :
        int idx;
        int key;
        Node* prev;
};

template <typename T>
class heap{
    public :
        int get_size(){
            return size;
        }

        void insert(T elem){
            arr.push_back(elem);
            size++;
            upheap();
        }

        void upheap(){
            int cur_idx = size-1;
            int parent_idx = (cur_idx-1)/2;

            while(cur_idx > 0){
                if(arr[cur_idx]->get_key()<arr[parent_idx]->get_key()){
                    std::swap(arr[cur_idx], arr[parent_idx]);
                    cur_idx = parent_idx;
                    parent_idx = (cur_idx-1)/2;
                }
                else{
                    break;
                }
            }
        }


        void upheap(int start_idx){
            int cur_idx = start_idx;
            int parent_idx = (cur_idx-1)/2;

            while(cur_idx > 0){
                if(arr[cur_idx]->get_key()<arr[parent_idx]->get_key()){
                    std::swap(arr[cur_idx], arr[parent_idx]);
                    cur_idx = parent_idx;
                    parent_idx = (cur_idx-1)/2;
                }
                else{
                    break;
                }
            }
        }


        T dequeue(){
            if(size==0){
                return nullptr;
            }
            Node* root = arr.front();
            arr[0] = arr.back();
            arr.pop_back();
            size--;
            downheap();
            return root;
        }

        void downheap(){
            int cur_idx = 0;
            int left = 2*cur_idx + 1;
            int right = 2*cur_idx + 2;

            while(left<= size-1){

                if(right <= size-1){
                    int tmp_min;
                    int tmp_idx;
                    Node* tmp_node;

                    if(arr[left]->get_key() < arr[right]->get_key()){
                        tmp_min = arr[left]->get_key();
                        tmp_node = arr[left];
                        tmp_idx = left;
                    }
                    else{
                        tmp_min = arr[right]->get_key();
                        tmp_node = arr[right];
                        tmp_idx = right;
                    }
                    
                    if(tmp_min < arr[cur_idx]->get_key()){
                        std::swap(arr[cur_idx], arr[tmp_idx]);

                        cur_idx = tmp_idx;
                        left = 2*cur_idx + 1;
                        right = 2*cur_idx + 2;
                    }
                    else{
                        break;
                    }
                }
                else{
                    int tmp_min = arr[left]->get_key();
                    Node* tmp_node = arr[left];
                    int tmp_idx = left;

                    if(tmp_min < arr[cur_idx]->get_key()){
                        std::swap(arr[cur_idx], arr[tmp_idx]);
                        cur_idx = left;
                        left = 2*cur_idx + 1;
                        right = 2*cur_idx + 2;
                    }
                    else{
                        break;
                    }
                }

                left = 2*cur_idx + 1;
                right = 2*cur_idx + 2;
            }

        }


        void downheap(int start_idx){
            int cur_idx = start_idx;
            int left = 2*cur_idx + 1;
            int right = 2*cur_idx + 2;

            while(left<= size-1){

                if(right <= size-1){
                    int tmp_min;
                    int tmp_idx;
                    Node* tmp_node;

                    if(arr[left]->get_key() < arr[right]->get_key()){
                        tmp_min = arr[left]->get_key();
                        tmp_node = arr[left];
                        tmp_idx = left;
                    }
                    else{
                        tmp_min = arr[right]->get_key();
                        tmp_node = arr[right];
                        tmp_idx = right;
                    }
                    
                    if(tmp_min < arr[cur_idx]->get_key()){
                        std::swap(arr[cur_idx], arr[tmp_idx]);

                        cur_idx = tmp_idx;
                    }
                }
                else{
                    int tmp_min = arr[left]->get_key();
                    Node* tmp_node = arr[left];
                    int tmp_idx = left;

                    if(tmp_min < arr[cur_idx]->get_key()){
                        std::swap(arr[cur_idx], arr[tmp_idx]);

                        cur_idx = left;
                    }
                }

                left = 2*cur_idx + 1;
                right = 2*cur_idx + 2;
            }

        }

        int traverse(T target, int start_idx){

            if(size == 0){
                return INT_MIN;
            }

            if(start_idx >= size){
                return INT_MIN;
            }

            if(arr[start_idx] == target){
                return start_idx;
            }

            int cur_idx = start_idx;
            int found_idx = INT_MIN;

            int left = 2*cur_idx + 1;
            int right = 2*cur_idx + 2;

            if(left+1 <= size){

                if(arr[left]->get_key() <= target->get_key()){
                    found_idx = traverse(target, left);
                }
            
            
                if(right+1 <= size){
                    if(found_idx == INT_MIN){
                        if(arr[right]->get_key() <= target->get_key()){
                            found_idx = traverse(target, right);
                        }
                    }
                }

            }

            return found_idx;

        }

        void heapify(int start_idx){
            //determine upheap or downheap

            int parent_idx = (start_idx-1)/2;
            int left = start_idx * 2 + 1;
            int right = start_idx * 2 + 2;

            if(parent_idx >= 0){
                if(arr[parent_idx]->get_key() > arr[start_idx]->get_key()){
                    upheap(start_idx);
                    return;
                }
            }

            if(left+1 <= size){
                if(arr[left]->get_key() < arr[start_idx]->get_key()){
                    downheap(start_idx);
                    return;
                }
            }

        }

        void print_heap(){
            for(int i=0; i<arr.size(); i++){
                std::cout <<"idx : " << arr[i]->get_idx()+1 << " , key : " << arr[i]->get_key() <<std::endl; ;
            }
        }


    private :
        int size = 0;
        std::vector<T> arr;

};

class edge_cls{
    public:
        edge_cls(int input_src, int input_dst, int input_weight){
            src = input_src;
            dst = input_dst;
            weight = input_weight;
        }

        int get_src(){
            return src;
        }

        int get_dst(){
            return dst;
        }

        int get_weight(){
            return weight;
        }

    private:
        int src;
        int dst;
        int weight;

};


int main(){

    int nodes_num;
    int edges_num;
    int min_cost = 0;

    std::cin >> nodes_num;
    std::cin >> edges_num;

    std::map<int, std::vector<edge_cls*>> adj_list;
    std::vector<Node*> node_list;

    for(int i=0; i<nodes_num; i++){
        Node* tmp_node = new Node(i);
        node_list.push_back(tmp_node);
    }


    for(int i=0; i<edges_num; i++){
        int src_idx;
        int dst_idx;
        int weight;

        std::cin >> src_idx;
        std::cin >> dst_idx;
        std::cin >> weight;


        adj_list[src_idx-1].push_back(new edge_cls(src_idx-1, dst_idx-1, weight));
        adj_list[dst_idx-1].push_back(new edge_cls(dst_idx-1, src_idx-1, weight));
    }

    node_list[0]->set_key(0);
    heap<Node*> node_heap;

    for(int i=0; i<node_list.size(); i++){
        node_heap.insert(node_list[i]);
    }

    while(node_heap.get_size()>0){
        
        Node* min_node = node_heap.dequeue();
        int min_node_idx = min_node->get_idx();
        int min_node_key = min_node->get_key();

        min_cost += min_node_key;


        for(int i=0; i<adj_list[min_node_idx].size(); i++){
            edge_cls* tmp_edge = adj_list[min_node_idx][i];
            Node* neighbor = node_list[tmp_edge->get_dst()];


            if(tmp_edge->get_weight() < neighbor->get_key()){
                int traverse_result = node_heap.traverse(neighbor, 0);
                if(traverse_result != INT_MIN){
                    neighbor->set_prev(min_node);
                    neighbor->set_key(tmp_edge->get_weight());
                    node_heap.heapify(traverse_result);

                }
            }
        }
    }
    std::cout << min_cost;
}