#pragma once
class BST12Node
{
public:
	BST12Node(int data);
	~BST12Node() = default;
	BST12Node(const BST12Node& other) = delete;
	BST12Node& operator=(const BST12Node& other) = delete;
	BST12Node(BST12Node&& other) = delete;
	BST12Node& operator=(BST12Node&& other) = delete;
private:
	int value;
	BST12Node* left;
	BST12Node* right;
	friend class BST12;
};
class BST12
{
public:
	BST12();
	~BST12();
	BST12(const BST12& other);
	BST12& operator=(const BST12& other);
	BST12(BST12&& other) noexcept;
	BST12& operator=(BST12&& other) noexcept;

	void insert(int value);
	void remove(int value);
	BST12Node* search (int value) const;
private:
	BST12Node* insertNode(BST12Node* node, int value);
	BST12Node* deleteNode(BST12Node* node, int value);
	BST12Node* searchNode(BST12Node* node, int value) const;
	BST12Node* findMax(BST12Node* node) const;

	BST12Node* copyTree(BST12Node* node);
	void deleteTree(BST12Node* node);
private:
	BST12Node* root;
};

