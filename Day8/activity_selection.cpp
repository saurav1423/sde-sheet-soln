Given N activities with their start and finish day given in array start[ ] and end[ ]. Select the maximum number of activities that can be 
performed by a single person, assuming that a person can only work on a single activity at a given day.
Note : Duration of the activity includes both starting and ending day.

Input:
N = 4
start[] = {1, 3, 2, 5}
end[] = {2, 4, 3, 6}
Output: 
3
Explanation:
A person can perform activities 1, 2
and 4.

//question is same as N meetings in a room 

//optimal
class solution
{
    public:
    struct activity{
        int st;
        int end;
        int pos;
    };
    
    static bool comp(struct activity act1, activity act2){
        if(act1.end < act2.end)
           return true;
        else if(act1.end > act2.end)
           return false;
        else if(act1.pos < act2.pos)
           return true;
        else
           return false;
    }
    
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        struct activity act[n];
        for(int i=0; i<n; i++){
            act[i].st = start[i];
            act[i].end = end[i];
            act[i].pos = i+1;
        }
        
        sort(act, act+n, comp);
        
        vector<int> ans;
        ans.push_back(act[0].pos);
        int limit = act[0].end;
        
        for(int i=1; i<n; i++){
            if(act[i].st>limit){
                ans.push_back(act[i].pos);
                limit = act[i].end;
            }
        }
        
        return ans.size();
        
    }
}

time - 0(NlogN)
space - 0(N)