//problem : https://www.acmicpc.net/problem/1406
#include <iostream>
#include <string>

class strNode{
    private:
        char data;
        strNode* next;
        strNode* prev;

    public :
        strNode* get_next(){
            return next;
        }

        strNode* get_prev(){
            return prev;
        }

        char get_data(){
            return data;
        }

        void set_next(strNode* input_next){
            next = input_next;
        }

        void set_prev(strNode* input_prev){
            prev = input_prev;
        }


        void set_data(char input_data){
            data = input_data;
        }


        strNode(): data('$'), next(nullptr), prev(nullptr){}
        strNode(char input_data, strNode* given_next, strNode* given_prev) : data(input_data), next(given_next), prev(given_prev){}

};


void gen_list(std::string line, strNode* root_ptr, strNode* cur_ptr);
void print_list(strNode* root_ptr);
void proc_comm(std::string command, strNode*& root_ptr, strNode* cur_ptr);

int main(){

    std::string line;
    std::string command;
    std::string num_inst_str;
    int num_inst;
    strNode* root_node_ptr;
    strNode* cur_node_ptr;



    std::getline(std::cin, line); // get initial characters.

    cur_node_ptr = new strNode();
    cur_node_ptr->set_data('|');

    root_node_ptr = new strNode();
    gen_list(line, root_node_ptr, cur_node_ptr);

    std::getline(std::cin, num_inst_str); // get the number of instructions.

    num_inst = std::stoi(num_inst_str);

    for(int i=0; i<num_inst; i++){
        std::getline(std::cin, command);
        proc_comm(command, root_node_ptr, cur_node_ptr);
    }

    print_list(root_node_ptr);


}

void gen_list(std::string line, strNode* root_node_ptr, strNode* cur_ptr){
    strNode* prev_node_ptr;
    strNode* tmp_node_ptr;

    for(int i=0; i<line.length(); i++){
        if(i==0){
            root_node_ptr->set_data(line[0]);
            prev_node_ptr = root_node_ptr;
        }

        else{
            tmp_node_ptr = new strNode();
            tmp_node_ptr->set_data(line[i]);
            tmp_node_ptr->set_prev(prev_node_ptr);
            prev_node_ptr->set_next(tmp_node_ptr);
            prev_node_ptr = tmp_node_ptr;
        }
    }

    cur_ptr->set_prev(prev_node_ptr);
    prev_node_ptr->set_next(cur_ptr);

}

void proc_comm(std::string command, strNode*& root_ptr, strNode* cur_ptr){
    if(command[0]=='P'){
        strNode* tmp_node_ptr = new strNode(command[2], cur_ptr, cur_ptr->get_prev());
        
        if(cur_ptr->get_prev() != nullptr)
            cur_ptr->get_prev()->set_next(tmp_node_ptr);
        else{
            root_ptr = tmp_node_ptr;
        }
        tmp_node_ptr->set_prev(cur_ptr->get_prev());
        cur_ptr->set_prev(tmp_node_ptr);
        tmp_node_ptr->set_next(cur_ptr);
        
    }

    else if(command[0]=='L'){
        if(cur_ptr == root_ptr)
            return;


        strNode* tmp_node_ptr = cur_ptr->get_prev();
        strNode* tmp_node_ptr2 = cur_ptr->get_next();

        cur_ptr->set_next(tmp_node_ptr);
        cur_ptr->set_prev(tmp_node_ptr->get_prev());

        tmp_node_ptr->set_prev(cur_ptr);
        tmp_node_ptr->set_next(tmp_node_ptr2);//

        if(cur_ptr->get_prev() != nullptr)
            cur_ptr->get_prev()->set_next(cur_ptr);
        else{
            root_ptr = cur_ptr;
        }

    }

    else if(command[0] == 'D'){
        if(cur_ptr->get_next() == nullptr)
            return;

        strNode* tmp_node_ptr = cur_ptr->get_prev();
        strNode* tmp_node_ptr2 = cur_ptr->get_next();

        cur_ptr->set_next(tmp_node_ptr2->get_next());
        cur_ptr->set_prev(tmp_node_ptr2);

        tmp_node_ptr2->set_next(cur_ptr);
        tmp_node_ptr2->set_prev(tmp_node_ptr);

        if(cur_ptr->get_next() != nullptr)
            cur_ptr->get_next()->set_prev(cur_ptr);

        if(tmp_node_ptr != nullptr)
            tmp_node_ptr->set_next(tmp_node_ptr2);
        else{
            root_ptr = tmp_node_ptr2;
        }  
    }

    else if(command[0] == 'B'){
        if(cur_ptr == root_ptr)
            return;

        strNode* tmp_node_ptr = cur_ptr->get_prev();
        strNode* tmp_node_ptr2 = cur_ptr->get_next();

        cur_ptr->set_prev(tmp_node_ptr->get_prev());

        if(tmp_node_ptr->get_prev() != nullptr){
            tmp_node_ptr->get_prev()->set_next(cur_ptr);
        }
        else{
            root_ptr = cur_ptr;
        }
    }
}


void print_list(strNode* root_ptr){
    strNode* now_ptr = root_ptr;

    while(now_ptr->get_next() != nullptr){
        if(now_ptr->get_data() != '|')
            std::cout << now_ptr->get_data();

        if(now_ptr->get_next() != nullptr)
            now_ptr = now_ptr->get_next();
    }

    if(now_ptr->get_data() != '|')
        std::cout << now_ptr->get_data() << std::endl;

}
