#include <iostream>

using namespace std;

class Pattern {
  private:
    int rows;
  public:
    Pattern(int rows) {
      this->rows = rows;
    }
    void print_pattern() {
        for (int i = rows; i > 0; i--)
        {     
            for (int j = rows - i; j > 0; j--)
            {
                cout << " ";
            }
            for (int j = 1; j < i * 2; j++)
            {
                cout << "*";
            }
            cout << endl;
        }
    }
};

int main() {
  Pattern pattern(5);
  pattern.print_pattern();
  return 0;
}
