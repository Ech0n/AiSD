#include <algorithm>
#include <utility>
#include <iostream>
#define DEFAULT_PQUEUE_SIZE 100

template <class T>
class QE{
	public:
		QE(){}
		QE(T x,int k):priority(k),obj(x){}
		int priority;
		T obj;
};

template <class T>
class PriorityQueue{
	private:
		void heapifydown(int);
		QE<T> *arr;
		int reserved_size;
		int element_count;
		void downsize();
		void upsize();
		int parent_indx(int);
		int left_indx(int);
		int right_indx(int);
	public:
		PriorityQueue<T>():arr(new QE<T>[DEFAULT_PQUEUE_SIZE]),reserved_size(DEFAULT_PQUEUE_SIZE),element_count(0){}
		void insert(T,int);
		QE<T> max();
		QE<T> extractmax();
		int size() const { return element_count;};
		void print();

};

template <class T>
int PriorityQueue<T>::parent_indx(int i){
	return (i-1)/2;
}
template<class T>
int PriorityQueue<T>::right_indx(int i){
	int ret = 2*i +2;
	if(ret>element_count-1){return -1;}
	return ret;
}
template<class T>
int PriorityQueue<T>::left_indx(int i){
	int ret = 2*i +1;
	if(ret>element_count-1){return -1;}
	return ret;
}

template <class T>
void PriorityQueue<T>::insert(T x,int k){
	if(element_count+1 > reserved_size){
		upsize();
	}
	QE<T> element = QE<T>(x,k);
	arr[element_count] = element;
	int i = element_count;
	while( i>0 && arr[parent_indx(i)].priority <k ){
		std::swap(arr[ parent_indx(i)],arr[i]);
		i = parent_indx(i);
	}
	element_count++;
}

template <class T>
QE<T> PriorityQueue<T>::max(){
	if(element_count == 0){
		return NULL;
	}
	return arr[0];
}

template <class T>
QE<T> PriorityQueue<T>::extractmax(){
	if(element_count< (reserved_size+1)/4){
		downsize();
	}
	element_count--;
	QE<T> extracted_element = arr[0];
	arr[0] = arr[element_count];
	heapifydown(0);
	return extracted_element;
}
template <class T>
void PriorityQueue<T>::heapifydown(int i ){
	int left = left_indx(i);
	int right = right_indx(i);
	int biggest = i;
	if(left!=-1){
		if(arr[left].priority > arr[biggest].priority){
			biggest = left;
		}
		if(right!=-1 && arr[right].priority >arr[biggest].priority){
			biggest = right;
		}
		if(biggest != i){
			QE<T> temp = arr[biggest];
			arr[biggest] = arr[i];
			arr[i] = temp;
			heapifydown(biggest);
		}
	}
}
template <class T>
void PriorityQueue<T>::upsize(){
    int new_size = reserved_size*2;
    QE<T> *new_arr = new QE<T>[new_size];
    std::move(arr,arr+ element_count,new_arr);
    delete [] arr;
    arr = new_arr;
    reserved_size = new_size;
}

template <class T>
void PriorityQueue<T>::downsize(){
    int new_size = reserved_size/2;
    QE<T> *new_arr = new QE<T>[new_size];
    std::move(arr,arr+element_count,new_arr);
    delete [] arr;
    arr = new_arr;
    reserved_size = new_size;
}

template<class T> 
void PriorityQueue<T>::print(){
	int level =1;
    for(int i = 0 ; i < element_count ;i++){
		if(i+1==level){
			level *= 2;
			std::cout<<std::endl;
		}
        std::cout<<"(p: "<< arr[i].priority<<",val: "<<arr[i].obj<<") ";
    }
    std::cout<<std::endl;
}