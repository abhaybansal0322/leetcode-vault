// class Solution {
// public:
//     typedef pair<int, pair<int, int>> P;
//     vector<vector<int>> dirs = {
//                 {-1,0},
//         {0,-1},         {0,1},
//                 {1, 0}
//     };
//    // Interesting right :-) 
    
//     int minimumEffortPath(vector<vector<int>>& heights) {
//         int m = heights.size();
//         int n = heights[0].size();
        
//         auto isSafe = [&](int x, int y) {
//             return x>=0 && x<m && y>=0 && y<n;
//         };
        
//         vector<vector<int>> result(m, vector<int>(n, INT_MAX));
//         priority_queue<P, vector<P>, greater<P>> pq;
        
//         pq.push({0, {0, 0}});
//         result[0][0] = 0;
  
//         while(!pq.empty()) {
//             int diff  = pq.top().first;
//             auto node = pq.top().second;
//             pq.pop();

//             int x = node.first;
//             int y = node.second;
            
//             //Why returning now ?
//             //Because there is no way that the rest of elements can update the weight of destination cell even smaller due to the min heap.
//             if(x == m-1 && y == n-1)
//                 return diff;
            
// 	    for(auto dir:dirs) {
// 		int x_   = x + dir[0];
// 		int y_   = y + dir[1];

// 		if(isSafe(x_, y_)) {

// 		    int newDiff = max(diff, abs(heights[x][y] - heights[x_][y_]));
// 		    if(result[x_][y_] > newDiff) {
// 			result[x_][y_] = newDiff;
// 			pq.push({result[x_][y_], {x_, y_}});
// 		    }
// 		}
// 	     }
//         }
   
//         return result[m-1][n-1];

//     }
// };

// class Solution {
// public:
//     typedef pair<int, pair<int,int>> P;

//     int minimumEffortPath(vector<vector<int>>& heights) {
//         int m = heights.size(), n = heights[0].size();
//         vector<vector<int>> directions{{-1,0},{1,0},{0,-1},{0,1}};
//         vector<vector<int>> effort(m, vector<int>(n, INT_MAX));

//         priority_queue<P, vector<P>, greater<P>> pq;
//         pq.push({0,{0,0}});
//         effort[0][0] = 0;

//         while (!pq.empty()) {
//             auto [currEffort, coord] = pq.top();
//             pq.pop();
//             int x = coord.first, y = coord.second;

//             if (x == m-1 && y == n-1)
//                 return currEffort;

//             for (auto& dir : directions) {
//                 int nx = x + dir[0], ny = y + dir[1];

//                 if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
//                     int nextEffort = max(currEffort, abs(heights[x][y] - heights[nx][ny]));
//                     if (nextEffort < effort[nx][ny]) {
//                         effort[nx][ny] = nextEffort;
//                         pq.push({nextEffort,{nx,ny}});
//                     }
//                 }
//             }
//         }
//         return 0; // default unreachable
//     }
// };


class Solution {
public:
    typedef pair<int, pair<int,int>> P;
    vector<vector<int>> dirs = {
                {-1,0},
        {0,-1},         {0,1},
                {1, 0}
    };

    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int m = heights.size();
        int n = heights[0].size();

        auto isSafe = [&] (int x,int y) {

            return (x<m && x>=0 && y<n && y>=0);
        };

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<int>> result(m,vector<int>(n,INT_MAX));
        result[0][0]=0;
        pq.push({0,{0,0}});

        while(!pq.empty()) {

            auto [effort,coord] = pq.top();
            pq.pop();

            int x = coord.first;
            int y = coord.second;

            if(x==m-1 && y==n-1)    return effort;

            for(auto& dir : dirs) {

                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if(isSafe(x_,y_)) {

                    int minEffort = max(abs(heights[x_][y_]-heights[x][y]),result[x][y]);

                    if(result[x_][y_] > minEffort) {

                        pq.push({minEffort,{x_,y_}});
                        result[x_][y_] = minEffort;
                    }
                }
            }
        }

        return -1;


    }
};


