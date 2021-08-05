template <typename T>
class AVLTree
{
private:
  T data;
  AVLTree<T> *left, *right;

  AVLTree<T> *leftRotate();

public:
  //construction | destruction functions
  AVLTree() : left(nullptr), right(nullptr){};
  AVLTree(T data) : data(data), left(nullptr), right(nullptr){};
  ~AVLTree();

  //Manipulação de dados
  T getData() { return this->data; }
  AVLTree<T> *getLeft() { return this->left; }

  //Algoritmos característiscos de árvore
  AVLTree *insert(T data);
  void inOrder();
  void inLevel();
  void preOrder();
  void posOrder();

  T greater();
  T smaller();

  int height();
  AVLTree *find(T value);
  AVLTree *remove(T value);
};

template <typename T>
AVLTree<T>::~AVLTree()
{
  this->left = nullptr;
  this->right = nullptr;
}
