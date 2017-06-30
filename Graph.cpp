#include <iostream>
#include "Graph.h"
using namespace std;

Node::Node(int i){
	index = i;
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
	add or delete nodes and edges
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
	
	bool GraphManager::deleteNode(int index){
		if(index+1 > pNode.size())
			return false;
		Node* p = pNode[index];
		delete p;
		pNode.erase(pNode.begin() + index);
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


GraphDisplay::GraphDisplay(GraphManager& ref):manager(ref){

}
	
void GraphDisplay::loadGraph(const GraphManager& ref){
		this->manager = ref;
}

void GraphDisplay::showBasicInfo(){
	cout<<"The number of Nodes: " + manager.numOfNode()<<endl
		<<"The number of Edge: " + manager.numOfEdge()<<endl;
}

