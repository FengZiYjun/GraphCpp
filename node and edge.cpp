#include <vector>

class Node{
private:
	// index starts from 0
	int index;
	vector<Edge*> In;
	vector<Edge*> Out;
	
public:
	Node(int i){
		index = i;
	}
	void addIn(Edge* e){
		In.push_back(e);
	}
	void addOut(Edge* e){
		Out.push_back(e);
	}
	void removeOut(Edge* e){
		remove(Out.begin(),Out.end(),e);
	}
	void removeIn(Edge* e){
		remove(In.begin(),In.end(),e);
	}
};

class Edge{
private:
	Node* from;
	Node* to;
public:

};



class NodeManager{
	vector<Node*> pNode;
	vector<Edge*> pEdge;
	
public:
	NodeManager(){
	}
	
	int numOfNode(){
		return pNode.size();
	}

	// Node operations
	void addNode(){
		int nodeNum = this.numOfNode();
		Node* p = new Node(nodeNum+1);
		if(p!=NULL){
			pNode.push_back(p);
		}else{
			//throw nullptr error;
		}
	}
	
	bool deleteNode(int index){
		if(index+1 > pNode.size())
			return false;
		Node* p = pNode[index];
		delete p;
		pNode.erase(pNode.begin() + index);
		return true;
	}

	// Edge operations
	void addEdge(int i, int j){
		Edge* p = new Edge();
		Node* pi = pNode[i];
		Node* pj = pNode[j];
		if(p!=NULL){
			p->from = pi;
			p->to = pj;
			pi->addOut(p);
			pj->addIn(p);
			
		}else{
			// throw 
		}
	}
	
	bool deleteEdge(int i, int j){
		Node* from = pNode[i];
		Node* to = pNode[j];
		Edge* p = NULL;
		for(int i=0;i<pEdge.size();i++){
			if(pEdge[i]->from == from && pEdge[i]->to == to){
				p = pEdge[i];
				break;
			}
		}
		if(p!=NULL){
			p->from->removeOut(p);
			p->to->removeIn(p);
			delete p;
		}else{
			// throw
		}
		return true;
	}
}

