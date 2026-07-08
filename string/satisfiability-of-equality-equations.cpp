class Solution {
public:

    vector<int> parent;
    vector<int> rank;

    int find(int x)
    {
        if(x == parent[x])
            return x;

        return parent[x]=find(parent[x]);
    }

    void Union(int x,int y)
    {
        if(parent[x]==parent[y])
            return;

        int parent_x = find(x);
        int parent_y = find(y);
        if(rank[parent_x] > rank[parent_y])
        {
            parent[parent_y] = parent_x;
        }
        else if(rank[parent_y]>rank[parent_x])
        {
            parent[parent_x] = parent_y;
        }
        else{
            parent[parent_x]=parent_y;
            rank[parent_y]++;
        }
    }

    bool equationsPossible(vector<string>& eq) {
        parent.resize(26);
        rank.resize(26);

        for(int i=0;i<26;i++)
        {
            parent[i]=i;
            rank[i]=0;
        }

        for(string &s : eq)
        {
            if(s[1] == '=')
            {
                Union(s[0]-'a',s[3]-'a');
            }
        }

        for(string &s : eq)
        {
            if(s[1]=='!')
            {
                if(find(s[0]-'a') == find(s[3]-'a'))
                {
                    return false;
                }
            }
        }

        return true;
        
    }
};