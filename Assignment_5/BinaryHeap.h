#include "RuntimeException.h"
#include <iostream>
#include <vector>


template<typename ElemType>
class Item {
	private:
		int key; // JobID
		ElemType elem; // priority
		int length; // length
	public:
		Item(const int k = 0, const ElemType& e = ElemType(), const int l = 0) : key(k), elem(e), length(l) { }
		const int getKey() const { return key; }
		const int getLength() const { return length; }
		const ElemType& getElem() const { return elem; }
		void setKey(const int k) { key = k; }
		void setElem(const ElemType& e) { elem = e; }
};

template<typename ElemType>
class PQComp {
	public:
		int operator() (const Item<ElemType>& e1, const Item<ElemType>& e2) { return e1.getElem() - e2.getElem(); }
};
	


template<typename ElemType, typename Comp>
class BinaryHeap {
		class EmptyHeap : public RuntimeException {
		   public:
			 EmptyHeap() : RuntimeException("Empty Heap") {}
		   };
	private:
		Comp comp; // Comp is a comparator class

		int curSize; //number of elements in heap
		ElemType *array; //(dynamic) heap array
		int length; //the length of the array
		bool orderOK;
		static const int DEF_SIZE = 8;
		
		void getNewArray(int newSize) {
			array = new ElemType[newSize];
			length = newSize;
		}
	
	public: // templated class BinaryHeap (cont)
		BinaryHeap(int size = DEF_SIZE) { //constructor
			curSize = 0;
			orderOK = true;
			getNewArray(size);
			}
		ElemType& findMin() throw(EmptyHeap) {
			if ( isEmpty() ) throw EmptyHeap();
			if (! orderOK) buildHeap();
			return array[0];
		}
		
		bool isEmpty( ) const {  return curSize == 0; }
		
		void buildHeap(){
			for (int i = (curSize-2)/2; i >= 0; i--) walkDown(i);
			orderOK = true;
		}
		
		void checkSize( ) {
			if (curSize == length) {
				ElemType *oldArray = array;
				getNewArray(2*curSize);
				for (int i = 0; i < curSize; i++)
				array[i] = oldArray[i];
				delete [] oldArray;
			}
		}
		
		void insert(const ElemType& x){
			checkSize( );
			//walk up (establish heap order now)
			int hole = curSize++;
			for ( ; hole > 0 && comp(array[(hole-1)/2], x) > 0; hole = (hole-1)/2){
				array[hole] = array[(hole-1)/2];
			}
			array[hole] = x;
			
			// add this to account for jobs with same priority
			while(comp(array[(hole - 1) / 2], array[hole]) == 0 && (hole != 0)){
				if(array[hole].getElem() == array[(hole-1)/2].getElem()){
					if(x.getKey() < array[(hole - 1) / 2].getKey()){
						array[hole] = array[(hole - 1) / 2];
						array[(hole - 1) / 2] = x;
					}
				}
				hole = (hole - 1) / 2;
			}
		}
		
				
		void deleteMin() throw(EmptyHeap){			
			array[0] = array[ --curSize ]; //decrease size
			walkDown(0);
		}
		
		void walkDown(int hole){
			int child;
			ElemType key = array[hole];
			
			//cout << "Left child job: " << array[2*hole + 1].getKey() << endl;
			//cout << "Right child job: " << array[2*hole + 2].getKey() << endl;
			//cout << "Current size of queue: " << curSize << endl;
			for ( ; 2*hole+1 < curSize; hole = child) {
				child = 2*hole+1;
				//cout << "value of child: " << child << endl;
				if (child != curSize-1 && comp(array[child], array[child+1]) > 0){
					child++; // right child = 2*hole+2
				}
				else if(comp(array[child], array[child + 1]) == 0){
					//cout << "im here" << endl;
					if(array[child].getKey() > array[child + 1].getKey()){
						child++;
						//cout << "here too" << endl;
					}
				}
				if (comp(key, array[child]) > 0) {
					array[hole]=array[child];
				}
				else if(comp(key, array[child]) == 0){
					if(key.getKey() > array[child].getKey()){
						array[hole] = array[child];
					}
				}
				else break;
			}
			array[hole] = key;
		}
		
};

template<typename ElemType>
class PriorityQueue {
	protected:
		typedef Item<ElemType> _Item;
		typedef PQComp<ElemType> _PQComp;
	private:
		BinaryHeap<_Item, _PQComp> T;
		static const int DEF_SIZE = 8;
	public:
		PriorityQueue(int size = DEF_SIZE) : T(size) { }
		bool isEmpty() const { return T.isEmpty(); }
		void insertItem(const int k, const ElemType& e, const int l) { T.insert(_Item(k, e, l)); }
		const ElemType& minElement()
		{
			if(T.isEmpty()) RuntimeException("Empty Queue");
			return T.findMin().getElem();
		}
		const int minKey()
		{
			if(T.isEmpty()) RuntimeException("Empty Queue");
			return T.findMin().getKey();
		}
		void removeMin()
		{
			if(T.isEmpty()) RuntimeException("Empty Queue");
			T.deleteMin();
		}
};