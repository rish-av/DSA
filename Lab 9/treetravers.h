#include"tree.h"
typedef struct currentset* CurrentSet;
struct currentset{
	Node set;
	CurrentSet next;
};
void visit(Node n);
Node selectNextNode(CurrentSet cr);
Iterator_list identifyNodes(CurrentSet cr);
CurrentSet addmorenodes(CurrentSet cr,Iterator_list it);
void bft(Node tree);

