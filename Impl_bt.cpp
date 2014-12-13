//Author: Wuzheng Ma
//Login name: WM813
//Date: 3/27/2014
//Email: wuzheng.ma13@imperial.ac.uk

#include<iostream>
using namespace std;

// Declare the data structure
struct CP {
	int id;			// id of the node
	int data;		// data of the node
	CP * left;		// pointer to the left subtree 
	CP * right;		// pointer to the right subtree
};

typedef CP * CPPtr;	

void constructStructure(CPPtr &hdTree);		

int getNodes(CPPtr);

int getEvenData(CPPtr);

CPPtr getMaxNode(CPPtr);

bool whetherOrdered(CPPtr, int, int);
#define MAXSIZE 0x7fffffff;		//Initialize a very big number to be "Infinity"
int PInfinity = MAXSIZE;		//Initialize "positive infinity"
int NInfinity = -MAXSIZE;		//Initialize "Negative infinity"

int getHeight(CPPtr);

int main(int argc, char ** argv)
{

	// Declare a pointer to the head of the tree
	CPPtr hdTree  = NULL;
	
	// Construct a tree structure. 
	constructStructure(hdTree);

	// =================================
	// Your functions should go here
	
    int n1 = getNodes(hdTree);	//Call function to get the number of nodes in the tree
	if(n1 != 0){
		cout<<"the number of nodes is "<<n1<<endl;
	}else{
		cout<<n1<<", empty tree"<<endl;
	}

	int n2 = getEvenData(hdTree);	//Call function to get the number of nodes wiwth even data
	if(n2 == 0){
		cout<<n2<<", empty tree"<<endl;		
	}else{
		cout<<"the number of even data is: "<<n2<<endl;
	}

    CPPtr max = getMaxNode(hdTree);		//Call function to obtain the node with maximum data
	if(max != NULL){
		cout<<"the node with maximum data is: "<<max->data<<" with ID of "<<max->id<<endl;
	}else{
		cout<<"Empty tree"<<endl;
	}

	bool flag = whetherOrdered(hdTree, NInfinity, PInfinity);		//Call function to check whether the tree is ordered
	if(flag == true){
		cout<<"The Binary tree is ordered"<<endl;
	}else{
		cout<<"The Binary tree is not ordered"<<endl;
	}
	
	int n3 = getHeight(hdTree);		//Call function to get the height of the root that passes as an argument in the function
	if(n3 != -1){
		cout<<"The height of the root is "<<n3<<endl;
	}else{
		cout<<n3<<", empty tree"<<endl;
	}
    // =================================
    
    // Just to freeze the console window (not always necessary)
    // getchar();
     
    return 0;
}



// The function generates an instance of the structure. The SP pointer
// points to the head of the tree
void constructStructure(CPPtr &SP){
    // Declare a structure with 5 nodes
    
    
    CPPtr SP0 = NULL;
    CPPtr SP1 = NULL;
    CPPtr SP2 = NULL;
    CPPtr SP3 = NULL;
    CPPtr SP4 = NULL;
	CPPtr SP5 = NULL;
    CPPtr SP6 = NULL;
	CPPtr SP7 = NULL;
	CPPtr SP8 = NULL;
	

    // build the structure tree
    // State 0
    
	SP0 = new CP;
    SP0->id = 1;
    SP0->data = 10;
    SP0->left = NULL;
    SP0->right = NULL;
    // State 1
    SP1 = new CP;
    SP1->id = 4;
    SP1->data = 5;
    SP1->left = NULL;
    SP1->right = NULL;
    // State 2
    SP2 = new CP;
    SP2->id = 8;
    SP2->data = 3;
    SP2->left = NULL;
    SP2->right = NULL;
    // State 3
    SP3 = new CP;
    SP3->id = 6;
    SP3->data =45;
    SP3->left = NULL;
    SP3->right = NULL;
    // State 4
    SP4 = new CP;
    SP4->id = 5;
    SP4->data = 10;
    SP4->left = NULL;
    SP4->right = NULL;
	// State 5
	SP5 = new CP;
    SP5->id = 2;
    SP5->data = 10;
    SP5->left = NULL;
    SP5->right = NULL;
	// State 6
	SP6 = new CP;
    SP6->id = 3;
    SP6->data = 20;
    SP6->left = NULL;
    SP6->right = NULL;
	// State 7
	SP7 = new CP;
    SP7->id = 9;
    SP7->data = 30;
    SP7->left = NULL;
    SP7->right = NULL;
	// State 8
	SP8 = new CP;
    SP8->id = 5;
    SP8->data = 15;
    SP8->left = NULL;
    SP8->right = NULL;
    
    //Make the connections
	
	SP0->left = SP1;
    SP0->right = SP4;
    
    SP1->left = SP2;
    SP1->right = SP3;
	
	SP3->left = SP5;
	SP3->right = SP6;
	
	SP5->left = SP8;
	SP5->right = SP7;
	
    
    // Make the head pointer to point to the head of the tree
    SP = SP0;
}

//Function will count the number of nodes
//When the pointer reaches the end node(the one which connect with nothing), the
//return value is 1
int getNodes(CPPtr hdtree){
	if(hdtree==NULL){		//Empty tree
		return 0;
	}else if((hdtree->left == NULL) && (hdtree->right == NULL)){
			return 1;
	}else{
		getNodes(hdtree->left);
		getNodes(hdtree->right);
	}
	return 1+getNodes(hdtree->left)+getNodes(hdtree->right); 
}


//Function will count the number of even data 
int getEvenData(CPPtr hdtree){
		if(hdtree==NULL){	//Empty tree
			return 0;
		}else if((hdtree->left == NULL) && (hdtree->right == NULL)){
			if((hdtree->data)%2 == 0) return 1;
			else return 0;
		}else{
			getEvenData(hdtree->left);
			getEvenData(hdtree->right);
		}
		if((hdtree->data)%2 ==0) return 1+getEvenData(hdtree->left)+getEvenData(hdtree->right);
		else return getEvenData(hdtree->left)+getEvenData(hdtree->right);
}

//Function will pick up the node with maximum data
CPPtr getMaxNode(CPPtr hdtree){
	if(hdtree==NULL){		//Empty tree
		return hdtree;
	}else if((hdtree->left == NULL) && (hdtree->right == NULL)){
		return hdtree;
	}else if(hdtree->right == NULL || hdtree->left == NULL){	//either left subtree or right subtree is empty
		return hdtree;
	}else{
		getMaxNode(hdtree->left);
		getMaxNode(hdtree->right);
	}
	//When the data from left subtree is greater than the data from right subtree, return the pointer points to left subtree
	//Otherwise, return the pointer points to right subtree
	//Special case is when the tree is not ordered, the data from left and right subtrees have to compare with the data 
	//where the current pointer points to(hdtree->data) before returning. 
	if((getMaxNode(hdtree->left)->data > getMaxNode(hdtree->right)->data) && (getMaxNode(hdtree->left)->data > hdtree->data)){
		return getMaxNode(hdtree->left);
	}else if(getMaxNode(hdtree->right)->data > hdtree->data){
		return getMaxNode(hdtree->right);
	}else{
		return hdtree;
	}
}

//Function will check whether the tree is ordered
bool whetherOrdered(CPPtr hdtree, int lowerbound, int upperbound){
	if(hdtree==NULL){		//Empty tree
		return false;
	}else if(hdtree->left == NULL && hdtree->right == NULL){
		if(hdtree->data >= lowerbound && hdtree->data <= upperbound){
			return true;
		}else{
			return false;
		}
	}else if(hdtree->left == NULL || hdtree->right == NULL){		//Special cases which either the left or right subtree is empty
		if(hdtree->data >= lowerbound && hdtree->data <= upperbound){
			return true;
		}else{
			return false;
		}
	}else{
		whetherOrdered(hdtree->left, lowerbound, hdtree->data);
		whetherOrdered(hdtree->right, hdtree->data, upperbound);
	}

	return ((whetherOrdered(hdtree->left, lowerbound, hdtree->data)) && (whetherOrdered(hdtree->right, hdtree->data, upperbound)));
}



//Function will return the height of the specific root
int getHeight(CPPtr rootPtr){
	if(rootPtr==NULL){		//Empty tree
		return -1;
	}else if(rootPtr->left == NULL && rootPtr->right == NULL){
		return 0;
	}else if(rootPtr->left != NULL && rootPtr->right != NULL){		//Normal cases
		return 1+max(getHeight(rootPtr->left), getHeight(rootPtr->right));
	}else if(rootPtr->left == NULL && rootPtr->right != NULL){		//Special cases which the left subtree is empty
		return 1+getHeight(rootPtr->right);
	}else if(rootPtr->left != NULL && rootPtr->right == NULL){	    //Special cases which the right subtree is empty
		return 1+getHeight(rootPtr->left);
	}
	return 0;
}
	






	
