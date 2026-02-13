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

};

int main_old() {

	Node* root = new Node("ROOT");

	Node* subBrunch1 = new Node("wtf");
	Node* subBrunch2 = new Node("FAAA");

	root->addChild(subBrunch1);
	root->addChild(subBrunch2);

}