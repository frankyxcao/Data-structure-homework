#include <stdio.h>
#include <iostream>
using namespace std;

template <class T>
class Link{
	public:
		T element;
		Link *next;
		Link(const T& item, Link *nextval = NULL){ // 'nextval' will get the address of following link
		element = item;
		next = nextval;
	}
	
	Link(Link *nextval = NULL){
		next = nextval;
	}
};

template<class T>
class Linklist :public Link<T>{
	private:
		Link<T> *first;  //pointer to the first one
		Link<T> *tail;   //pointer to the last one
		Link<T> *present;//pointer to the present Link
		void init(){
			present = tail = first = new Link<T>;
		//	cout<<"init successfully!"<<present<<" "<<present->element<<endl;  //test point 1
		}
		
	public:
		LLst(){
			init();
			first->next = first;
		}
		
		Link<T> *first1;
		void get(){
			first1 = first;
		}
		void insert(T x){  //  'x' is the Elem inserted in the link 
			Link<T> *s = new Link<T>;
			if(!s){
				cout<<"failed to get room"<<endl;
				return; 
			}
			
			s->element = x;
			present->next = s;
			present = s;
			tail = s->next;
			return;
		}
		
		void read(T x){
			int i;
			Link<T> *curr;
			curr = first->next;
			
			cout<<endl;
			for( i = 0; i < x; i++){
				cout << curr->element <<" ";
				curr = curr->next;
			}
		}
		
		//以下为处理程序 
		void process( Link<T> *link1, Link<T> *link2 ){
			int counter = 0;
			T temp;
			int i;
			
			link1 = link1->next;
			link2 = link2->next;
			
			while( 1 ){
				if( link1->element < link2->element){
					insert(link1->element);
					link1 = link1->next;
					counter++;
				}
				
				else{
					insert(link2->element);
					link2 = link2->next;
					counter ++;
				}
				
				if(link1 == NULL || link2 == NULL)
				    break;
			}
			
			
			
			if(link1 == NULL){
				while( link2 != NULL ){
				insert( link2->element );
				counter++;
				link2 = link2->next;
		 }
		 }
			
			else if(link2 == NULL){
				while( link1 != NULL ){
				insert( link1->element );
				counter++;
				link1 = link1->next;
		 }
		 }
			
			read(counter);
			
			return;
		}
		
};

int main(){
	int n, i, temp;
	Linklist<int> link1;
	Linklist<int> link2;
	Linklist<int> link3;
	link1.LLst();
	link2.LLst();
	link3.LLst();
	
	cout<<"请输入第一个链表元素的个数" <<endl;
	cin>>n;
	cout<<"请输入元素"<<endl;
	for( i = 0; i < n; i++){
		cin>>temp;
		link1.insert(temp);
	}
	
	cout<<"请输入第二个链表元素的个数" <<endl;
	cin>>n;
	cout<<"请输入元素"<<endl;
	for( i = 0; i < n; i++){
		cin>>temp;
		link2.insert(temp);
	}
	
	link1.get();
	link2.get();
	link3.process(link1.first1, link2.first1);
	
	return 0;
}
