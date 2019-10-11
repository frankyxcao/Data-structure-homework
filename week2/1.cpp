#include <stdio.h>
#include <iostream>
using namespace std;

template <class T>
class Link
{
public:
    T element; //data stored in this link
    Link *next;
    Link(const T &item, Link *nextval = NULL)
    { // 'nextval' will get the address of following link
        element = item;
        next = nextval;
    }

    Link(Link *nextval = NULL)
    {
        next = nextval;
    }
};

template <class T>
class Linklist : public Link<T>
{
private:
    Link<T> *first;   //pointer to the first one
    Link<T> *tail;    //pointer to the last one
    Link<T> *present; //pointer to the present Link
    void init()
    {
        present = tail = first = new Link<T>;
        //	cout<<"init successfully!"<<present<<" "<<present->element<<endl;  //test point 1
    }

public:
    LLst()
    {
        init();
    }

    void insert(T x)
    { //  'x' is the Elem inserted in the link
        Link<T> *s = new Link<T>;
        if (!s)
        {
            cout << "failed to get room" << endl;
            return;
        }

        s->element = x;
        present->next = s;
        present = s;
        tail = s->next;
        return;
    }

    void read(T x)
    {
        int i;
        Link<T> *curr;
        curr = first->next;

        cout << endl;
        for (i = 0; i < x; i++)
        {
            cout << curr->element << " ";
            curr = curr->next;
        }
    }

    //process fun followed
    void change(int x)
    { // x is the number of Elem, so template is unnecessary
        Link<T> *tempbefore;
        Link<T> *tempafter;
        Link<T> *temp;
        tempbefore = first->next;
        temp = tempbefore->next;
        tempbefore->next = NULL;

        int i;
        for (i = 0; i < x - 2; i++)
        {
            tempafter = temp->next;  //changing
            temp->next = tempbefore; //changing
            tempbefore = temp;       //move to next Elem
            temp = tempafter;        //move to next Elem
        }

        temp->next = tempbefore;
        first->next = temp; //chaning 'first' and 'tail'
    }
};

int main()
{
    Linklist<int> link1;
    link1.LLst();

    int n, i, temp;
    cout << "input number of elements" << endl;
    cin >> n;
    cout << "input elements" << endl;

    for (i = 0; i < n; i++)
    {
        cin >> temp;
        link1.insert(temp);
    }

    link1.change(n);
    link1.read(n);

    system("pause");

    return 0;
}
