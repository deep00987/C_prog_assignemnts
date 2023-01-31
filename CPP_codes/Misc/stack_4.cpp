#include <iostream>
using namespace std;

class Height {
    private:
        int feet, inch;
    public:
        Height() {
            feet = 0;
            inch = 0;
        }
        Height(int f, int i) {
            feet = f;
            inch = i;
        }
        void set(int f, int i) {
            feet = f;
            inch = i;
        }
        bool operator <= (Height h) {
            int h1 = (feet * 12) + inch;
            int h2 = (h.feet * 12) + h.inch;
            if (h1 <= h2){
                return true;
            }else{
                return false;
            }
        }
        friend ostream & operator << (ostream & os, Height h){
            os << h.feet << "feet " << h.inch << "inch";
            return os;
        }
};


template <class T>
class Stack{
    protected:
        T *arr; 
        int size, top;
    public:
        Stack(){
            arr = NULL;
            size = 0;
            top = -1;
        }
        Stack(int size){
            this->size = size;
            arr = new T[size];
            top = -1;
        }
        void push(T ele);
        T pop();
        void peek();
        void display();
        void display(int position);
        void stack_average();
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
    
};

template <class T>
void Stack<T> :: push(T ele)
{
        if (isFull())
        {
            cout << "Stack overflow!! " << endl;
        }
        else
        {
            arr[++top] = ele;
        }
}
template <class T>
T Stack<T> :: pop()
{
        if (isEmpty())
        {
            cout << "Stack underflow !!" << endl;
            exit(1);
        }
        else
        {
            return arr[top--];
        }
}
template <class T>
void Stack<T> :: peek()
{
        if (isEmpty())
        {
            cout << "stack is empty" << endl;
        }
        else
        {
            cout << "Curr element: " << arr[top] << endl;
        }
}
template <class T>
void Stack<T> :: stack_average(){
    try{
        if (isEmpty()){
            throw 0;
        }
        int sum = 0;
        int elements = 0;
        float avg = 0;
        for (int i = 0; i <= top; i++){
            sum += arr[i];
            elements += 1;
        }
        if (elements == 0){
            throw 0;
        }
        avg = (float)sum/elements;
        cout << "Stack average: " << avg << endl;
    }catch(int err){
        cout << "Exception: Illegal operation, stack is empty" << endl;
    }
}

template <class T>
void Stack<T> :: display()
{
        if (top == -1)
        {
            cout << "Empty stack" << endl;
            return;
        }
        cout << "Stack contents :---" << endl;
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << "\t";
        }
        cout << endl;
}
template <class T>
void Stack<T> :: display(int position)
{
        if (position > top || position < -1)
        {
            cout << "Invalid position " << endl;
        }
        else
        {
            cout << "Value at the specified position: " << arr[top - position] << endl;
        }
}

//special stack class
template <class T>
class MinStack: public Stack<T>{
    public:
        MinStack(){
            this->arr = NULL;
            this->size = 0;
            this->top = -1;
        }
        MinStack(int size){
            this->size = size;
            this->arr = new T[size];
            this->top = -1;
        }
        void minimum_push(T value);
        void display();
};

template <class T>
void MinStack<T> :: minimum_push(T value)
{
    if (this->isFull()){
        cout << "Stack overflow!! " << endl;
    }else{
        if (this->isEmpty()){
            this->arr[++(this->top)] = value;
            return;
        }else{
            if (this->arr[this->top] <= value){
                cout << "Element is larger than or equal to stack top" << endl;
                return;
            }
                this->arr[++(this->top)] = value;
            }
        }
}
template <class T>
void MinStack<T> :: display(){
    if (this->top == -1){
        cout << "Empty stack" << endl;
        return;
    }
    cout << "Stack contents :---" << endl;
    for (int i = this->top; i > -1; i--){
        cout << this->arr[i] << "\t";
    }
    cout << endl;
}

void towerOfHanoi(int n, MinStack<int> &From, MinStack<int> &To, MinStack<int> &Aux, char from, char to, char aux){
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
    int size, ch = 1, depth;
    cout << "Enter the size of the stacks" <<endl;
    cin >> size;
    
    int ele;

    MinStack <int> A(size), B(size), C(size);
    while (1){
        cout << "Enter 1 to push or any key to quit: " << endl;
        cin >> ch;
        if (ch != 1){
            break;
        }
        cout << "enter element to push: " << endl;
        cin >> ele;
        A.minimum_push(ele);
    }
    A.display();
    towerOfHanoi(size, A, C, B, 'A', 'C', 'B');
    cout << "Destination stack(C) --" << endl;
    C.display();
    cout << "Source stack(A) --" << endl;
    A.display();
    C.stack_average();
    A.stack_average();
    return 0;
}

