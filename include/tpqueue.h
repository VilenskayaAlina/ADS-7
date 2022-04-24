// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
  struct ITEM {
    T data;
    ITEM * next;
  };
 private:
  ITEM *head;
  ITEM *tail;

 public:
  TPQueue():head(nullptr),tail(nullptr){}
  ~TPQueue();
  void push(const T&);
  T pop();

  bool isEmpty() {
    return head.isEmpty();
  }
  void push(const T&value) {
    ITEM* first = head;
    if (first == nullptr) {
      first = new ITEM;
      head = first;
      first->value = data;
      first->next = nullptr;
    } else {
        ITEM* temp = new ITEM;
        temp->value = data;
        if (head->value.prior < temp->value.prior) {
          temp->next = first;
          head = temp;
          return;
        }
        while (first != nullptr) {
          prov1 = first->value.prior;
          prov2 = temp->value.prior;
          prov3 = first->next; //соответствие
          if ((prov1 == prov2 && (prov3 == nullptr || prov1 < prov2)) || (prov1 > prov2 && ((prov3 != nullptr && prov3->value.prior < prov2) || (prov3 == nullptr)))) {
            temp->next = first->next;
            first->next = temp;
            return;
          }
          first = first->next;
        }
     }
  }
  T pop() {
    ITEM *first = nullptr;
    first = head;
    if (first != nullptr) {
        T extract = first->data;
        head = first->next;
        return extract;
    } else {
        throw "Empty!";;
    }
  }
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
