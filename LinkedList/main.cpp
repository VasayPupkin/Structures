#include <iostream>
#include <LinkedList.h>

using namespace std;

int main()
{
    LinkedList<int> list;
    list.push_back(10);
    list.push_back(11);
    list.push_back(12);
    list.push_front(9);
    list.push_front(8);
    int x = list.const_first();
    int y = list.const_last();
    int z = list.at(1);
    cout << "x= "<<x << " y = "<< y <<" z = "<< z <<endl;
    cout << list.size()<<endl;
    list.pop_back();
    list.pop_front();
    cout << list.const_first() <<"   " << list.const_last()<<endl;
    cout << "Hello World!" << endl;
    return 0;
}
