#include <iostream>
#include <raylib.h>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

// --- Node Class: Represents a single branch/leaf in the tree structure ---
class Node {
private:
    string content;
    vector<Node*> children;

public:
    // --- Getters and Constructor: Basic data access and initialization ---
    vector<Node*> getChildren() { return children; }
    string getContent() { return content; }
    Node(string text) : content(text) {}

    // --- Search Logic: Recursively finds a node by its string content ---
    Node* findNode(string target) {
        if (content == target) return this;
        for (Node* child : children) {
            Node* result = child->findNode(target);
            if (result != nullptr) return result;
        }
        return nullptr;
    }

    // --- Structure Management: Adds a new child to the current node ---
    void addChild(Node* childNode) {
        children.push_back(childNode);
    }

    // --- Console Visualization: Recursively prints the tree hierarchy to terminal ---
    void printTree(int level = 0) {
        for (int i = 0; i < level; i++) cout << "  ";
        cout << "|-- " << content << endl;
        for (Node* child : children) {
            child->printTree(level + 1);
        }
    }

    static void DrawMorphTree(Node* node, float x, float y, float angle, float length) {
        // 1. Base case: if the pointer is null, stop recursion
        if (node == nullptr) return;

        // 2. Calculate the end point of the current branch using trigonometry
        // We use cosf for X and sinf for Y. 
        // DEG2RAD is a Raylib macro (PI / 180) to convert degrees to radians.
        float x_end = x + cosf(angle * DEG2RAD) * length;
        float y_end = y + sinf(angle * DEG2RAD) * length;

        // 3. Draw the current branch (line from start to end)
        // DrawLineEx allows setting thickness (e.g., 2.0f)
        DrawLineEx({ x, y }, { x_end, y_end }, 2.0f, DARKGRAY);

        // 4. Draw Text
        DrawText(node->getContent().c_str(), (int)x_end + 5, (int)y_end, 10, MAROON);

        // 5. Recursive step: process children
        int count = 0;
        for (Node* child : node->getChildren()) {
            float nextAngle;

            // Logic for branching angles
            if (count == 0) {
                // First child tilts to the left
                nextAngle = angle - 30.0f;
            }
            else {
                // Subsequent children tilt to the right
                nextAngle = angle + 30.0f;
            }

            // Reduce length for the next level (fractal effect)
            float nextLength = length * 0.7f;

            // Recursive call: the end of the current branch becomes the start for the child
            Node::DrawMorphTree(child, x_end, y_end, nextAngle, nextLength);

            // Increment counter to differentiate between children
            count++;
        }
    }
};

int main() {

    // --- LEVEL 0: Root ---
    Node* root = new Node("ROOT");

    // --- LEVEL 1: Main Categories ---
    Node* arch = new Node("architecture");
    Node* design = new Node("design");
    Node* systems = new Node("systems");

    root->addChild(arch);
    root->addChild(design);
    root->addChild(systems);

    // --- LEVEL 2: Sub-branches for Architecture ---
    Node* layout = new Node("layout");
    Node* logic = new Node("logic");
    arch->addChild(layout);
    arch->addChild(logic);

    // --- LEVEL 2: Sub-branches for Design ---
    Node* colors = new Node("colors");
    Node* fonts = new Node("fonts");
    design->addChild(colors);
    design->addChild(fonts);

    // --- LEVEL 3: Deep details for Layout ---
    layout->addChild(new Node("grid_2d"));
    layout->addChild(new Node("space_3d"));

    // --- LEVEL 3: Deep details for Colors ---
    colors->addChild(new Node("palettes"));
    colors->addChild(new Node("contrast"));

    // --- LEVEL 3: Deep details for Systems ---
    systems->addChild(new Node("kernel"));
    systems->addChild(new Node("drivers"));



    // --- Debug Output: Print the built structure to the console ---
    cout << "Tree structure built successfully!" << endl;
    root->printTree(0);

    // --- Window Initialization: Setting up Raylib screen and frame rate ---
    InitWindow(800, 600, "Morph Engine - Lab 6");
    SetTargetFPS(60);

    // --- Main Application Loop: Handling frame rendering ---
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Render the tree starting from bottom-center, pointing upwards
        Node::DrawMorphTree(root, GetScreenWidth() / 2.0f, GetScreenHeight() - 20.0f, -90.0f, 150.0f);

        EndDrawing();
    }

    // --- Cleanup: Close window and exit program ---
    CloseWindow();
    return 0;
}