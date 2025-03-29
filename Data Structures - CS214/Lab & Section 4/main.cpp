/*
 * Author(s): Mohammed Atef & George Malak.
 * Date: March 25, 2025.
 * Lab & Section: 4.
 * Course: Data Structure - CS214.
*/

#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Stack {
private:
   T* arr ;
   int size ;
public:
    Stack(){
        this->size = 0;
        this->arr = new T (this->size) ;
    };
    
    bool isEmpty (){
        return (this->size == 0) ;
    }
    
    T top() {
        return arr[size - 1];
    };
    
    void pop(){
        T* newArr = new T(this->size -1);
        for (int i = 0; i < this->size -1; ++i) {
            newArr[i] = this->arr[i];
        }
        
        delete[] this->arr;
        this->arr = newArr;
        this->size--;
    };
    
    void push(T element){
        T* newArr = new T(this->size + 1);
        for (int i = 0; i < this->size ; ++i) {
            newArr[i] = this->arr[i];
        }
        
        newArr[this->size] = element;
        delete[] this->arr;
        this->arr = newArr;
        this->size++;
    };
};

int main() {
    string s ; cin >> s ;
    auto st = Stack<char> ();
    
    for (char i : s) {
        if(i == '(' || i == '[' || i == '{'){
            st.push(i);
        }
        
        else if (i == ')' || i == ']' || i == '}'){
            char top = st.top();
            if ((top == '(' && i == ')') || (top == '{' && i == '}') || (top == '[' && i == ']')) {
                if(st.isEmpty()){
                    cout << "The string is unbalanced !!" ;
                    return 0;
                }
                st.pop();
            }
        }
    }
    
    if(st.isEmpty()) cout << "The string is balanced !!";
    else cout << "The string is unbalanced !!";
    return 0;
}