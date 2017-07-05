#include <iostream>
#include "stableMatching.h"

using namespace std;

/**
	Class Person 
*/
Person::Person(int identity): id(identity){
	this->preference_list = NULL;
}

void Person::loadList(int* list, int readInNum){
	preference_list = new int[readInNum];
	if(preference_list==NULL){
		exit(1);
	}
	for(int i=0;i<readInNum;i++){
		preference_list[i] = list[i];
	}
}

/**
	class Boy
*/
Boy::Boy(int id):Person(id){
	
}


/**
	class Girl
*/
Girl::Girl(int id):Person(id){
	
}


/**
	class StableMatching
*/
StableMatching::StableMatching(int numOfBoys){
	this->numOfBoys = numOfBoys;
	this->boys = new Boy*[numOfBoys];
	if(this->boys == NULL){
		exit(1);
	}
	this->girls = new Girl*[numOfBoys];
	if(this->girls == NULL){
		exit(1);
	}
	
}

void StableMatching::getPreferenceList(istream& in){
	for(int i=0;i<numOfBoys;i++){
		boys[i] = new Boy(i+1);
		int tmp[numOfBoys];
		for(int j=0;j<numOfBoys;j++){
			in >> tmp[j];
		}
		boys[i]->loadList(tmp, numOfBoys);
	}
}







