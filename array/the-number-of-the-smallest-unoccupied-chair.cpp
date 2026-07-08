// class Solution {
// public:

//     struct myCompare{

//         bool operator()(const pair<int,int> a,const pair<int,int> b)
//         {
//             if(a.second == b.second)
//                 return a.first < b.first;

//             return a.second < b.second;
//         }

//     };
    

//     int smallestChair(vector<vector<int>>& times, int targetFriend) {
//         int n=times.size();
//         int arrTime = times[targetFriend][0];
//         sort(times.begin(),times.end());
        
//         int seat=0;
//         priority_queue<pair<int,int>,vector<pair<int,int>>,myCompare> seatsAvail; // {seat,timeFree}

//         for(int i=0;i<n;i++)
//         {
//             if(times[i][0]==arrTime)
//             {
//                 if(seatsAvail.size()==0 || seatsAvail.top().second > arrTime)
//                 {
//                     return seat;
//                 }

//                 int ans =INT_MAX;
//                 while(seatsAvail.size()!=0 && seatsAvail.top().second <= arrTime)
//                 {
//                     ans=min(ans,seatsAvail.top().first);
//                     seatsAvail.pop();
//                 }
//                 return ans;

//             }

//             if(seatsAvail.size()!=0 && times[i][0] >= seatsAvail.top().second)
//             {
//                 int oldSeat = seatsAvail.top().first;
//                 seatsAvail.pop();
//                 seatsAvail.push({oldSeat,times[i][1]});
//             }
//             else{
//                 seatsAvail.push({seat,times[i][1]});
//                 seat++;
//             }

//         }
//         return 0;
        
//     }
// };

class Solution {
public:

    struct myCompare {
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) {
            if(a.second == b.second)
                return a.first > b.first;  // Sort by seat number if the free time is the same
            return a.second > b.second;     // Otherwise sort by free time
        }
    };
    
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        int arrTime = times[targetFriend][0];
        
        // Sort based on arrival times
        sort(times.begin(), times.end());
        
        int seat = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, myCompare> seatsAvail; // {seat, timeFree}
        priority_queue<int, vector<int>, greater<int>> availableSeats;  // Min heap of available seat numbers

        for(int i = 0; i < n; i++) {
            // Free up seats for friends whose leave time has passed
            while(!seatsAvail.empty() && seatsAvail.top().second <= times[i][0]) {
                availableSeats.push(seatsAvail.top().first);
                seatsAvail.pop();
            }

            // If the current friend is the target friend
            if(times[i][0] == arrTime) {
                if(!availableSeats.empty()) {
                    return availableSeats.top(); // Return the smallest available seat
                }
                return seat;  // Otherwise return the next available seat
            }

            // Assign a seat to the current friend
            if(!availableSeats.empty()) {
                int assignedSeat = availableSeats.top();
                availableSeats.pop();
                seatsAvail.push({assignedSeat, times[i][1]});
            } else {
                seatsAvail.push({seat, times[i][1]});
                seat++;
            }
        }
        
        return 0;
    }
};
