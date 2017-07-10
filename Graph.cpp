#include <iostream>
#include "Graph.h"
using namespace std;

/**
	All member functions of Node class
*/
Node::Node(int i){
	index = i;
}

Node::~Node(){
	// It is the node class's responsibility to 
	// delete all edges it connects.
	int numOfOutEdge = Out.size();
	int numOfInEdge = In.size();
			
	for(int i=0;i<numOfOutEdge;i++){
		delete Out[i];
	}
	for(int i=0;i<numOfInEdge;i++){
		delete In[i];
	}
}

void Node::addIn(Edge* e){
	In.push_back(e);
}
void Node::addOut(Edge* e){
	Out.push_back(e);
}
void Node::removeOut(Edge* e){
	remove(Out.begin(),Out.end(),e);
}
void Node::removeIn(Edge* e){
	remove(In.begin(),In.end(),e);
}

int Node::numOfInEdge(){
	return In.size();
}

int Node::numOfOutEdge(){
	return Out.size();
}

Edge* Node::getInEdge(int index){
	return In[index];
}


Edge* Node::getOutEdge(int index){
	return Out[index];
}

int Node::getIndex(){
	return index;
}

/**
	All member functions of Edge class
	
*/

Edge::~Edge(){
	// it is the Edge class's responsibility to 
	// delete all connection info of the node it connects
	from->removeOut(this);
	to->removeIn(this);
}

Node* Edge::getFrom(){
	return from;
}

void Edge::addFrom(Node* p){
	this->from = p;
}

Node* Edge::getTo(){
	return to;
}

void Edge::addTo(Node* p){
	this->to = p;
}


/*
	Member functions of GraphManager class
	
*/

GraphManager::GraphManager(){
}
	
int GraphManager::numOfNode(){
	return pNode.size();
}
	
int GraphManager::numOfEdge(){
	return pEdge.size();
}

// Node operations
void GraphManager::addNode(){
	int nodeNum = this->numOfNode();
	Node* p = new Node(nodeNum+1);
	if(p!=NULL){
		pNode.push_back(p);
	}else{
		//throw nullptr error;
		cout<<"fail to add a node."<<endl;
	}
}
	
bool GraphManager::deleteNode(int indexOfNode){
	int numOfNode = pNode.size();
	for(int i=0;i<numOfNode;i++){
		Node* np = pNode[i];
		if(np->getIndex()==indexOfNode){
			delete np;
			cout<<"delete the node " + indexOfNode << endl;
		}
	}
	
	pNode.erase(pNode.begin() + indexOfNode);
	return true;
}

// Edge operations
// index from 0
void GraphManager::addEdge(int i, int j){
	Edge* p = new Edge();
	Node* pi = pNode[i];
	Node* pj = pNode[j];
	if(p!=NULL){
		p->addFrom(pi);
		p->addTo(pj);
		pi->addOut(p);
		pj->addIn(p);
		
	}else{
		// throw 
		cout<<"Error: fail to add an edge."<<endl;
	}
}
	
bool GraphManager::deleteEdge(int i, int j){
	Node* from = pNode[i];
	Node* to = pNode[j];
	Edge* p = NULL;
	for(int i=0;i<pEdge.size();i++){
		if(pEdge[i]->getFrom() == from && pEdge[i]->getTo() == to){
			p = pEdge[i];
			break;
		}
	}
	if(p!=NULL){
		p->getFrom()->removeOut(p);
		p->getTo()->removeIn(p);
		delete p;
	}else{
		// throw
		cout<<"fail to find the node."<<endl;
	}
	return true;
}


/**
	member functions of GraphDisplay class

*/
GraphDisplay::GraphDisplay(GraphManager& ref):manager(ref){

}
	
void GraphDisplay::loadGraph(GraphManager& ref){
	// assignment operator is needed to make reference assignment available ? 
	//this->manager = ref;
}

/**
	It is weird that the starting letters are missing...
	And sth. must be wrong for the methods called here. 
*/
void GraphDisplay::showBasicInfo(ostream& out){
	out << "  " << "The number of Nodes: " + manager.numOfNode() <<endl;
	out << "The number of Edge: " + manager.numOfEdge() <<endl;
}

