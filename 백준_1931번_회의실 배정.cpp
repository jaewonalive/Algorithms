// problem : https://www.acmicpc.net/problem/1931
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#include <climits>


int find_early_sched(std::vector<std::pair<int,int>>& pair_vec, int last_sched_idx){

    int last_finished_hour = pair_vec[last_sched_idx].first;
    int found_idx = INT_MAX;


    for(int i=last_sched_idx+1; i<pair_vec.size(); i++){
        if(pair_vec[i].second >= last_finished_hour){
            found_idx = i;
            break;
        }
    }

    return found_idx;
}


int main(){

    int num_conf;
    std::vector<std::pair<int, int>> vect;

    std::cin >> num_conf;

    for(int i=0; i<num_conf; i++){
        int start_time;
        int end_time;
        
        std::cin >> start_time;
        std::cin >> end_time;


        vect.push_back(std::make_pair(end_time, start_time));
    }

    std::sort(vect.begin(), vect.end());

    int cur_idx = 0;
    int cnt = 1;


    while(cur_idx < vect.size()){
        cur_idx = find_early_sched(vect, cur_idx);
        if(cur_idx != INT_MAX){
            cnt+= 1;
        }
    }

    std::cout << cnt;

}
