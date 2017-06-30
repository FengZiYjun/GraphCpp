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
	GD.showBasicInfo();
	
	cout<<"num of nodes: " << GM.numOfNode() << endl;
	
	GM.deleteNode(0);
	GM.deleteNode(1);
	
	return 0;
}