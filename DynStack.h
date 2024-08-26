// Name - Dominic McElroy
// Class - CSC 1310 Lab 5 
// Date - 10.16.2023

using namespace std;

template <typename T>
class Node {
    public:
        T data;
        Node* next;
        Node (T data) {
            this->data = data;
        }
};

template <typename T>
class DynamicStack {
    private:

        Node<T>* TopOfStack;

        public:

            DynamicStack () {
                TopOfStack = NULL;
            }

            bool isEmpty() {
                if(TopOfStack == NULL){
                return true;
                         }
                return false; 
            }

            void push (T item) {
                if(isEmpty ()) {
                    TopOfStack = new Node<T> (item);
                }
                else {
                    Node<T>* newNode = new Node<T> (item);

                    newNode->next = TopOfStack;
                    TopOfStack = newNode;
                }
            }

            void pop (T &item) {
                item = TopOfStack->data;
                Node<T> * toDelete = TopOfStack;
                TopOfStack = TopOfStack->next;
                delete toDelete;
            }
};