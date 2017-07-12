#include <iostream>
#include "Graph.h"
using namespace std;

/*
	unit test
*/
int main(){

	GraphManager GM;
	GM.addNode();
	GM.addNode();
	GM.addEdge(0,1);
	
	GraphDisplay GD(GM);
	//GD.loadGraph(GM);
	GD.showBasicInfo(cout);
	
	GraphManager& ref = GM;
	cout<<"num of nodes: " << ref.numOfNode() << endl;
	
	// sth. wrong with the destructor
	
	if(GM.deleteNode(0)){
		cout<<"deleted!"<<endl;
	}
	if(GM.deleteNode(1)){
		cout<<"deleted!"<<endl;
	}
	
	return 0;
}

