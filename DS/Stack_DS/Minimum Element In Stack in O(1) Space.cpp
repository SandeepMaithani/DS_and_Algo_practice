/*

Complexity Analysis :

Time Complexity: O(1). All operation take constant time so time complexity will be O(1).

Space Complexity: O(1).

*/



/*

The structure of the class is as follows :

class _stack {
  stack<int> s;
  int minEle;

  public :

  int getMin();
  int pop();
  void push(int);

};

*/


int _stack :: getMin()
{
  if (s.empty()) {
    return -1;
  }

  return minEle;
}



int _stack ::pop()
{
  int top = -1;

  if (s.empty()) {
    return top;
  }

  if (s.top() >= minEle) {
    top = s.top();
    s.pop();
  }
  else {
    top = minEle;
    minEle = 2 * minEle - s.top();
    s.pop();
  }
  return top;
}


void _stack::push(int x)
{
  if (s.empty()) {
    s.push(x);
    minEle = x;
    return;
  }

  if (x >= minEle) {
    s.push(x);
  }
  else {
    int tempVal = 2 * x - minEle;
    s.push(tempVal);
    minEle = x;
  }

}