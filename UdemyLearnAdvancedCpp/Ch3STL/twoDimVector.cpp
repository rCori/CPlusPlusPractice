/* twoDimVector.cpp
 * Simple demonstration of how we can use the
 * flexibility of templace types in stl to make
 * a vector of vectors, or a two-dimensional
 * vectors. They can be used like two-dimensional
 * arrays can, except
 */

#include <iostream>
#include <vector>

//The verbosity of the 
using namespace std;

int main(){
	//First one we can initialize
	vector< vector<int> > matrix_1(4,vector<int>(4,1));
	//This is now a 4x4 matrix of 1's
	cout << "Printing initialized two-dimensional vector" << endl;
	for(vector< vector<int> >::iterator it1 = matrix_1.begin(); 
		it1 != matrix_1.end(); it1++){
		for(vector<int>::iterator it2 = (*it1).begin();
			it2 != (*it1).end(); it2++){
				cout << *it2 << " ";
		}
		cout << endl;
	}

	//Extra space for cleanliness of output
	cout << endl << endl;


	//Now we can do the same only inserting all of our values
	vector< vector<int> > identMat;
	//Initialize rows of empty vectors
	vector<int> identMatRow;
	identMat.push_back(identMatRow);
	identMat.push_back(identMatRow);
	identMat.push_back(identMatRow);
	identMat.push_back(identMatRow);

	//First row
	identMat[0].push_back(1);
	identMat[0].push_back(0);
	identMat[0].push_back(0);
	identMat[0].push_back(0);

	//Second Row
	identMat[1].push_back(0);
	identMat[1].push_back(1);
	identMat[1].push_back(0);
	identMat[1].push_back(0);

	//Third Row
	identMat[2].push_back(0);
	identMat[2].push_back(0);
	identMat[2].push_back(1);
	identMat[2].push_back(0);
	
	//Fourth Row
	identMat[3].push_back(0);
	identMat[3].push_back(0);
	identMat[3].push_back(0);
	identMat[3].push_back(1);

	//Now print as we did previously
	cout << "Printing manually populated two-dimensional vector" << endl;
	for(vector< vector<int> >::iterator it1 = identMat.begin(); 
		it1 != identMat.end(); it1++){
		for(vector<int>::iterator it2 = (*it1).begin();
			it2 != (*it1).end(); it2++){
				cout << *it2 << " ";
		}
		cout << endl;
	}
}
