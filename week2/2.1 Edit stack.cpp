#include <ctime>
#include <stdio.h>
#include <windows.h>
#include <iostream>
using namespace std;
#define Stacklength 3 //change the length of stack here.

template <typename T>
class Stack
{
private:
    T *element;   //Point to current position
    int size;     //Current number of elements
    int capacity; //Total number of elements

    bool ensureCapacity()
    { //Judge whether theres enough room for the current stack.
        if (size >= capacity)
        {
            cout << "no more space for the current stack!" << endl;
            return false;
        }
        else
            return true;
    }

public:
    void init()
    { //Initiate a stack, n is length
        element = new T[Stacklength]();
        size = 0;
        capacity = Stacklength;
        int i;
        for (i = 0; i < capacity; i++)
            element[i] == 0;

        cout << "init Stack successfully!" << endl
             << Stacklength << " elements can be contained in the stack based on current settings." << endl;
    }

    void destroyStack()
    {
        delete[] element;
        cout << "current stack is deleted!" << endl;
    }

    void using_other_stack(Stack<T> n)
    {
        element = n.element;
        capacity = n.capacity;
        size = Stacklength - 1;
        cout << "get address successfully!" << endl;
    }

    int check(Stack<T> s, int n)
    {
        if (n)
        {
            if (size == s.size + 1)
                return 0;
            else
                return 1;
        }
        else
        {
            if (size == s.size - 1)
                return 0;
            else
                return 1;
        }
    }

    int pushfrombuttom(int n, Stack<T> s)
    {
        if (check(s,1))
        {
            element[size] = n;
            size++;
            cout << "Push success!" << endl;
            return 0;
        }
        else
            cout << "full!" << endl;
        return 1;
    }

    int pushfromtop(int n, Stack<T> s)
    {
        if (check(s,0))
        {
            element[size] = n;
            size--;
            cout << "Push success!" << endl;
            return 0;
        }
        else
            cout << "full!" << endl;
        return 1;
    }

    void popfrombuttom()
    {
        if (size == 0)
        {
            cout << "No element in this link!" << endl;
            return;
        }
        else
            cout << "The element popped is: " << element[size - 1] << endl;
    }

    void popfromtop()
    {
        if (size == capacity - 1)
        {
            cout << "No element in this link!" << endl;
            return;
        }
        cout << element[size + 1] << endl;
    }

    void print()
    { 
        int i;
        for(i=0;i<capacity;i++)
        cout<<element[i]<<" ";
        cout<<endl;
    }
};

int main()
{
    Stack<int> s1;
    Stack<int> s2;
    s1.init();
    s2.using_other_stack(s1);

    //s1.out();  //test point1
    //s2.out();  //test point2

    int in;
    while (1)
    {
        cout << "--------------------------------------------------" << endl
             << "Input corresponding number to edit the stack." << endl
             << "1 push S1" << endl
             << "2 push S2" << endl
             << "3 pop S1" << endl
             << "4 pop S2" << endl
             << "5 output element in S1 and S2" << endl
             << "6 end edit" << endl;
        cin >> in;
        if (in == 1)
        {
            cout << "Input element now." << endl;
            cin >> in;
            s1.pushfrombuttom(in, s2);
        }

        else if (in == 2)
        {
            cout << "Input element now." << endl;
            cin >> in;
            s2.pushfromtop(in, s1);
        }

        else if (in == 3)
        {
            s1.popfrombuttom();
        }

        else if (in == 4)
        {
            s2.popfromtop();
        }

        else if(in==5){
            s1.print();
        }

        else if (in == 6)
            break;

        //Sleep(1000); //if unable to run, annotate thie line
    }

    s1.destroyStack();

    system("pause");
}
