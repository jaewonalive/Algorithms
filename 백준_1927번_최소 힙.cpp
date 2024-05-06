// problem : https://www.acmicpc.net/problem/1927
#include <iostream>
#include <vector>
#include <algorithm>

class heap{
    private:
        std::vector<int> heap_arr;
        

    public:
        void enqueue(int value){
            heap_arr.push_back(value);
            int size = heap_arr.size();
            int cur_idx =  size - 1;
            int tmp_idx=-1;

            if(heap_arr.size() != 1){
                int parent_idx = (cur_idx-1)/2;


                while(heap_arr[parent_idx] > heap_arr[cur_idx]){

                    int tmp = heap_arr[parent_idx];
                    heap_arr[parent_idx] = heap_arr[cur_idx];
                    heap_arr[cur_idx] = tmp;

                    cur_idx = parent_idx;
                    parent_idx = (cur_idx-1)/2;
                    if(cur_idx == 0)
                        break;
                }
            }
        }

        int dequeue(){
            if(heap_arr.size()==0)
                return 0 ;

            
            int min_val = heap_arr[0];

            if(heap_arr.size()==1){
                heap_arr.pop_back();
                return min_val;
            }

            heap_arr[0] = heap_arr.back();
            heap_arr.pop_back();
            int cur_idx = 0;

            int left_idx = cur_idx*2 + 1;
            int right_idx = cur_idx*2 + 2;

            bool heap_flag;

            int min_idx;

            int size = heap_arr.size();


            if((left_idx > size -1)&& (right_idx > size-1)){
                return min_val;
            }
            
            else if((left_idx <= size-1)&& (right_idx <= size-1)){
                if(heap_arr[left_idx] < heap_arr[right_idx]){
                    min_idx = left_idx;
                }
                else{
                    min_idx = right_idx;

                }
                
                if(heap_arr[min_idx] < heap_arr[cur_idx]){
                    heap_flag = true;
                }
                else{
                    heap_flag = false;
                }
            }



            else if((left_idx <= size-1)&& (right_idx > size-1)){
                
                min_idx = left_idx;


                if(heap_arr[min_idx] < heap_arr[cur_idx]){
                    heap_flag = true;
                }
                else{
                    heap_flag = false;
                }
            }


            while(heap_flag){


                int tmp = heap_arr[min_idx];
                heap_arr[min_idx] = heap_arr[cur_idx];
                heap_arr[cur_idx] = tmp;



                cur_idx = min_idx;

                left_idx = cur_idx*2 + 1;
                right_idx = cur_idx*2 + 2;

                size = heap_arr.size();

                if((left_idx > size-1)&& (right_idx > size-1)){
                    heap_flag = false;
                }
                
                else if((left_idx <= size-1)&& (right_idx <= size-1)){
                    if(heap_arr[left_idx] < heap_arr[right_idx]){
                        
                        min_idx = left_idx;
                    }
                    else{
                        
                        min_idx = right_idx;

                    }
                    
                    if(heap_arr[min_idx] < heap_arr[cur_idx]){
                        heap_flag = true;
                    }
                    else{
                        heap_flag = false;
                    }
                }



                else if((left_idx <= size-1)&& (right_idx > size-1)){
                    
                    min_idx = left_idx;


                    if(heap_arr[min_idx] < heap_arr[cur_idx]){
                        heap_flag = true;
                    }
                    else{
                        heap_flag = false;
                    }
                }

            }



            return min_val;



        }

        void traverse(){
            for(int i=0; i<heap_arr.size(); i++){
                std::cout << heap_arr[i] << std::endl;
            }        
        }

        int peek(){
            return heap_arr[0];
        }       
};

int main(){
    heap my_heap;


	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

    int num_inst;
    int inst;

    std::cin >> num_inst;

    int value;

    for(int i=0; i<num_inst; i++){
        std::cin >> inst;

        if(inst == 0){
            value = my_heap.dequeue();
            std::cout << value << "\n";
        }
        else{
            my_heap.enqueue(inst);
        }



    }

}