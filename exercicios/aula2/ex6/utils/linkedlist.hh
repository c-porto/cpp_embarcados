namespace utils {
template <class T> struct Node {
  T value;
  Node *next;
};

template <class T> class LinkedList {
public:
  LinkedList();
  LinkedList(Node<T> item);
  ~LinkedList();

private:
  Node<T> *head;
  Node<T> *tail;
};

template <class T> LinkedList<T>::LinkedList(Node<T> item) {}

template <class T> LinkedList<T>::~LinkedList() {}
} // namespace utils
