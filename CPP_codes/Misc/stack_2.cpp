#include <iostream>
using namespace std;

class Stack{
    protected:
        int *arr, size, top;
    public:
        Stack(){
            arr = NULL;
            size = 0;
            top = -1;
        }
        Stack(int size){
            this->size = size;
            arr = new int[size];
            top = -1;
        }
        bool isEmpty(){
            if (top == -1){
                return true;
            }else{
                return false; 
            }
        }
        bool isFull(){
            if(top == size - 1){
                return true;
            }else{
                return false;
            }
        }

        void push(int ele){
            if (isFull()){
                cout << "Stack overflow!! " <<endl;
            }else{
                arr[++top] = ele;
            }
        }

        int pop(){
            if (isEmpty()){
                cout << "Stack underflow !!" << endl;
                exit(1);
            }else{
                return arr[top--];
            }
        }

        void peek(){
            if (isEmpty()){
                cout << "stack is empty" <<endl;
            }else{
                cout << "Curr element: " << arr[top] << endl;
            }
        }

        void display(){
            if (top == -1){
                cout << "Empty stack" << endl;
                return;
            }
            cout << "Stack contents :---" << endl;
            for (int i = 0; i <= top; i++){
                cout << arr[i] << "\t";
            }
            cout << endl;
        }

        void display(int position){
            if (position > top || position < -1){
                cout << "Invalid position " << endl;
            }else{
                cout <<"Value at the specified position: "<< arr[top - position] << endl;
            }
        }

};
//special stack class
class MinStack: public Stack{
    public:
        MinStack(){
            arr = NULL;
            size = 0;
            top = -1;
        }
        MinStack(int size){
            this->size = size;
            arr = new int[size];
            top = -1;
        }
        void minimum_push(int value){
            if (isFull()){
                cout << "Stack overflow!! " <<endl;
            }else{
                if (isEmpty()){
                    arr[++top] = value;
                    return;
                }else{
                    if (arr[top] <= value){
                        cout << "Element is larger than or equal to stack top" << endl;
                        return;
                    }
                    arr[++top] = value;
                }
            }
        }

        void display(){
            if (top == -1){
                cout << "Empty stack" << endl;
                return;
            }
            cout << "Stack contents :---" << endl;
            for (int i = top; i > -1; i--){
                cout << arr[i] << "\t";
            }
            cout << endl;
        }
        

};

void towerOfHanoi(int n, MinStack &From, MinStack &To, MinStack &Aux, char from, char to, char aux){
    if (n == 0) {
        return;
    }
    towerOfHanoi(n - 1, From, Aux, To, from, aux, to);
    int tmp = From.pop();
    To.minimum_push(tmp);
    cout << "Move " << tmp << " from stack " << from << " to stack " << to << endl;
    towerOfHanoi(n - 1, Aux, To, From, aux, from, to);            
}

int main(){
    int size, ch = 1, ele, depth;
    cout << "Enter the size of the stacks" <<endl;
    cin >> size;
    MinStack A(size), B(size), C(size);
    while (1){
        cout << "Enter 1 to push or any key to quit: " << endl;
        cin >> ch;
        if (ch != 1){
            break;
        }
        cout << "enter element to push on the source stack(A)" << endl;
        cin >> ele;
        A.push(ele);
    }
    A.display();
    towerOfHanoi(size, A, C, B, 'A', 'C', 'B');
    cout << "Destination stack(C) --" << endl;
    C.display();
    cout << "Source stack(A) --" << endl;
    A.display();

    return 0;
}

