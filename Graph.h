#include <vector>
#include <algorithm>

class Edge;

class Node{
private:
	// index starts from 0
	int index;
	std::vector<Edge*> In;
	std::vector<Edge*> Out;
	
public:
	Node(int);
	void addIn(Edge*);
	void addOut(Edge*);
	void removeOut(Edge*);
	void removeIn(Edge*);
};

class Edge{
private:
	Node* from;
	Node* to;
public:
	Node* getFrom();
	void addFrom(Node*);
	Node* getTo();
	void addTo(Node*);
};


/*
	add or delete nodes and edges
*/
class GraphManager{
	std::vector<Node*> pNode;
	std::vector<Edge*> pEdge;
	
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

};

class GraphDisplay{
	GraphManager& manager;
public:
	GraphDisplay(GraphManager&);
	void loadGraph(const GraphManager&);
	void showBasicInfo();
};
