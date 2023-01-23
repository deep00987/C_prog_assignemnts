#include <iostream>
using namespace std;

class Stack{
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

int main(){
    int size, ch, ele, depth;
    cout << "Enter the size of the stack" <<endl;
    cin >> size;
    Stack st(size);

    while (1){
        cout << "Enter 1 to push" <<endl;
        cout << "Enter 2 to pop" <<endl;
        cout << "Enter 3 to peek" <<endl;
        cout << "Enter 4 to display whole stack" <<endl;
        cout << "Enter 5 to display value at depth" <<endl;
        cin >> ch;
        switch (ch)
        {
            case 1:
                cout << "enter elemenet to push: " << endl;
                cin >> ele;
                st.push(ele);
                break;
            case 2:
                ele = st.pop();
                cout << "Popped element is: " << ele << endl;
                break;
            case 3:
                st.peek();
                break;
            case 4:
                st.display();
                break;
            case 5:
                cout << "Enter depth: " << endl;
                cin >> depth;
                st.display(depth);
                break;
            default:
                cout << "exiting ...." << endl;
                exit(1);
                break;
        }
    }



    return 0;
}