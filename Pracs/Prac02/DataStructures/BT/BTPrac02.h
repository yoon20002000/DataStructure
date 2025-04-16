#pragma once

class BTPrac02Node
{
public:
    BTPrac02Node(char c);
    ~BTPrac02Node();
    BTPrac02Node(const BTPrac02Node& other) = delete;
    BTPrac02Node& operator=(const BTPrac02Node& other) = delete;
    BTPrac02Node(BTPrac02Node&& other) noexcept;
    BTPrac02Node& operator=(BTPrac02Node&& other) noexcept;

    char data;
    BTPrac02Node* left;
    BTPrac02Node* right;
};

class BTPrac02
{
public:
    static void printPreorder(BTPrac02Node* root);
    static void printInorder(BTPrac02Node* root);
    static void printPostorder(BTPrac02Node* root);
};
