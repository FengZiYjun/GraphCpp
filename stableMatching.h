/**
	An implementation of stable matching

*/

#include <iostream>

class Person{
public:
	Person(int);
	void loadList(int*, int);
protected:
	int id;
	int* preference_list;	
};

class Boy: public Person{
public:
	Boy(int);
	int nextGirlID();
private:
	int requestGirl;
};

class Girl: public Person{
public:
	Girl(int);
private:
	int loveBoy;
};


class StableMatching{
public:
	StableMatching(int);
	void getPreferenceList(std::istream&);
	void match(int*);

private:
	int numOfBoys;
	Boy** boys;
	Girl** girls;
};





