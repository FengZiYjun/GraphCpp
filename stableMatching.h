/**
	An implementation of stable matching

*/

struct Girl{
	int id;
	int[] preference_list;
};

struct Boy{
	int id;
	int[] preference_list;
};

class StableMatching{
public:
	StableMatching(int);
	void getPreferenceList();
	void match(int*);

private:
	int numOfBoys;
	Boy** boys;
	Girl** girls;
};





