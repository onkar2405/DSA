#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class MinStack
{
private:
  vector<pair<int, int>> st;

public:
  MinStack()
  {
  }

  void push(int val)
  {
    if (this->st.empty())
    {
      this->st.push_back({val, val});
    }
    else
    {
      this->st.push_back({val, min(val, this->st[st.size() - 1].second)});
    }
  }

  void pop()
  {
    this->st.pop_back();
  }

  int top()
  {
    return this->st[st.size() - 1].first;
  }

  int getMin()
  {
    return this->st[st.size() - 1].second;
  }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */