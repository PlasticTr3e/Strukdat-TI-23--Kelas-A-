/* Nama program : penjumlahan_MatriksSparse
Nama            : Bagas Diatama Wardoyo 140810230061
Nama            : MUHAMMAD LUTHFI AZIZ SUNARYA 140810230081
Nama            : MUHAMAD HISYAM AZ-ZAHRAN 140810230065
Tanggal buat    : 02/06/2024
Deskripsi       : Tugas Kelompok Matriks Sparse
**********************************************************************/
#include <iostream>
#include <iomanip>

using namespace std;

struct Node {
    int row, col, value;
    Node* nextRow;
    Node* nextCol;
};

struct HeadNode {
    int index;
    Node* firstNode;
    HeadNode* nextHead;
};

typedef Node* NodePtr;
typedef HeadNode* HeadNodePtr;

NodePtr createNode(int row, int col, int value);
HeadNodePtr createHeadNode(int index);
HeadNodePtr findOrCreateHeadNode(HeadNodePtr &headList, int index);
void insertNode(HeadNodePtr &rowHeadList, HeadNodePtr &colHeadList, int row, int col, int value);
NodePtr findNode(HeadNodePtr headList, int row, int col);
void addMatrix(HeadNodePtr rowHeadListA, HeadNodePtr colHeadListA, HeadNodePtr rowHeadListB, HeadNodePtr colHeadListB, HeadNodePtr &rowHeadListC, HeadNodePtr &colHeadListC);
void printMatrix(HeadNodePtr rowHeadList);
void inputMatrix(HeadNodePtr &rowHeadList, HeadNodePtr &colHeadList);


int main() {
    HeadNodePtr rowHeadListA = nullptr;
    HeadNodePtr colHeadListA = nullptr;
    HeadNodePtr rowHeadListB = nullptr;
    HeadNodePtr colHeadListB = nullptr;
    HeadNodePtr rowHeadListC = nullptr;
    HeadNodePtr colHeadListC = nullptr;

    bool Loop = true;

    do {
        cout << "Masukkan Elemen Matriks Sparse A [row column value]:" << endl;
        inputMatrix(rowHeadListA, colHeadListA);

        cout << "Masukkan Elemen Matriks Sparse B [row column value]:" << endl;
        inputMatrix(rowHeadListB, colHeadListB);

        addMatrix(rowHeadListA, colHeadListA, rowHeadListB, colHeadListB, rowHeadListC, colHeadListC);

        cout << "Matrix A:\n";
        printMatrix(rowHeadListA);
        cout << "\nMatrix B:\n";
        printMatrix(rowHeadListB);
        cout << "\nMatrix A + B:\n";
        printMatrix(rowHeadListC);

        char opsi;
        cout << "\nLanjut? (Y/N)\n=> ";
        cin >> opsi;
        if (toupper(opsi) != 'Y') {
            Loop = false;
        }
    } while (Loop);

    return 0;
}

NodePtr createNode(int row, int col, int value) {
    NodePtr newNode = new Node{row, col, value, nullptr, nullptr};
    return newNode;
}

HeadNodePtr createHeadNode(int index) {
    HeadNodePtr newHeadNode = new HeadNode{index, nullptr, nullptr};
    return newHeadNode;
}

HeadNodePtr findOrCreateHeadNode(HeadNodePtr &headList, int index) {
    HeadNodePtr prev = nullptr;
    HeadNodePtr current = headList;
    while (current && current->index < index) {
        prev = current;
        current = current->nextHead;
    }
    if (current && current->index == index) {
        return current;
    } else {
        HeadNodePtr newHeadNode = createHeadNode(index);
        if (prev) {
            prev->nextHead = newHeadNode;
        } else {
            headList = newHeadNode;
        }
        newHeadNode->nextHead = current;
        return newHeadNode;
    }
}

void insertNode(HeadNodePtr &rowHeadList, HeadNodePtr &colHeadList, int row, int col, int value) {
    HeadNodePtr rowHead = findOrCreateHeadNode(rowHeadList, row);
    HeadNodePtr colHead = findOrCreateHeadNode(colHeadList, col);

    NodePtr newNode = createNode(row, col, value);

    if (!rowHead->firstNode) {
        rowHead->firstNode = newNode;
    } else {
        NodePtr temp = rowHead->firstNode;
        if (temp->col > col) {
            newNode->nextRow = temp;
            rowHead->firstNode = newNode;
        } else {
            while (temp->nextRow && temp->nextRow->col < col) {
                temp = temp->nextRow;
            }
            newNode->nextRow = temp->nextRow;
            temp->nextRow = newNode;
        }
    }

    if (!colHead->firstNode) {
        colHead->firstNode = newNode;
    } else {
        NodePtr temp = colHead->firstNode;
        if (temp->row > row) {
            newNode->nextCol = temp;
            colHead->firstNode = newNode;
        } else {
            while (temp->nextCol && temp->nextCol->row < row) {
                temp = temp->nextCol;
            }
            newNode->nextCol = temp->nextCol;
            temp->nextCol = newNode;
        }
    }
}

NodePtr findNode(HeadNodePtr headList, int row, int col) {
    while (headList) {
        if (headList->index == row) {
            NodePtr current = headList->firstNode;
            while (current) {
                if (current->row == row && current->col == col) {
                    return current;
                }
                current = current->nextRow;
            }
        }
        headList = headList->nextHead;
    }
    return nullptr;
}

void addMatrix(HeadNodePtr rowHeadListA, HeadNodePtr colHeadListA, HeadNodePtr rowHeadListB, HeadNodePtr colHeadListB, HeadNodePtr &rowHeadListC, HeadNodePtr &colHeadListC) {
    HeadNodePtr currentRowHeadA = rowHeadListA;
    while (currentRowHeadA) {
        NodePtr currentNodeA = currentRowHeadA->firstNode;
        while (currentNodeA) {
            insertNode(rowHeadListC, colHeadListC, currentNodeA->row, currentNodeA->col, currentNodeA->value);
            currentNodeA = currentNodeA->nextRow;
        }
        currentRowHeadA = currentRowHeadA->nextHead;
    }

    HeadNodePtr currentRowHeadB = rowHeadListB;
    while (currentRowHeadB) {
        NodePtr currentNodeB = currentRowHeadB->firstNode;
        while (currentNodeB) {
            NodePtr nodeInC = findNode(rowHeadListC, currentNodeB->row, currentNodeB->col);
            if (nodeInC) {
                nodeInC->value += currentNodeB->value;
            } else {
                insertNode(rowHeadListC, colHeadListC, currentNodeB->row, currentNodeB->col, currentNodeB->value);
            }
            currentNodeB = currentNodeB->nextRow;
        }
        currentRowHeadB = currentRowHeadB->nextHead;
    }
}

void printMatrix(HeadNodePtr rowHeadList) {
    if (!rowHeadList) {
        cout << "Matrix is empty." << endl;
        return;
    }
    int maxRow = 0, maxCol = 0;
    HeadNodePtr currentRowHead = rowHeadList;
    while (currentRowHead) {
        NodePtr currentNode = currentRowHead->firstNode;
        while (currentNode) {
            if (currentNode->row > maxRow) maxRow = currentNode->row;
            if (currentNode->col > maxCol) maxCol = currentNode->col;
            currentNode = currentNode->nextRow;
        }
        currentRowHead = currentRowHead->nextHead;
    }
    currentRowHead = rowHeadList;
    for (int i = 0; i <= maxRow; ++i) {
        NodePtr currentNode = nullptr;
        while (currentRowHead && currentRowHead->index < i) {
            currentRowHead = currentRowHead->nextHead;
        }
        if (currentRowHead && currentRowHead->index == i) {
            currentNode = currentRowHead->firstNode;
        }
        for (int j = 0; j <= maxCol; ++j) {
            if (currentNode && currentNode->col == j) {
                cout << setw(3) << currentNode->value << " ";
                currentNode = currentNode->nextRow;
            } else {
                cout << setw(3) << 0 << " ";
            }
        }
        cout << endl;
    }
}

void inputMatrix(HeadNodePtr &rowHeadList, HeadNodePtr &colHeadList) {
    while (true) {
        int row, col, value;
        cout << "Row, Column, dan Value: ";
        cin >> row >> col >> value;
        if (row == -1 && col == -1 && value == -1) break;
        insertNode(rowHeadList, colHeadList, row, col, value);
    }
}
