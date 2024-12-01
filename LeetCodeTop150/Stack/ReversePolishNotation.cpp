#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int evalRPN(vector<string> &tokens)
{
  stack<int> st;
  int num;

  for (int i = 0; i < tokens.size(); i++)
  {
    if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/" || tokens[i] == "*")
    {
      int num1 = st.top();
      st.pop();
      int num2 = st.top();
      st.pop();
      if (tokens[i] == "+")
      {
        num = num1 + num2;
        st.push(num);
      }
      else if (tokens[i] == "-")
      {
        num = num2 - num1;
        st.push(num);
      }
      else if (tokens[i] == "*")
      {
        num = num1 * num2;
        st.push(num);
      }
      else
      {
        num = num2 / num1;
        st.push(num);
      }
    }
    else
    {
      if (!tokens[i].empty())
      {
        st.push(stoi(tokens[i]));
      }
    }
  }

  return st.top();
}