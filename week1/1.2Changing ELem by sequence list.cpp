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

        //����Ϊ������ 
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
			cout<<"���ڴ�����Ԫ��."<<endl;
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
	
	cout<<"������Ԫ�صĸ���"<<endl;
	cin >> n;
	intorder.creatlist( n );
	
	intorder.input( n );
	
	intorder.change( n );
	
	intorder.output( n );
	
	delete intorder.listarrary;
}
