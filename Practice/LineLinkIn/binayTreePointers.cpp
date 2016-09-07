#include <iostream>
#include <queue>

class BinaryTree {
private:
    struct node {
            node *left;  
            node *right; 
            int element;   

            node() {

            }
            node( 
               int element,
               node *l = nullptr,
               node *r = nullptr)
             : left(l), right(r), element(element) {}
    };

    node* root;      
    int numElements;    

public:
    BinaryTree(): root(nullptr), numElements(0) {}

    void inserir(int element) {
        node *newNode = new node(element);
        node *father = nullptr;

        if(!root) {
            root = newNode;
            numElements++;
            return;
        }
        node* actual = root;

        while(actual) {
            father = actual;
            actual = newNode->element > actual->element ? actual->right : actual->left;
        }

        if(newNode->element < father->element) {
            father->left = newNode;
        }
        else {
            father->right = newNode;
        }
        numElements++;
    }

    void printTree() {
        std::queue<node*> currentlyLevel, nextLevel;
        currentlyLevel.push(root);
        while(!currentlyLevel.empty()) {
            node* noActual = currentlyLevel.front();
            currentlyLevel.pop();
            
            if(noActual) {
                std::cout << noActual->element << " ";
                nextLevel.push(noActual->left);
                nextLevel.push(noActual->right);
            }
            if(currentlyLevel.empty()) {
                std::cout << std::endl;
                swap(currentlyLevel, nextLevel);
            }
        }
    }

};

int main(int argc, char *argv[]) {

    BinaryTree tree;

    tree.inserir(50);
    tree.inserir(45);
    tree.inserir(40);
    tree.inserir(46);
    tree.inserir(30);
    tree.inserir(43);
    tree.inserir(20);
    tree.inserir(35);
    tree.inserir(42);
    tree.inserir(44);
    tree.inserir(70);
    tree.inserir(65);
    tree.inserir(60);
    tree.inserir(66);
    tree.inserir(75);
    tree.inserir(71);
    tree.inserir(78);

    tree.printTree();
    return 0;
}




