
/*
LC 1544 - Make The String Great
Time : O(N^3) - traverse every char in string until string is good, erase char in string
Space : O(1) - Create a vector to track missing number

Logic:
1. Make a loop until the string is OK.
2. Traverse every char in the string.
3. If an uppercase letter is found, check whether pos+1 or pos-1 has the lowercase version of that letter.
4. If there is a lowercase letter around ±1 position, erase both the lowercase and uppercase letters.
5. Until there is no modification in a traversal -> exit the loop.
*/

class Solution {
public:
    string makeGood(string s) {
        bool flag = true;
        while (flag)
        {
            bool flag_end = true;
            for (int i=0;i<s.size();i++)
            {
                if ((int)s[i] >= 65 && (int)s[i]<= 90)
                {
                    if ((int)s[i] + 32 == (int)s[i+1])
                    {
                        s.erase(i,2);
                        flag_end = false;

                    }
                    else if (i != 0 && (int)s[i] + 32 == (int)s[i-1])
                    {

                        flag_end = false;
                        s.erase(i-1,2);
                    }
                    // cout<<"i: "<<i<<endl;
                }
            }
            // cout<<(int)'A'<<endl;
            // cout<<(int)'a'<<endl;
            // cout<<(int)'B'<<endl;
            // cout<<(int)'b'<<endl;
            // flag = false;
            if (flag_end) flag =false;
        }
        return s;
    }
};