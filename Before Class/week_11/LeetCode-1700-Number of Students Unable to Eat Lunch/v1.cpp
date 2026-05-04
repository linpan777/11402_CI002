class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int one_std{0}, one_sand{0};
        queue<int> student_q;
        queue<int> sandwiche_q;
        for(int i{0}; i < students.size(); i++)
        {
            if(students[i] == 1)
                one_std++;
            student_q.push(students[i]);
        }
        for(int i{0}; i < sandwiches.size(); i++)
        {
            if(sandwiches[i] == 1)
                one_sand++;
            sandwiche_q.push(sandwiches[i]);
        }
        if(one_std == one_sand)
            return 0;

        int vaild{0}, temp;
        while(vaild < sandwiche_q.size())
        {
            if(student_q.front() == sandwiche_q.front())
            {
                student_q.pop();
                sandwiche_q.pop();
                vaild = 0;
            }
            else
            {           
                student_q.push(student_q.front());
                student_q.pop();
                vaild++;
            }
        }

        return student_q.size();
    }
};