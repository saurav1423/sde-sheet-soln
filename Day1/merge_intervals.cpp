//ask interviewer, is given data is sorted or not(as if it is not sorted then we will have to sort it)

//brute
A simple approach is to start from the first interval and compare it with all other intervals for overlapping,
if it overlaps with any other interval, then remove the other interval from the list and merge the other into 
the first interval. Repeat the same steps for the remaining intervals after the first. 

time - 0(N^2)


//optimal
vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> result;
        
        for(int i=0; i<intervals.size(); i++){
            
            if(result.size() == 0){
                result.push_back(intervals[i]);
            }else{
                if(result[result.size()-1][1] < intervals[i][0]){
                    result.push_back(intervals[i]);
                }else{
                    result[result.size()-1][1] = max(result[result.size()-1][1],intervals[i][1]);
                }
            }
        }
        
        return result;
    }

 time - 0(NlogN)  space - 0(N)   