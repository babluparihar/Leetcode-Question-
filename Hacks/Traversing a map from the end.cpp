  for(auto it = mp.rbegin(); it!=mp.rend(); it++){
            if(temp_k >= it->second){
                temp_sum -= it->first*it->second;
                temp_k-=it->second;
            }
            else{
                temp_sum -= it->first*temp_k;
                break;
            }
        }
