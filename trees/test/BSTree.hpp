class node
{
private:
  int data;
  node *left, *right;

public:
  node(int data) : data(data), left(nullptr), right(nullptr){};
  ~node()
  {
    this->left = nullptr;
    this->right = nullptr;
  };

  /* Manipulação de ponteiros */
  void setRight(node *ptr) { this->right = ptr; }
  void setLeft(node *ptr) { this->left = ptr; }
  node *getRight() { return this->right; }
  node *getLeft() { return this->left; }

  /* manipulação de dados */
  void setData(int data) { this->data = data; }
  int getData() { return this->data; }
};

class BSTree
{
private:
  node *root;

public:
  BSTree() : root(nullptr){};
  ~BSTree();

  void insert(int data);
};

BSTree::~BSTree()
{
}
