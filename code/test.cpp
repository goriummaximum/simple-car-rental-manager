#include <iostream>
#include <string>

using namespace std;

class people
{
    public:

        people(string input_hair = "", string input_body = "gg")
        {
            hair = input_hair;
            body = input_body;
        }

        string hair;
        string body;
};

class student : public people
{
    private:
        int id;
    
    public:
        student(int input_id);
        void set_id(int input)
        {
        }
        int get_id()
        {
            return id;
        }
};

student::student(int input_id = 2) : people{"4", "6"}, id{input_id}{}

int main()
{
    student stu;
    cout << stu.get_id();
    cout << stu.hair;
    cout << stu.body;

    return 0;
}