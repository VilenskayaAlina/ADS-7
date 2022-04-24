// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
  struct ITEM {
    T data;
    ITEM * next;
  };
 private:
  TPQueue::ITEM* create(const T&);
  ITEM *head; ITEM *tail;

 public:
  TPQueue():head(nullptr),tail(nullptr){}
  ~TPQueue();
  void push(const T&);
  T pop();
  void print() const;
  
  bool isEmpty() {
    return head.isEmpty();
  }
  void push(const T&value) {
    head.addHead(value);
  }
  T pop() {
    if (!isEmpty) return head.rmHead;
    else trow "Empty!";
  }
  T get() {
    if (!isEmpty) return head.getHead;
    else throw "Empty!";
};

template<typename T>
  typename TPQueue<T>::ITEM* TPQueue<T>::create(const T& data) {
    ITEM *item=new ITEM;
    item−>data=data;
    item−>next=nullptr;
    return item;
  }

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
