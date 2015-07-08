#include<iostream>
using namespace std;

class Assign2{
	int a[20],cnt,pivot,spoint;
	public:
	//Accept List items from user
	void getList(){
		cout<<"\n\tEnter List Count : ";
		cin>>cnt;
		cout<<"\n\tEnter "<<cnt<<" List Elements : \n";
		for(int i=0;i<cnt;i++){
			cout<<"\t\tElement ["<<i+1<<"] : ";
			cin>>a[i];
		}
	}
	//Display List Items [sorted/unsorted]
	void showList(){
		cout<<"\n\tList Elements : \n\t";
		cout<<"-----------------------\n\t";
		for(int i=0;i<cnt;i++){
			cout<<"["<<a[i]<<"] ";
		}
		cout<<"\n";
	}
	//Set the pivot element	
	void setPivot(){
		pivot=a[0];
	}
	//Sorting Algorithm	
	void quicksort(int low,int high){
		while(low<high){
		   	spoint=split(low,high);
			quicksort(low,spoint-1);
			quicksort(spoint+1,high);
		}
	}
	//Splitting list recursively
	int split(int low,int high){
		int i, p, q, t ;
		p = low + 1 ;
		q = high ;
		i = a[low] ;
		while (q >= p)
		{
			while(a[p] < i)
				p++ ;
			while(a[q] > i)
				q-- ;
			if (q > p)
			{
				t = a[p] ;
				a[p] = a[q] ;
				a[q] = t ;
			}
		}
		t = a[low] ;
		a[low] = a[q] ;
		a[q] = t;
		return q;
	}

	//Return List count
	int getCount(){
		return cnt;
	}

};

int main(){
	//Create an object.
	Assign2 obj=Assign2();
	//Accept elements of list
	obj.getList();
	//show unsorted element list
	obj.showList();
	//Sorting Logic
	obj.quicksort(0,obj.getCount()-1);
	//Show sorted list
	obj.showList();	
	return 0; 
}
