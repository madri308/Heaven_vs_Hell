#ifndef NODE_H
#define NODE_H
struct Human;
struct Node
{
public:
    Node(Human *data);
    Node *next = nullptr;
    Node *prev = nullptr;
    Node *left = nullptr;
    Node *right = nullptr;
    Human *data;
};

#endif // NODE_H
