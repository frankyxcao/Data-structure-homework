#include <iostream>
using namespace std;

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

    void destroy(){
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

    void outqueue()
    {
        if (emptyjudger())
        {
            cout << "Current queue is empty!" << endl;
            return;
        }
        quelen--;
        cout << "The element out is: " << queuepointer[front] << endl;
        front = (front + 1) % totallength;
        return;
    }

    void outquelen()
    {
        cout << "The amount of elements in the queue is: " << quelen << endl;
    }
};

int main()
{
    int n;
    cout << "Input the number of element the queue can contain" << endl;
    cin >> n;

    seqqueue<int> q1;
    q1.init(n);

    while (1)
    {
        cout << "------------------------------------------------" << endl
             << "Input corresponding number to edit the queue." << endl
             << "1 input element" << endl
             << "2 output element" << endl
             << "3 show number of elements in the queue" << endl
             << "4 end edit" << endl;
        cin >> n;

        if (n == 1)
        {
            cout << "Input the element." << endl;
            cin >> n;
            q1.inqueue(n);
        }

        else if (n == 2)
        {
            q1.outqueue();
        }

        else if (n == 3)
        {
            q1.outquelen();
        }

        else if (n == 4)
            break;
    }

    q1.destroy();
    system("pause");
    return 0;
}
