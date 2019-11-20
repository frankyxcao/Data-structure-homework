#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std; 
#define maxsize 100

template<typename T>
class len{
	private:
		int curlen;
		T* a;
		int left;
		int right;
		void qsort(int left, int right){
	    	if(left<right){
	    		int temp = partition(left,right);
	    		qsort(left,temp-1);
	    		qsort(temp+1,right);
			}
		}
		int partition(int low, int high){
			T key = a[low];
			while(low<high){
				while(low<high&&a[high]>key)
				high--;
				a[low] = a[high];
				while(low<high&&a[low]<=key)
				low++;
				a[high] = a[low];
			}
			a[low] = key;
			return low;
		}
//-----------------------------------------------------------------------------------------------
	public:
		void init(){
			a = new T[maxsize]();
	        curlen = 0;
	        cout<<"Init len success! The len can contain "<<maxsize<<" elements."<<endl;
		}
		void destory(){
			delete a;
		}
		void insert(T n){//n is the element inserted into the len.
		    if(curlen < maxsize - 1){
			a[curlen] = n;
			startsort();
			curlen++;
		}
		    else
		    cout<<"Len is full!"<<endl;
		    return;
		
		}
		void outlength(){
			cout<<"The length of the len is: "<<curlen<<endl;
		}
	    void output(){
	    	if(curlen!=0){
	    	int i;
	    	for(i=0;i<curlen;i++){
	    		cout<<a[i]<<" ";
			}
			cout<<endl;
		}
		    else
		    cout<<"The len is empty!"<<endl;
		return;
		}
		void startsort(){
			left = 0;
			right = curlen;
			qsort(left,right);
		}
		void startserach(T n){//n is the element wanted.
			left = 0;
			right = curlen;
			search(n,left,right);
		}
		void search(T n, int left, int right){
			if(left>right){
				cout<<"Fail to find "<<n<<"!"<<endl;
				return;
			}
			
			int mid = (left + right)/2;
			if(a[mid] == n)
			cout<<n<<" found. In the position "<<mid<<" ."<<endl;
			else if(a[mid]>n)
			search(n,left,mid-1);
			else if(a[mid]<n)
			search(n,mid+1,right);
		}
		
};

int main(){
	len<int> Len;
	Len.init();
	int n = 0;
	int temp = 0;
	while(n != -1){
		cout<<"----------------------------------------------"<<endl
		<<"Please input number to edit len."<<endl
		<<"1 Insert elements."<<endl
		<<"2 Output the len."<<endl
		<<"3 Search element."<<endl
		<<"-1 Exit edit."<<endl
		<<"----------------------------------------------"<<endl; 
		cin>>n;
		if(n==1){
			cout<<"Input the number"<<endl;
			cin>>temp;
			Len.insert(temp);
		}
		else if(n==2){
			Len.output();
		}
		else if(n==3){
			cout<<"Input the element wanted."<<endl;
			cin>>temp;
			Len.startserach(temp);
		}
	}
	Len.destory();
	
	return 0;
}

