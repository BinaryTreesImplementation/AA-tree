#include <iostream>     

class Counter
{
protected:
	size_t& Count() { static size_t counter = 0; return counter; }

public:
	Counter() { ++Count(); }
	~Counter() { --Count(); }
};

using namespace std;

template <typename T>
class AATree {

private:


	struct AANode : public Counter
	{
		T key;
		AANode    *left;
		AANode    *right;
		int        level;
		AANode() : left(nullptr), right(nullptr), level(1) { }
		AANode(const T& value) : left(nullptr), right(nullptr), level(1), key(value) { }

		size_t getCounter()
		{
			return Count();
		}
	} *root;

public:


	AATree()
	{
		root = nullptr;
	}

	void deleteNode(AANode* temp)
	{
		if (temp != nullptr)
		{
			deleteNode(temp->left);
			deleteNode(temp->right);
			delete temp;

		}
		if (root->getCounter() == 0)
			root = nullptr;
	}

	~AATree()
	{
		deleteNode(root);
	}



	AANode *search(const T& value)const
	{
		AANode *searchedElement = root;
		
		while (searchedElement != nullptr)
		{
			if (searchedElement->key < value)
			{
				searchedElement = searchedElement->right;
			}
			else if (value < searchedElement->key)
			{
				searchedElement = searchedElement->left;
			}
			else if (searchedElement->key == value)
			{
				return searchedElement;
			}
		}

		return nullptr;
	}
/*
	AANode* decreaseLevel(AANode* localRoot)
	{

		int shouldBe = localRoot->left->level - localRoot->right->level + 1;
		if (shouldBe < localRoot->level)
		{
			localRoot->level = shouldBe;
			if (shouldBe < localRoot->right->level)
				localRoot->right->level = shouldBe;
		}
		return localRoot;
	}

	void remove(const T& key, AANode* localRoot)
	{
		AANode* parent = parentSearch(key);
		//AANode *removing = parent->left->key == key ? parent->left : parent->right;


		std::cout << parent->key;
	}
	/*
	if(removing)
	{
	if (!removing->left && !removing->right)
	{
	parent->left == localRoot ? parent->left = nullptr : parent->right = nullptr;
	delete localRoot;
	return;
	}

	else if (localRoot->left == nullptr)
	{
	AANode* successor = nullptr;
	if (localRoot->right)
	{
	successor = localRoot->right;
	while (successor->left != nullptr)
	{
	parent = successor;
	successor = successor->left;
	}
	}

	localRoot->right = remove(successor->key, localRoot->left);
	localRoot->key = successor->key;
	if (parent)
	{
	parent->left = nullptr;
	}
	delete successor;
	return;
	}

	else
	{
	AANode* predecessor = nullptr;
	if (localRoot->left)
	{
	predecessor = localRoot->left;
	while (predecessor->right != nullptr)
	{
	parent = predecessor;
	predecessor = predecessor->right;
	}
	}

	localRoot->left = remove(predecessor->key, localRoot->right);
	localRoot->key = predecessor->key;
	if (parent)
	{
	parent->right = nullptr;
	}
	delete predecessor;
	return;
	}
	//localRoot = decreaseLevel(localRoot);

	}
	}
	*/







	void insert(const T & x)
	{
		insert(x, root);
	}

	void remove(const T & x)
	{
		remove(x, root);
	}



	void insert(const T & x, AANode * & t)
	{
		if (t == nullptr)
		{
			root = new AANode(x);
		}
		else if (x < t->key)
			insert(x, t->left);
		else if (t->key < x)
			insert(x, t->right);
		else
			return;

		t = skew(t);
		t = split(t);
	}






	AANode* skew(AANode * & t)
	{
		if (t == nullptr)
			return nullptr;
		else if (t->left == nullptr)
			return t;
		else if (t->left->level == t->level)
			rotateWithLeftChild(t);
		else
			return t;
	}


	AANode* split(AANode * & t)
	{
		if (t == nullptr)
			return nullptr;
		else if (t->right == nullptr || t->right->right == nullptr)
			return t;
		else if (t->right->right->level == t->level)
		{
			rotateWithRightChild(t);
			t->level++;
		}
		else
			return t;
	}

	void rotateWithLeftChild(AANode * & k2)
	{
		AANode *k1 = k2->left;
		k2->left = k1->right;
		k1->right = k2;
		k2 = k1;
	}

	void rotateWithRightChild(AANode * & k1)
	{
		AANode *k2 = k1->right;
		k1->right = k2->left;
		k2->left = k1;
		k1 = k2;
	}

	T* getLevel(const T& key)
	{
		AANode *node = search(key);
		if (node != nullptr)
			return new T(node->level);
		else
			return nullptr;
	}

	T* getRightKey(const T& key)
	{
		AANode *node = search(key);
		if (node != nullptr && node->right != nullptr)
			return new T(node->right->key);
		else
			return nullptr;
	}

	T* getKeyRoot()
	{
		if (root)
			return new T(root->key);
		else
			return nullptr;
	}
	T* getLeftKey(const T& key)
	{
		AANode *node = search(key);
		if (node != nullptr && node->left != nullptr)
			return new T(node->left->key);
		else
			return nullptr;
	}

	int getcount() {
		return root->getCounter();
	}

	AANode* getroot() const {
		return root;
	}
};
