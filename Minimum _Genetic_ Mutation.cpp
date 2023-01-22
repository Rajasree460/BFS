class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {

        unordered_set<string> dict;

        // insert all the words of bank into dict

        for(auto gene : bank)
        {
            dict.insert(gene);
        }

        // apply bfs

        // declare a queue

        queue<string> q;

        // push the start into queue

        q.push(start);

        // declare a vis set

        unordered_set<string> vis;

        // mark start as visited

        vis.insert(start);

        // characters that are present in the gene

        vector<char> characetrs = {'A', 'C', 'G', 'T'};

        // steps will keep track of minimum steps required

        int steps = 0;

        while(!q.empty())
        {
            int size = q.size();

            while(size--)
            {
                auto str = q.front();

                q.pop();

                // if end gene is found

                if(str == end)
                {
                    return steps;
                }

                string temp = str;

                // traverse over gene

                for(int i = 0; i < 8; i++)
                {
                    str = temp;

                    // change one character

                    for(auto ch : characetrs)
                    {
                        str[i] = ch;

                        // if the str is present in dict and str is not visited the push into q and mark visited

                        if(dict.count(str) && vis.count(str) == 0)
                        {
                            vis.insert(str);

                            q.push(str);
                        }
                    }
                }
            }

            // increment steps

            steps++;
        }

        return -1;
    }
};
