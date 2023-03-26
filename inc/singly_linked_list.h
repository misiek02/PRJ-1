#pragma once
template <typename T> struct Node {
  T value;
  Node<T> *next;

  Node() { this->next = NULL; }
  Node(T value, Node *next = NULL) {
    this->value = value;
    this->next = next;
  }
};

template <typename T> struct SinglyLinkedList {
  Node<T> *head;
  int siz;

public:
  SinglyLinkedList() {
    this->head = NULL;
    siz = 0;
  }
  bool empty();                      // returns 1 if stack is empty
  int size();                        // returns number of elements
  void addFront(const T &newElem);   // adds element to the list(front)
  void removeFront();                // removes elem from list (front)
  void addBack(const T &newElement); // adds element to the list(back)
  void removeBack();                 // removes elem from list (back)
  const T &front() const; // returns elem from list (front) deosnt delete
  const T &back() const;  // returns elem from list (back) deosnt delete
  void insert(const T &newElement,
              int index);   //  inserts elem at the  index position
  T &operator[](int index); // list indexing
};

// EMPTY - returns 1 if stack is empty
template <typename T> bool SinglyLinkedList<T>::empty() {
  if (head == NULL) {
    std::cout << "List is empty\n";
    return true;
  }

  std::cout << "List isn't empty\n";
  return false;
}

// SIZE - returns number of elements
template <typename T> int SinglyLinkedList<T>::size() { return siz; }

// addFront - adds element at the front
template <typename T> void SinglyLinkedList<T>::addFront(const T &newElem) {
  head = new Node(newElem, head);
  siz++;
}

template <typename T> void SinglyLinkedList<T>::removeFront() {
  if (empty()) {
    std::cout << "List empty\n";
    exit(1);
  }
  head = head->next;
  siz--;
}

// addBack -adds element to the list (back)
template <typename T> void SinglyLinkedList<T>::addBack(const T &newElement) {
  Node<T> *NEW = new Node<T>;
  Node<T> *back;
  NEW->value = newElement;

  if (!empty()) {
    back = head;
    while (back->next != NULL) {
      back = back->next;
    }
    back->next = NEW;
  } else {
    head = NEW;
  }
  siz++;
}

// removeBack - removes elem from list (back)
template <typename T> void SinglyLinkedList<T>::removeBack() {
  Node<T> *temp;
  Node<T> *back;

  if (!empty()) {
    back = head;

    while (back->next != NULL) {
      temp = back;
      back = back->next;
    }
    temp->next = NULL;
    siz--;
  } else {
    empty();
  }
}

// front - returns elem from list (front) deosnt delete
template <typename T> const T &SinglyLinkedList<T>::front() const {

  return head->value;
}

// front - returns elem from list (front) deosnt delete
template <typename T> const T &SinglyLinkedList<T>::back() const {

  Node<T> *back;

  back = head;

  while (back->next != NULL) {

    back = back->next;
  }
  return back->value;
}

//  insert - inserts elem at the  index position
template <typename T>
void SinglyLinkedList<T>::insert(const T &newElement, int index) {
  if (index < 1)
    index = 1;
  if (index > siz)
    index = siz;

  int temp = 1;

  Node<T> *NEW = new Node<T>;
  Node<T> *OLD;
  Node<T> *temp_node = new Node<T>;
  NEW->value = newElement;

  temp_node = head;
  if (head != NULL) {
    while (temp != index - 1) {
      temp_node = temp_node->next;
      temp++;
    }
    OLD = temp_node->next;
    temp_node->next = NEW;
    NEW->next = OLD;
    siz++;
  } else
    addFront(newElement);
}

template <typename T> T &SinglyLinkedList<T>::operator[](int index) {
  if (index < 0)
    index = 0;
  if (index > siz)
    index = siz;

  Node<T> *back;
  int temp = 0;

  if (!empty()) {
    back = head;
    while (temp != index) {
      back = back->next;
      temp++;
    }
  }

  return back->value;
}
