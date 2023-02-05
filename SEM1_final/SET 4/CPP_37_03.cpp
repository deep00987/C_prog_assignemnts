#include <iostream>
using namespace std;

class Number_List {
  private:
    int size;
    int *numbers;

  public:
    // Constructor to create the array
    Number_List(int size) {
      this->size = size;
      numbers = new int[size];
    }

    // Member function to sort the array
    void sort_list() {
        int temp = 0; 
        bool swapped;
        for (int i = 0; i < size - 1; i++)
        {
            swapped = false;
            for (int j = 0; j < size - i - 1; j++)
            {
                if (numbers[j] > numbers[j + 1])
                {
                    temp = numbers[j];
                    numbers[j] = numbers[j + 1];
                    numbers[j + 1] = temp;
                    swapped = true;
                }
            }
 
            if (swapped == false)
                break;
        }
    }

    // Member function to find the minimum value in the array
    int min_value() {
      return numbers[0];
    }

    // Member function to find the maximum value in the array
    int max_value() {
      return numbers[size - 1];
    }

    // Member function to input values into the array
    void input_values() {
      for (int i = 0; i < size; i++) {
        cout << "Enter number " << i + 1 << ": ";
        cin >> numbers[i];
      }
    }

    void display(){
        cout << "Element in the arr --" << endl;
        for (int i = 0; i < size; i++){
            cout << " " << numbers[i];
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    // Create an instance of the Number_List class
    Number_List list(size);

    // Input values into the array
    list.input_values();

    //display
    list.display();

    // Sort the array
    list.sort_list();

    //display
    list.display();

    // Find the minimum and maximum values in the array
    cout << "Minimum value: " << list.min_value() << endl;
    cout << "Maximum value: " << list.max_value() << endl;

    return 0;
}
