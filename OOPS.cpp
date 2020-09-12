#include<iostream>
using namespace std;
class Encapsulation
{
    private:
        int x;
    public:
        void set(int value)
        {
            x = value;
        }    
        int get()
        {
            return x;
        }

};

int main()
{
   Encapsulation a;

    a.set(5);
    int b = a.get();
   cout<<b;
    
}