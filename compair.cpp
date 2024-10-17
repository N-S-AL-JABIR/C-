#include <bits/stdc++.h>
using namespace std;
class student
{
public:
    string name;
    int roll;
    int marks;
    student(string name, int roll, int marks)
    {
        this->marks = marks;
        this->roll = roll;
        this->name = name;
    }
};
class cmp
{
public:
    bool operator()(student a, student b)
    {
        return (a.marks < b.marks);
    }
};
int main()
{
    int n;
    cin >> n;
    priority_queue<string, vector<student>, cmp> pq;
    for (int i = 0; i < n; i++)
    {
        string name;
        int roll, marks;
        cin >> name >> roll >> marks;
        student obj(name, roll, marks);
        pq.push(obj);
    }
    while (!pq.empty())
    {
        cout << pq.top().name << " " << pq.top().roll << " " << pq.top().marks << endl;
        pq.pop();
    }

    return 0;
}
