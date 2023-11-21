#ifndef WEEK8_QUEUE_H
#define WEEK8_QUEUE_H

template<class T>
class Queue {
private:
    struct Node {
        T element;
        Node* next;

        Node(T element, Node* next = nullptr){
            this->element = element;
            this->next - next;
        };
    };

    Node* front;
    Node* back;
    int numNodes;

public:
    Queue();
    ~Queue();
    void enqueue(T);
    void dequeue(T &num);
    bool isEmpty();
    void clear();
};

//************************************************
// Constructor                                   *
//************************************************
template<class T>
Queue<T>::Queue(){
    front = nullptr;
    back = nullptr;
    numNodes = 0;
}

//************************************************
// Destructor                                    *
//************************************************
template<class T>
Queue<T>::~Queue(){
    clear();
}

//************************************************
// Function enqueue inserts the value in num     *
// at the rear of the queue.                     *
//************************************************
template<class T>
void Queue<T>::enqueue(T num){
    Node *n = new Node(num);
    if(!numNodes)
        front = n;
    else
        back->next = n;
    back = n;
    ++numNodes;
}

//************************************************
// Function dequeue removes the value at the     *
// front of the queue, and copies it into num.   *
//************************************************
template<class T>
void Queue<T>::dequeue(T &num){
    Node *n = nullptr;
    if(!isEmpty()){
        n = front;
        delete(front);
        front = n->next;
        num = n->element;
        --numNodes;
    }
    else{
        std::cout << "queue empty, operation failed" << std::endl;
    }
}

//************************************************
// Function isEmpty returns true if the queue    *
// is empty, and false otherwise.                *
//************************************************
template<class T>
bool Queue<T>::isEmpty(){
    return !numNodes;
}

//************************************************
// Function clear dequeues all the elements      *
// in the queue.                                 *
//************************************************
template<class T>
void Queue<T>::clear(){
    T x;
    for(int i = 0; i < numNodes; i++){
        dequeue(x);
    }
}

#endif //WEEK8_QUEUE_H
