#include <stdio.h>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
#define maxtreenum 11
#define Stacklength 10000 //change the length of stack here.

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
    int empty()
    {
        if (size == 0)
            return 0;

        else
            return 1;
    }
    void stackinit()
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

    int pushfrombuttom(T n)
    {

        element[size] = n;
        size++;
        cout << "Push success!" << endl;
        return 0;
    }

    T popfrombuttom()
    {
        if (size == 0)
        {
            cout << "No element in this link!" << endl;
            return 0;
        }
        else
            cout << "The element popped is: " << element[size - 1] << endl;
        return element[size - 1];
    }
};

template <class T>
class seqqueue
{
private:
    int rear;   //the address + 1 of the latest element in.
    int front;  //the address of the first element out.
    int quelen; //length of current queue.
    T *queuepointer;
    int totallength;

public:
    void init(int n)
    { //n is the length of queue. Initiate queue.
        queuepointer = new T[n];
        totallength = n;
        rear = 0;
        front = 0;
        quelen = 0;
        cout << "Create queue success!" << endl;
    }

    int fulljudger()
    {
        return ((rear + 1) % totallength == front); //If full return 1, or return 0.
    }

    int emptyjudger()
    {
        return (front == rear); //If empty return 1, or return 0.
    }

    void destroy()
    {
        delete[] queuepointer;
    }

    void inqueue(T n)
    { //n is the element insert in queue.
        if (fulljudger())
        {
            cout << "Current queue is full!" << endl;
            return;
        }
        quelen++;
        queuepointer[rear] = n;
        rear = (rear + 1) % totallength;
    }

    T outqueue()
    {
        if (emptyjudger())
        {
            cout << "Current queue is empty!" << endl;
            return NULL;
        }
        quelen--;
        //cout << "The element out is: " << queuepointer[front] << endl;
        front = (front + 1) % totallength;
        return queuepointer[front];
    }

    void outquelen()
    {
        cout << "The amount of elements in the queue is: " << quelen << endl;
    }
};

template <class T>
class treeelem
{
public:
    T data;
    treeelem<T> *left;
    treeelem<T> *right;
    treeelem<T> *father;
    int counter;
};

template <class T>
class tree : public treeelem<T>, public seqqueue<T>, public Stack<T>
{
protected:
    treeelem<T> *current;
    treeelem<T> *root;
    queue<treeelem<T> *> pointerqueue;
    stack<treeelem<T> *> findstack;

public:
    void inittree()
    {
        root = new treeelem<T>;
        //root->left = new treeelem<T>;
        //root->right = new treeelem<T>;
        root->counter = -1;
        //root->left->counter = -1;
        //root->right->counter = -1;
        root->father = root;
        cout << "Init tree successfully!" << endl;
        pointerqueue.push(root);
        //pointerqueue.inqueue(root->left);
        // pointerqueue.inqueue(root->right);
    }

    void insert(int n)
    { // n is the Elem inserted in the location pointed by the elem poped from queue.
        treeelem<T> *temp;
        temp = pointerqueue.front();
        pointerqueue.pop();
        temp->data = n;
        temp->counter = 1;
        temp->left = new treeelem<T>;
        temp->left->counter = -1;
        temp->left;
        temp->right = new treeelem<T>;
        temp->father = temp;
        temp->right->counter = -1;
        pointerqueue.push(temp->left);
        pointerqueue.push(temp->right);
    }

    void firstorder()
    {
        stack<treeelem<T> *> treenodestack;
        treeelem<T> *node = root;

        while (node->counter != -1 || !treenodestack.empty())
        {

            while (node->counter != -1)
            {
                cout << node->data;
                //cout<<"yes"<<endl;
                treenodestack.push(node);
                node = node->left;
            }

            if (!treenodestack.empty())
            {
                node = treenodestack.top();
                treenodestack.pop();
                node = node->right;
                //cout<<"one root"<<endl;
            }
        }
        //cout<<"finish"<<endl;
        cout << endl;
    }

    void midorder()
    {
        stack<treeelem<T> *> treenodestack;
        treeelem<T> *node = root;

        while (node->counter != -1 || !treenodestack.empty())
        {

            while (node->counter != -1)
            {
                //cout<<node->data;
                //cout<<"yes"<<endl;
                treenodestack.push(node);
                node = node->left;
            }

            if (!treenodestack.empty())
            {
                node = treenodestack.top();
                cout << node->data;
                treenodestack.pop();
                node = node->right;
                //cout<<"one root"<<endl;
            }
        }
        //cout<<"finish"<<endl;
        cout << endl;
    }
};

int main()
{
    //cout << "The tree can contain less than " << maxtreenum - 4 << " Elems" << endl;
    tree<int> t1;
    t1.inittree();
    int i = 0;
    int n = 0;

    /* while(i<6){
    	cin>>n;
    	t1.insert(n);
    	i++;
	} */
    //for test

    while (i != 4)
    {
        cout << "------------------------------------------------" << endl
             << "Input corresponding number to edit the tree." << endl
             << "1 input element" << endl
             << "2 output elements in tree by front order" << endl
             << "3 output elements in tree by middle order" << endl
             << "4 end edit" << endl;
        cin >> i;
        switch (i)
        {
        case 1:
        {
            cout << "Insert Elem" << endl;
            cin >> n;
            t1.insert(n);
            break;
        }

        case 2:
        {
            t1.firstorder();
            break;
        }

        case 3:
        {
            t1.midorder();
            break;
        }
        }
    }

    system("pause");
    return 0;
}
