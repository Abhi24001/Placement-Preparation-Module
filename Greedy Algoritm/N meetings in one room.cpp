class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool cmp(pair<int,int> a,pair<int,int> b){
        return a.second<b.second;
    }
    int maxMeetings(int Start[], int End[], int n)
    {
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({Start[i],End[i]});
        }
        sort(v.begin(),v.end(),cmp);
        int count=1;
        int endtime=v[0].second;
        for(int i=1;i<n;i++){
            if(v[i].first>endtime)
            {
                count++;
                endtime=v[i].second;
            }
        }
        return count;
    }
};
