#include <iostream>
#include <stdio.h>
using namespace std;

template<class T>
class order{
	private:
		int maxsize;
		int presentsize;
		int currentlo;
		
		
	public:
	    T *listarrary;
	    void creatlist(int n){
		    T *array = new T[ n ]();
			listarrary = array;
		//	cout<<"Create array successfully!"<<endl<<endl;		
}; 

        //以下为处理函数 
        void change(int n){ 
        	int temp,i;
        	
        	for( i = 0; i < n / 2; i++){
        		temp = listarrary[ i ];
        		listarrary[ i ] = listarrary[ n - i - 1 ];
        		listarrary[ n - i - 1] = temp;
			}
			
		//	cout<<"Change Successfully!"<<endl;
		}
		
		void input(int n){
			cout<<"请在此输入元素."<<endl;
			int i;
			for( i = 0; i < n; i++)
			cin>>listarrary[i];
		}
		
		void output(int n){
			int i;
			for( i = 0; i < n; i++ )
			cout<<listarrary[i]<<" ";
			cout<<endl;
		}
};

int main(){
	int n, i;    //n is the max length of array
	order< int > intorder;
	
	cout<<"请输入元素的个数"<<endl;
	cin >> n;
	intorder.creatlist( n );
	
	intorder.input( n );
	
	intorder.change( n );
	
	intorder.output( n );
	
	delete intorder.listarrary;
}
