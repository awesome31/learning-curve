#include <iostream>
using namespace std;

class MinStack {
public:
  vector<int> values;
  vector<int> mins;
  int topIndex;

  MinStack() { topIndex = -1; }

  void push(int val) {
    if (values.empty()) {
      mins.push_back(val);
      topIndex++;
    } else {
      int currentStackMin = mins[topIndex];
      topIndex++;

      if (val < currentStackMin) {
        mins[topIndex] = val;
      } else {
        mins[topIndex] = currentStackMin;
      }
    }

    values.push_back(val);
  }

  void pop() {
    values.pop_back();
    mins.pop_back();

    topIndex--;
  }

  int top() { return values[topIndex]; }

  int getMin() { return mins[topIndex]; }
};

int main() {
  MinStack a;

  a.push(-2);
  a.push(0);
  a.push(-3);

  cout << a.getMin() << endl;
  cout << a.top() << endl;

  a.pop();

  cout << a.getMin() << endl;
}
