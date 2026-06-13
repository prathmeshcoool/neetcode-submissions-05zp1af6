/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        
        
        if(intervals.size()==0){
            return 0;
        }    
        
        sort(intervals.begin(),intervals.end(),[](const Interval &a,const Interval &b){
            if(a.start==b.start){
                return a.end < b.end;
            }
            return a.start < b.start;
        });

        priority_queue<int, vector<int>, greater<int>> pq;

        int ans = INT_MIN;
        for(auto v:intervals){
            int l = v.start;
            int r = v.end;

            pq.push(r);
            while(!pq.empty() && pq.top()<=l){
                pq.pop();
            }
            ans = max(ans, (int)pq.size());

        }
        return ans;

    }
};
