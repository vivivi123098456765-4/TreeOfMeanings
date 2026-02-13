#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node {
private:

	string content;
	vector<Node*> children;

public:

	Node(string text) : content(text) {}

	void addChild(Node* childNode) {

		children.push_back(childNode);

	}

	void printTree(int level = 0) {

		for (int i = 0; i < level; i++) {
			cout << "  ";
		}

		cout << "|-- " << content << endl;


		for (Node* child : children) {
			child->printTree(level + 1);
		}
	}

};

int main() {

	Node* root = new Node("ROOT");

	Node* subBrunch1 = new Node("architecture");
	Node* subBrunch2 = new Node("design");

	root->addChild(subBrunch1);
	root->addChild(subBrunch2);

	Node* subBrunch3 = new Node("clean architecture book");
	Node* subBrunch4 = new Node("Figma Mockups");


	subBrunch1->addChild(subBrunch3);
	subBrunch2->addChild(subBrunch4);

	cout << "Tree structure:" << endl;
	root->printTree(0);

	return 0;
}