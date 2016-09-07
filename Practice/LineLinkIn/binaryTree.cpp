#include <iostream>
#include <vector>
#include <string>

void printTree( const std::vector<std::string>  & tree)
{	
	int depthTree = 1;
	bool depthDone = true;
	int elementInDepth = 1, auxStop = 0;

	for (unsigned int nodePosition = 0; nodePosition < tree.size(); nodePosition++)
	{	

		if (nodePosition ==0)
		{
			std::cout<<"\nNode at depth 0: " << tree[nodePosition] << std::endl <<std::endl;
		}

		if(elementInDepth == auxStop){

			depthDone = true;
			auxStop = 0;
			depthTree++;
			elementInDepth = (depthTree - 1) * 2;
			std::cout<<std::endl <<std::endl;
		}

		if(depthDone and (nodePosition * 2 + 1 < tree.size() or nodePosition * 2 + 2 < tree.size())  ) {
			std::cout<<"Nodes at depth " << depthTree << ": ";
			depthDone = false;
		}
			
		if(nodePosition * 2 + 1 < tree.size() or nodePosition * 2 + 2 < tree.size()  ){
			std::cout<< tree[nodePosition * 2 + 1]<<" ";
			std::cout<< tree[nodePosition * 2 + 2]<<" ";
			auxStop++;

	    }
	    else{

	    	break;
	    }
	}

	std::cout<<std::endl <<std::endl;  
}

// example of how the program would work
int main()
{
	std::vector<std::string> tree;

	tree.push_back("A");
	tree.push_back("B");
	tree.push_back("C");
	tree.push_back("F");
	tree.push_back("G");
	tree.push_back("E");
	tree.push_back("D");
	tree.push_back("I");
	tree.push_back("J");
	tree.push_back("M");
	tree.push_back("O");
	tree.push_back("L");
	tree.push_back("N");
	tree.push_back("K");
	tree.push_back("H");

	printTree(tree);
	
	return 0;
}

