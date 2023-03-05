#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <deque>
#include <locale>

using namespace std; //introduces namespace std

const int SIZE = 10; //size of the vector
bool DONE =0;        //boolean to check if sorting is completed

//fills vector with random integers
void fill_vector(vector<int> & v){
  srand(time(0));
   for (int i = 0; i < SIZE;i++)
     v.push_back(rand() % 1000);
}

//split puts runs of ordered numbers alternately into deque a & b
void split(const vector<int> v, deque<int> & a, deque<int> & b){
	int i=0, j=0, k=0;

	while (v.size() > j ){
		a.push_back(v[j]);
		j++;
		while (j < v.size() && a[i] < v[j]){ //fills 
		  //cout << a[i] << " ai v[j] " <<v[j] << endl;
		  //cout << "on a pushing " << v[j] << endl;
			a.push_back(v[j]);
	        //cin.get(); 
			i++;
			j++;	
    		//cout << i << " =  i in a   j = " << j <<"  "<< a[i] << endl;
		}

		if(j<v.size()){
			b.push_back(v[j]);
			j++;
			while (j < v.size() && b[k] < v[j]){
		    //cout <<b[k]<< " on b pushing " << v[j] << endl;
				b.push_back(v[j]);
				//cin.get();
				k++;
				j++;
				//cout << k << " =  k in b  j = " << j <<  endl;					
			}
		}
	}
				//checks for completion of the sorting
	if(b.empty()){
		DONE = 1;
	}
}

//merges deque a & deque b into vector v using merge algorithm
void merge(vector<int> & v, deque <int> & a, deque<int> & b){
 int i=0;
 				// Loop thru both deques
  while(!b.empty() && !a.empty()){
  			// This copies the smallest of two values from deques to vector
  	if(a[i]<b[i]){
  		v.push_back(a[i]);
  		a.pop_front();
  		//cout<<"merge from a "<<endl;
  	}
  	if(a[i]>b[i]) {
  		v.push_back(b[i]);
  		b.pop_front();
  		//cout<<"merge from b "<<endl;
  	}
   }
   		//copies values from remaining deque
  	while(!a.empty()){
  		v.push_back(a[i]);
  		a.pop_front();
  	}
  	while(!b.empty()){
  		v.push_back(b[i]);
  		b.pop_front();
  	}

}

//operator << overload
ostream & operator<<(ostream & out , const vector<int> & v){
 for (int i=0 ; i< v.size(); i++)
  out <<  (i%5? ' ' : '\n') << setw(8) << v[i] ;
  			//outputs items with corresponding indexes
  //out <<  (i%5? ' ' : '\n') << setw(8) << "v["<<i<<"] = "<< v[i] ;
 return out; 
}

int main ( void )
{
  system("COLOR 0A");	
  setlocale (LC_ALL, "spanish");
  vector <int> v;
  deque<int> a, b;
  fill_vector(v);
  cout <<"Prueba Compilada de Mezcla Natural el  "<<__DATE__<<", a las "<<__TIME__<<endl;
  cout <<"\nv.tamaño() = "<<v.size()<<"\n"<< v; 
  // cout << v <<endl;
  //cin.get();
  while(!DONE){
  	//cout<<"going into split\n";
  	split(v, a, b);
    while(!v.empty()){
  		v.pop_back();
    }
  	//cout << "sizes " << a.size() << "   " << b.size() << endl;
    merge(v, a, b);
    //cout<<"\nvector V after MERGE "<<v.size()<<endl;
  }
	cout <<"\n\nVector Ordenado v\n"<< v;
	cout <<"\n\nEsto concluye la prueba de la Mezcla Natural"<<endl;
	
	return 0;
}
