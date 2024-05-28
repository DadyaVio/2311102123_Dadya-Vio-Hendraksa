#include <iostream>
#include <iomanip>

using namespace std;

struct Pohon
{
    char data;
    Pohon *left, *right, *parent;
};

Pohon *root, *baru;

void init() // inisialisasi
{
    root = NULL;
}

bool isEmpty() // cek apakah tree kosong
{
    return root == NULL;
}

void buatNode(char data) // membuat node root
{
    if (isEmpty())
    {
        root = new Pohon();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\nNode " << data << " berhasil dibuat sebagai root!" << endl;
    }
    else
    {
        cout << "\nTree sudah ada!" << endl;
    }
}

Pohon *findNode(Pohon *node, char data) // mencari node
{
    if (node == NULL) return NULL;
    if (node->data == data) return node;

    Pohon *foundNode = findNode(node->left, data);
    if (foundNode == NULL)
        foundNode = findNode(node->right, data);

    return foundNode;
}

Pohon *insertLeft(char data, Pohon *node) // menambah child kiri
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->left != NULL)
        {
            cout << "\nNode " << node->data << " sudah ada child kiri!" << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data << endl;
            return baru;
        }
    }
}

Pohon *insertRight(char data, Pohon *node) // menambah child kanan
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->right != NULL)
        {
            cout << "\nNode " << node->data << " sudah ada child kanan!" << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << baru->parent->data << endl;
            return baru;
        }
    }
}

void update(char data, Pohon *node) // mengupdate node
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        }
        else
        {
            char temp = node->data;
            node->data = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

void find(Pohon *node) // mencari node dan menampilkan informasi node
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        }
        else
        {
            cout << "\nData Node: " << node->data << endl;
            cout << "Root: " << root->data << endl;
            if (!node->parent)
                cout << "Parent: (tidak punya parent)" << endl;
            else
                cout << "Parent: " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                cout << "Sibling: " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << "Sibling: " << node->parent->right->data << endl;
            else
                cout << "Sibling: (tidak punya sibling)" << endl;
            if (!node->left)
                cout << "Child Kiri: (tidak punya child kiri)" << endl;
            else
                cout << "Child Kiri: " << node->left->data << endl;
            if (!node->right)
                cout << "Child Kanan: (tidak punya child kanan)" << endl;
            else
                cout << "Child Kanan: " << node->right->data << endl;
        }
    }
}

void printDescendants(Pohon *node) // menampilkan descendants
{
    void preOrder(Pohon * node);

    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else if (!node)
    {
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
    }
    else
    {
        cout << "Descendants dari node " << node->data << " : ";
        if (node->left) preOrder(node->left);
        if (node->right) preOrder(node->right);
        cout << endl;
    }
}

void printChild(Pohon *node) // menampilkan child
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else if (!node)
    {
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
    }
    else
    {
        if (node->left)
        {
            cout << "Child Kiri: " << node->left->data << endl;
        }
        else
        {
            cout << "Child Kiri: (tidak ada)" << endl;
        }

        if (node->right)
        {
            cout << "Child Kanan: " << node->right->data << endl;
        }
        else
        {
            cout << "Child Kanan: (tidak ada)" << endl;
        }
    }
}

// Cek Size Tree
int size(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

// Cek Height Level Tree
int height(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            if (heightKiri >= heightKanan)
            {
                return heightKiri + 1;
            }
            else
            {
                return heightKanan + 1;
            }
        }
    }
}

// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon *node)
{
    if (node != NULL)
    {
        cout << " " << node->data << ", ";
        preOrder(node->left);
        preOrder(node->right);
    }
}


// inOrder
void inOrder(Pohon *node = root)
{
    if (node != NULL)
    {
        inOrder(node->left);
        cout << " " << node->data << ", ";
        inOrder(node->right);
    }
}

// postOrder
void postOrder(Pohon *node = root)
{
    if (node != NULL)
    {
        postOrder(node->left);
        postOrder(node->right);
        cout << " " << node->data << ", ";
    }
    cout << endl;
}

// Karakteristik Tree
void characteristic()
{
    cout << "\n Size Tree : " << size() << endl;
    cout << " Height Tree : " << height() << endl;
    cout << " Average Node of Tree : " << size() / height() << endl;
}

int main() {
    int choice_2123;
    char data_2123, parentData_2123;
    Pohon *parentNode_2123;

    init();

    do {
        cout << "\nMenu Program Graph dan Tree dari Dadya Vio Hendraksa:\n";
        cout << "1. Buat node root\n";
        cout << "2. Tambah node child kiri\n";
        cout << "3. Tambah node child kanan\n";
        cout << "4. Update node\n";
        cout << "5. Cari node dan tampilkan informasi\n";
        cout << "6. Tampilkan descendants\n";
        cout << "7. Tampilkan child\n";
        cout << "8. Tampilkan karakteristik tree\n";
        cout << "9. Cari PreOrder\n";
        cout << "10. Cari InOrder\n";
        cout << "11. Cari PostOrder\n";
        cout << "12. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> choice_2123;

        switch (choice_2123) {
            case 1:
                if (isEmpty()) {
                    cout << "Masukkan data untuk simpul root: ";
                    cin >> data_2123;
                    buatNode(data_2123);
                } else {
                    cout << "Tree ternyata sudah ada\n";
                }
                break;
            case 2:
                cout << "Masukkan data untuk simpul parent: ";
                cin >> parentData_2123;
                parentNode_2123 = findNode(root, parentData_2123);
                if (parentNode_2123)
                {
                    cout << "Masukkan data untuk child kiri: ";
                    cin >> data_2123;
                    insertLeft(data_2123, parentNode_2123);
                }
                else
                {
                    cout << "Simpul parent tidak ada.\n";
                }
                break;
            case 3:
                cout << "Masukkan data untuk simpul parent: ";
                cin >> parentData_2123;
                parentNode_2123 = findNode(root, parentData_2123);
                if (parentNode_2123)
                {
                    cout << "Masukkan data untuk child kanan: ";
                    cin >> data_2123;
                    insertRight(data_2123, parentNode_2123);
                }
                else
                {
                    cout << "Simpul parent tidak ada.\n";
                }
                break;
            case 4:
                cout << "Masukkan data simpul yang ingin diubah: ";
                cin >> data_2123;
                parentNode_2123 = findNode(root, data_2123);
                if (parentNode_2123)
                {
                    cout << "Masukkan data baru untuk simpul: ";
                    cin >> data_2123;
                    update(data_2123, parentNode_2123);
                }
                else
                {
                    cout << "Simpul tidak ada.\n";
                }
                break;
            case 5:
                cout << "Masukkan data simpul yang ingin dicari: ";
                cin >> data_2123;
                parentNode_2123 = findNode(root, data_2123);
                find(parentNode_2123);
                break;
            case 6:
                cout << "Masukkan data simpul yang ingin ditampilkan descendants-nya: ";
                cin >> data_2123;
                parentNode_2123 = findNode(root, data_2123);
                printDescendants(parentNode_2123);
                break;
            case 7:
                cout << "Masukkan data simpul yang ingin ditampilkan child-nya: ";
                cin >> data_2123;
                parentNode_2123 = findNode(root, data_2123);
                printChild(parentNode_2123);
                break;
            case 8:
                characteristic();
                break;
            case 9:
                cout << "Cari PreOrder: ";
                preOrder(root);
                cout << endl;
                break;
            case 10:
                cout << "Cari InOrder: ";
                inOrder(root);
                cout << endl;
                break;
            case 11:
                cout << "Cari PostOrder: ";
                postOrder(root);
                cout << endl;
                break;
            case 12:
                cout << "Anda telah keluar dari program Graph ini.\n";
                break;
            default:
                cout << "Pilihan anda tidak sesuai.\n";
                break;
        }
    } while (choice_2123 != 12);

    return 0;
}