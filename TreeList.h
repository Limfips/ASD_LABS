#include "Entiry.h"

using namespace std;


class TreeList {

private:
    struct Node
    {
        int key; // Ключ, по которому строится дерево
        Student* data; // Полезные данные (любого типа)
        Node *left, *right; // Указатели на соседние узлы
    };

    Node* root;

    bool addNode(Node*& node, int key, Student* data) {
        if (node == nullptr) {
            node = new Node{key, data, nullptr, nullptr};
            return true;
        }
        if (node->key > key) {
            return addNode(node->left, key, data);
        }
        if (node->key < key) {
            return addNode(node->right, key, data);
        }
        return false;
    }

    void inorder(Node* r)
    {
        if (r == nullptr) return;
        inorder(r->left);
        cout<<r->key<<":["<<r->data->id<<"] ";
        inorder(r->right);
    }

    void preorder(Node* r)
    {
        if (r == nullptr) return;
        cout<<r->key<<":["<<r->data->id<<"] ";
        preorder(r->left);
        preorder(r->right);
    }

    void postorder(Node* r)
    {
        if (!r) return;
        postorder(r->left);
        postorder(r->right);
        cout<<r->key<<":["<<r->data->id<<"] ";
    }

    Student* searchByKeyNode(Node* r, int key)
    {
        if (r == nullptr) {
            return nullptr;
        }
        if (r->key == key) {
            return r->data;
        }
        if (r->key > key) {
            return searchByKeyNode(r->left, key);
        }
        if (r->key < key) {
            return searchByKeyNode(r->right, key);
        }
        return nullptr;
    }

    bool dellNode(Node *r, Node* parent) {
        Node* tmp = r->right;
        Node* tmpParent = r;
        while (tmp->left != nullptr) {
            tmpParent = tmp;
            tmp = tmp->left;
        }
        if (parent == nullptr) {
            tmpParent->left = tmp->right;
            tmp->left = r->left;
            tmp->right = r->right;
            free(r);
            root = tmp;
        } else {
            parent->right = tmp;
            tmpParent->left = tmp->right;
            tmp->left = r->left;
            tmp->right = r->right;
            free(r);
        }

        return true;
    }
    bool removeNode(Node *r, int key, Node* parent) {
        if (r == nullptr) {
            return false;
        }
        if (r->key == key) {
            dellNode(r, parent);
            return true;
        } else {
            if (r->key > key) {
                return removeNode(r->left, key, r);
            }
            if (r->key < key) {
                return removeNode(r->right, key, r);
            }
        }
        return false;
    }


public:
    TreeList() {
        root = nullptr;
    }

    /**
     * Вставка узла в дерево
     *
     * @param key ключ (id)
     * @param data  значение типа Student
     * @return бинарный результат выполнения
     */
    bool add(int key, Student* data) {
        if (root == nullptr) {
            root = new Node{key, data, nullptr, nullptr};
            return true;
        }
        if (root->key > key) {
            return addNode(root->left, key, data);
        }
        if (root->key < key) {
            return addNode(root->right, key, data);
        }
        return false;
    }

    /**
     * Удаление узла из дерева
     *
     * @param key ключ (id)
     * @return бинарный результат выполнения
     */
    bool remove(int key) {
       if (root == nullptr) {
           return false;
       }
        if (root->key == key) {
            dellNode(root, nullptr);
            return true;
        } else {
            if (root->key > key) {
                return removeNode(root->left, key, root);
            }
            if (root->key < key) {
                return removeNode(root->right, key, root);
            }
        }
        return false;
    }

    /**
     * Поиск по дереву
     *
     * @param key ключ (id)
     * @return
     */
    Student* searchByKey(int key) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->key == key) {
            return root->data;
        }
        if (root->key > key) {
            return searchByKeyNode(root->left, key);
        }
        if (root->key < key) {
            return searchByKeyNode(root->right, key);
        }
        return nullptr;
    }

    /**
     * Прохождение дерева в последовательном (в глубину) порядке.
     *
     * (Последовательный (он же инфиксный, симметричный,
     * поперечный) – дерево проходится, начиная с левой ветви вверх к
     * корню, затем к правой ветви)
     */
    void print1() {
        if (root == nullptr) return;
        inorder(root->left);
        cout<<root->key<<":["<<root->data->id<<"] ";
        inorder(root->right);
    }

    /**
     * Прохождение дерева в нисходящем (в глубину) порядке.
     *
     * (Нисходящий (префиксный или прямой) – от корня к левой
     * ветви, затем к правой)
     */
    void print2() {
        if (root == nullptr) return;
        cout<<root->key<<":["<<root->data->id<<"] ";
        preorder(root->left);
        preorder(root->right);
    }



    /**
     * Прохождение дерева в восходящем (в глубину) порядке.
     *
     * (Восходящий (постфиксный или обратный) – проходится
     * левая ветвь, затем правая, затем корень.)
     */
    void print3() {
        if (!root) return;
        postorder(root->left);
        postorder(root->right);
        cout<<root->key<<":["<<root->data->id<<"] ";
    }
};
