class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int delta;
        int container;
        const int length = gas.size();
           
        for(int i = 0;i<length;++i){
            
            delta = gas[i] - cost[i];
            container = 0;
            if(delta >= 0){
                
                container +=gas[i];
                
                for(int k = i;;++k){
                    
                    k %=length;
                    
                    container -=cost[k];
                    
                   
                    if(container < 0 || (k == ((i+length-1)%length)))break;
                    
                    container += gas[(k+1)%length];
                }
                
                if(container >= 0)
                    return i;
            }
           
        }
       
        
        return -1;
    }
    
    
    //參考解答
    class Solution {
    public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int start(0),total(0),tank(0);
        //if car fails at 'start', record the next station
        for(int i=0;i<gas.size();i++) if((tank=tank+gas[i]-cost[i])<0) {start=i+1;total+=tank;tank=0;}
        return (total+tank<0)? -1:start;
    }
};
    
};
