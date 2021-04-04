#include<iostream>
using namespace std;
 
 class a
 {
     private:
        int x;
    
    public:
        a(int input_x = 0)
        {
            x = input_x;
        }

        void set_x(int input_x)
        {
            x = input_x;
        }

        int *get_x()
        {
            return &x;
        }
        
 };

int main(void)
{
    auto x = a();
    auto *y = x.get_x();
    cout << *y;
    x.set_x(7);
    cout << *y;


    return 0;
}