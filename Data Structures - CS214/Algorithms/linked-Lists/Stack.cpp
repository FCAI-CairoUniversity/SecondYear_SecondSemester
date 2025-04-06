#include <iostream>
#include <string>
#include <stdexcept> // For std::out_of_range
#include <cctype>
using namespace std;

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };
    Node* top;  // Pointer to the top of the stack
    int size;   // Size of the stack

public:
    Stack() : top(nullptr), size(0) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    int getSize() const {
        return size;
    }

    void push(const T& value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        size++;
    }

    void pop() {
        if (isEmpty()) {
            throw out_of_range("Stack underflow! Cannot pop from an empty stack.");
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
    }

    T peek() const {
        if (isEmpty()) {
            throw out_of_range("Stack is empty! Cannot peek.");
        }
        return top->data;
    }
};

void bigIntegerAddition(const string& num1, const string& num2) {
  Stack<int> stack1, stack2, resultStack;
  int carry = 0;

  // Push digits of num1 onto stack1
  for (char digit : num1) {
      stack1.push(digit - '0');
  }

  // Push digits of num2 onto stack2
  for (char digit : num2) {
      stack2.push(digit - '0');
  }

  // Perform addition until both stacks are empty and no carry remains
  while (!stack1.isEmpty() || !stack2.isEmpty() || carry > 0) {
      int sum = carry;
      if (!stack1.isEmpty()) {
          sum += stack1.peek();
          stack1.pop();
      }
      if (!stack2.isEmpty()) {
          sum += stack2.peek();
          stack2.pop();
      }
      resultStack.push(sum % 10);  // Push the last digit of the sum onto the result stack
      carry = sum / 10;            // Update carry for the next iteration
  }

  // Print the result in reverse order
  cout << "Sum: ";
  while (!resultStack.isEmpty()) {
      cout << resultStack.peek();  // Print the top element of the result stack
      resultStack.pop();           // Remove it from the stack
  }
  cout << endl;
}



bool checkBrackets(const string& expression) {
  Stack<char> stack;
  unordered_map<char, char> bracketPairs = {
      {')', '('},
      {'}', '{'},
      {']', '['},
      {'>', '<'},
      {'"', '"'},
      {'\'', '\''},
      {'/', '*'} // For comments starting with /* and ending with */
  };

  bool inComment = false;
  for (size_t i = 0; i < expression.length(); ++i) {
      char currentChar = expression[i];

      if (inComment) {
          if (currentChar == '*' && i + 1 < expression.length() && expression[i + 1] == '/') {
              inComment = false; // Comment ends
              ++i; // Skip next character
          }
          continue; // Skip everything inside comments
      }

      // Check if it's an opening bracket
      if (currentChar == '(' || currentChar == '{' || currentChar == '[' || currentChar == '<' || currentChar == '"' || currentChar == '\'') {
          stack.push(currentChar);
      }
      // Check if it's a closing bracket
      else if (currentChar == ')' || currentChar == '}' || currentChar == ']' || currentChar == '>' || currentChar == '"' || currentChar == '\'') {
          if (stack.isEmpty() || stack.peek() != bracketPairs[currentChar]) {
              return false;  // Mismatched or unbalanced bracket
          }
          stack.pop();
      }
      // Check for the start of a comment block (/*)
      else if (currentChar == '/' && i + 1 < expression.length() && expression[i + 1] == '*') {
          inComment = true; // Enter comment block
          ++i; // Skip next character
      }
  }

  return stack.isEmpty(); // If stack is empty, brackets are balanced
}




int precedence(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

string infixToPostfix(const string& infix) {
    Stack<char> opStack;
    string postfix = "";

    for (char c : infix) {
        if (isspace(c)) continue;

        if (isdigit(c) || isalpha(c)) {
            postfix += c;
        }
        else if (isOperator(c)) {
            while (!opStack.isEmpty() && precedence(opStack.peek()) >= precedence(c)) {
                postfix += opStack.peek();
                opStack.pop();
            }
            opStack.push(c);
        }
    }

    while (!opStack.isEmpty()) {
        postfix += opStack.peek();
        opStack.pop();
    }

    return postfix;
}
