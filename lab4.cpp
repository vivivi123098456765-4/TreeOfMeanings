#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node {
private:

	string content;
	vector<Node*> children;

public:

	string getContent() { return content; }

	Node(string text) : content(text) {}

	Node* findNode(string target) {

		if (content == target) {
			return this;
		}

		for (Node* child : children) {

			Node* result = child->findNode(target);
			if (result != nullptr) { return result; }

		}

		return nullptr;
	}

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

	cout << "-------------------------------" << endl << endl;

	cout << "Testing search..." << endl;

	string target = "architecture";
	Node* found = root->findNode(target);

	if (found != nullptr) {
		cout << "Success! Found node with content: " << found->getContent() << endl;
	}
	else {
		cout << "Sorry, node '" << target << "' not found." << endl;
	}


	while (true) {

		string command;
		cout << "Enter the command" << endl;
		cin >> command;

		if (command == "add") {

			string parent;
			cout << "Enter the name of parent" << endl;
			cin >> parent;
			
			Node* find = root->findNode(parent);

			if (find != nullptr) {

				string child;
				cout << "Enter name of child" << endl;
				cin >> child;
				find->addChild(new Node(child));

			}
			else {

				cout << "Parent not found";

			}

		}
		else if (command == "print") {

			root->printTree(0);

		}
	}
	return 0;
}