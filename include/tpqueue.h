// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
  struct ITEM {
    T data;
    ITEM* next;
  };

 private:
  ITEM* jump;

 public:
  TPQueue():head(nullptr),tail(nullptr){};

  void push(const T& value) {
    ITEM* first = jump;
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
    first = jump;
    if (first != nullptr) {
        T extract = first->data;
        jump = first->next;
        return extract;
    } else {
        throw "Empty!";;
    }
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
