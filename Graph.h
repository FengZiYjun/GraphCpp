/*---------------------------------------------------

	how to destruct the node and edge ? 

*/

#include <iostream>
#include <vector>
#include <algorithm>

class Edge;

class Node{

public:
	Node(int);
	void addIn(Edge*);
	void addOut(Edge*);
	void removeOut(Edge*);
	void removeIn(Edge*);/* 
	int numOfOutEdge();
	int numOfInEdge();
	Edge* getInEdge(int);
	Edge* getOutEdge(int); */
	int getIndex();
	
	~Node();
	
private:
	// index starts from 0
	int index;
	std::vector<Edge*> In;
	std::vector<Edge*> Out;
	
};

class Edge{
public:
	Node* getFrom();
	void addFrom(Node*);
	Node* getTo();
	void addTo(Node*);
	~Edge();
	
private:
	Node* from;
	Node* to;
};


/*
	add or delete nodes and edges
*/
class GraphManager{
public:
	GraphManager();
	
	int numOfNode();
	
	int numOfEdge();

	// Node operations
	void addNode();
	
	bool deleteNode(int);

	// Edge operations
	// index from 0
	void addEdge(int, int);
	
	bool deleteEdge(int, int);
	
private:
	std::vector<Node*> pNode;
	std::vector<Edge*> pEdge;
	
};

/**
	The private member should be const, but methods need to make sure the 
	read-only accessiblity. 
*/
class GraphDisplay{
public:
	GraphDisplay(GraphManager&);
	void loadGraph(GraphManager&);
	void showBasicInfo(std::ostream&);
private:
	GraphManager& manager;
};
