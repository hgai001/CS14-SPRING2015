#ifndef lab3_h
#define lab3_h
#include <iostream>
using namespace std;


template <typename T>
class TwoStackFixed {
  private:
    int top1;
    int top2;
    int maxtop;
    int size;
    T *arr;
  public:
    TwoStackFixed(int size, int maxtop ) {
        if (size < maxtop) {
            cout << "ERROR!" << endl;
            return;
        }
        arr = new T[size];
        this->maxtop = maxtop - 1;
        this->size = size;
        top1 = -1;
        top2 = size;
    }
    void pushStack1(T value) {
        if (top1 == maxtop) {
            cout <<"Stack 1 is full!" << endl;
        }
        else {
            ++top1;
            arr[top1] = value;
        }
        return;
    } 
    void pushStack2(T value) {
        if (top2 == (maxtop + 1)) {
            cout <<"Stack 2 is full!" << endl;
        }
        else {
            --top2;
            arr[top2] = value;
        }
        return;
    }
    T popStack1() {
        T tmp;
        if (top1 == -1) {
            cout << "Stack 1 is already empty!" << endl;
        }
        else {
            tmp = arr[top1];
            arr[top1] = 0;
            --top1;
        }
        return tmp;
    }
    T popStack2() {
        T tmp;
        if (top2 == size) {
            cout << "Stack 2 is already empty!" << endl;
        }
        else {
            tmp = arr[top2];
            arr[top2] = 0;
            ++top2;
        }
        return tmp;
    }
    bool isFullStack1() {
        if (top1 == maxtop) {
            return true;
        }
        else return false;
    }
    bool isFullStack2() {
        if (top2 == (maxtop + 1)) {
            return true;
        }
        else return false;
    }
    bool isEmptyStack1() {
        if (top1 == -1) {
            return true;
        }
        else return false;
    }
    bool isEmptyStack2() {
        if (top2 == size) {
            return true;
        }
        else return false;
    }
};


template <typename T>
class TwoStackOptimal {
  private:
    int top1;
    int top2;
    int size;
    T *arr;
  public:
    TwoStackOptimal(int size) {
        arr = new T[size];
        this->size = size;
        top1 = -1;
        top2 = size;
    }
    void pushFlexStack1(T value) {
        if (top1 == (top2 - 1)) {
            cout <<"Stack 1 is full!" << endl;
        }
        else {
            ++top1;
            arr[top1] = value;
        }
        return;
    }
    void pushFlexStack2(T value) {
        if (top2 == (top1 + 1)) {
            cout << "Stack 2 is full!" << endl;
        }
        else {
            --top2;
            arr[top2] = value;
        }
    }
    T popFlexStack1() {
        T tmp;
        if (top1 == -1) {
            cout << "Stack 1 is already empty!" << endl;
        }
        else {
            tmp = arr[top1];
            arr[top1] = 0;
            --top1;
        }
        return tmp;
    }
    T popFlexStack2() {
        T tmp;
        if (top2 == size) {
            cout << "Stack 2 is already empty!" << endl;
        }
        else {
            tmp = arr[top2];
            arr[top2] = 0;
            ++top2;
        }
        return tmp;
    }
    bool isFullStack1() {
        if (top1 == (top2 - 1)) return true;
        else return false;
    }
    bool isFullStack2() {
        if (top2 == (top1 + 1)) return true;
        else return false;
    }
    bool isEmptyStack1() {
        if (top1 == -1) return true;
        else return false;
    }
    bool isEmptyStack2() {
        if (top2 == size) return true;
        else return false;
    }
};

#endif
