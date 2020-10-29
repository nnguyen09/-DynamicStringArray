/***********************************************
Author: <Ngan Nguyen>
Date: <10/20/2020>
Purpose: < create a class called DynamicStringArray that includes member functions that allow it to emulate the behavior of a vector of strings>
Sources of Help: <lecture note, c++ library>
Time Spent: <6 hours>
***********************************************/

/*
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining
good order in the classroom, providing an enriching learning
experience for students, and as training as a practicing computing
professional upon graduation. This practice is manifested in the
University’s Academic Integrity policy. Students are expected to
strictly avoid academic dishonesty and adhere to the Academic
Integrity policy as outlined in the course catalog. Violations will
be dealt with as outlined therein.
All programming assignments in this class are to be done by the
student alone. No outside help is permitted except the instructor and
approved tutors.
I certify that the work submitted with this assignment is mine and was
generated in a manner consistent with this document, the course
academic policy on the course website on Blackboard, and the UMass
Lowell academic code.
Date: 10/20/2020
Name: Ngan Nguyen
*/

#include <iostream>
#include <string>
using namespace std;
class  DynamicStringArray{
public:
//A default constructor that sets the dynamic array to nullptr and sets size to 0.
	DynamicStringArray(): dynamicArray(nullptr), size(0){}
//A function that returns size.
	int getSize(void){
		return size;
	}
//A function a string as input. 
	void addEntry(string newInput);
//function to delete 
	bool deleteEntry(string strDelete);
//getter function
	string getEntry(int i);
//copy constructor
	DynamicStringArray(const DynamicStringArray &l);
//copy assignment operator (= operator)
	DynamicStringArray& operator= (const DynamicStringArray &l);
//destructor function
	~DynamicStringArray();

private:
	string* dynamicArray;
	int size;	//number of entity in the array
};

int main (int argc, char** argv){

	DynamicStringArray A,C;
	string word;
	while(cin>>word){
		A.addEntry(word);
	}

	cout<<"Sentence A has "<<A.getSize()<<" word\n";

	DynamicStringArray B(A);
	cout<<"sentence B:\n";
	for(int i=0;i<B.getSize();i++){
		cout<<B.getEntry(i)<<" ";
	}
	cout<<endl;

	C=B;
	
	for(int i=0;i<5;i++){
		if(C.deleteEntry(C.getEntry(0))){
			cout<<"delete!\n";
		}
	}

	cout<<"Sentence C has "<<C.getSize()<<" word\n";
	cout<<"Sentence C:\n";
	for(int i=0;i<C.getSize();i++){
		cout<<C.getEntry(i)<<" ";
	}
	cout<<endl;
	return 0;
}

void DynamicStringArray::addEntry(string newInput){
	string* temp;
	if(size==0){
		dynamicArray = new string[size+1];
		dynamicArray[size] = newInput;
		size++;	
		
	}else{
		temp = new string[size+1];
		for(int i =0; i<size; i++){
			temp[i] = dynamicArray[i];
		}
		temp[size] = newInput;
		size++;
		delete[] dynamicArray;
		dynamicArray = temp;
		
	}	
}
bool DynamicStringArray::deleteEntry(string strDelete){
	bool boolVal=false;
	int i = 0;
	string* temp= new string[size-1];
	while(i<size){
		if(dynamicArray[i]==strDelete){
			boolVal=true;
			break;
		}
		i++;
	}
		
	if(boolVal==true){
		for(int i=0,j(0); j<size&&j<size-1;i++, j++){
			if(dynamicArray[i]==strDelete){
				i++;
			}
			temp[j]= dynamicArray[i];
		}
		size--;
		delete[] dynamicArray;
		dynamicArray = temp;

	}
	
	return boolVal;
}

string DynamicStringArray::getEntry(int i){
	if( i>=size || i<0 )
		return nullptr;
	else
		return dynamicArray[i];
}

DynamicStringArray::DynamicStringArray(const DynamicStringArray &l){
	size = l.size;
	dynamicArray = new string[size];
	for(int i=0;i<size; i++){
		dynamicArray[i] = l.dynamicArray[i];
	}
}
	
DynamicStringArray& DynamicStringArray::operator= (const DynamicStringArray &l){
	//step0: check if it is self-assignment 
	if(this == &l) return *this;
	//step1: clean up lhs
	if(size > 0){
		delete[] dynamicArray;
		size =0;
	}
	//step2: copy rhs to lhh
	size = l.size;
	dynamicArray = new string[size];
	for(int i=0;i<size; i++){
		dynamicArray[i] = l.dynamicArray[i];
	}
	//return lhs
	return *this;

}
DynamicStringArray::~DynamicStringArray(){
		if(dynamicArray!=nullptr){
			delete[] dynamicArray;
			dynamicArray=nullptr;	
			size = 0;
		}
		
}
			





















