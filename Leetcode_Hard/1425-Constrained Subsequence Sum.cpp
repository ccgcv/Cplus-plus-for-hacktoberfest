int constrainedSubsetSum(vector<int>& ar, int k) {
        priority_queue< pair<int,int>,vector< pair<int,int> >  > pq;
        int ans =*max_element(ar.begin(),ar.end());
        for(int idx=0; idx<ar.size();idx++){
            while(pq.size() >0 and idx - pq.top().second > k) pq.pop();
            if(pq.size() > 0)  pq.push({pq.top().first + ar[idx],idx});
            pq.push({ar[idx],idx});
        }
        return max(ans,pq.top().first);
 }
