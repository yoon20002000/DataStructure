#pragma once

class BSTPrac03Node
{
public:
    BSTPrac03Node();
    BSTPrac03Node(int data, BSTPrac03Node* left = nullptr, BSTPrac03Node* right = nullptr);
    ~BSTPrac03Node();
    BSTPrac03Node(const BSTPrac03Node& other) = delete;
    BSTPrac03Node& operator=(const BSTPrac03Node& other) = delete;
    BSTPrac03Node(BSTPrac03Node&& other) noexcept;
    BSTPrac03Node& operator=(BSTPrac03Node&& other) noexcept;

public:
    int data;
    BSTPrac03Node* left;
    BSTPrac03Node* right;
};

class BSTPrac03
{
public:
    BSTPrac03();
    ~BSTPrac03();
    BSTPrac03(const BSTPrac03& other);
    BSTPrac03& operator=(const BSTPrac03& other);
    BSTPrac03(BSTPrac03&& other) noexcept;
    BSTPrac03& operator=(BSTPrac03&& other) noexcept;

    void insert(int data);
    void deleteData(int data);
    
    BSTPrac03Node* search(BSTPrac03Node* node, int data);
    BSTPrac03Node* deleteData(BSTPrac03Node* node, int data);
    BSTPrac03Node* findMax(BSTPrac03Node* node);

    BSTPrac03Node* copyNode(BSTPrac03Node* node);
    void deleteNode(BSTPrac03Node* node);

private:
    BSTPrac03Node* insert(BSTPrac03Node* node, int data);
public:
    BSTPrac03Node* root;
    
};
