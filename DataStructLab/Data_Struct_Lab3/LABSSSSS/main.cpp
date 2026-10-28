#include <iostream>
#include <list>
#include <vector>

using namespace std;
// PART 3 EKLEMELERÝ (Soru Talimatlarý Ýçin)

// Single Linked List Node (Question 1.a ve Question 2 için)
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

//  Double Linked List Node(Question 1.b için)
struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Question 1.a: Ordered Union of Two Linked Lists
Node* orderedUnion(Node* L1, Node* L2) {
    Node* resultHead = nullptr;
    Node* resultTail = nullptr;
    Node* tmp1 = L1;
    Node* tmp2 = L2;

    auto appendResult = [&](int val) {
        if (!resultHead) {
            resultHead = new Node(val);
            resultTail = resultHead;
        } else if (resultTail->data != val) {
            resultTail->next = new Node(val);
            resultTail = resultTail->next;
        }
    };

    while (tmp1 != nullptr && tmp2 != nullptr) {
        if (tmp1->data < tmp2->data) {
            appendResult(tmp1->data);
            tmp1 = tmp1->next;
        } else if (tmp2->data < tmp1->data) {
            appendResult(tmp2->data);
            tmp2 = tmp2->next;
        } else {
            appendResult(tmp1->data);
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
    }

    while (tmp1 != nullptr) {
        appendResult(tmp1->data);
        tmp1 = tmp1->next;
    }

    while (tmp2 != nullptr) {
        appendResult(tmp2->data);
        tmp2 = tmp2->next;
    }

    return resultHead;
}

// Question 1.b: Ordered Union of Two Double Linked Lists
struct DoubleListResult {
    DNode* head;
    int totalSize;
    int commonCount;
};

DoubleListResult orderedUnionDouble(DNode* A1, DNode* A2) {
    DNode* resultHead = nullptr;
    DNode* resultTail = nullptr;
    DNode* tmp1 = A1;
    DNode* tmp2 = A2;
    int size = 0;
    int common = 0;

    auto appendDoubleResult = [&](int val, bool isCommon) {
        if (isCommon) common++;
        if (!resultHead) {
            resultHead = new DNode(val);
            resultTail = resultHead;
        } else if (resultTail->data != val) {
            DNode* newNode = new DNode(val);
            resultTail->next = newNode;
            newNode->prev = resultTail;
            resultTail = newNode;
        } else {
            if (isCommon) common--; // Tekrar sayýmýný engellemek için
        }
        size++;
    };

    while (tmp1 != nullptr && tmp2 != nullptr) {
        if (tmp1->data < tmp2->data) {
            appendDoubleResult(tmp1->data, false);
            tmp1 = tmp1->next;
        } else if (tmp2->data < tmp1->data) {
            appendDoubleResult(tmp2->data, false);
            tmp2 = tmp2->next;
        } else {
            appendDoubleResult(tmp1->data, true);
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
    }

    while (tmp1 != nullptr) {
        appendDoubleResult(tmp1->data, false);
        tmp1 = tmp1->next;
    }

    while (tmp2 != nullptr) {
        appendDoubleResult(tmp2->data, false);
        tmp2 = tmp2->next;
    }

    return {resultHead, size, common};
}

// Question 2: Check if a Linked List is Palindrome
bool isPalindrome(Node* head) {
    if (!head || !head->next) return true;
    vector<int> vals;
    Node* curr = head;
    while (curr != nullptr) {
        vals.push_back(curr->data);
        curr = curr->next;
    }

    int left = 0;
    int right = vals.size() - 1;
    while (left < right) {
        if (vals[left] != vals[right]) return false;
        left++;
        right--;
    }
    return true;
}
void printLinkedList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

void printDoubleLinkedList(DNode* head) {
    DNode* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " <-> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}


int main()
{
//  PART 1
//          Question 1
int n;
cout<<"Enter the number:\n";
cin>>n;
vector<int>VectorIterator;
list<int>ListIterator;
vector<char>VectorIteratorChar;
list<char>ListIteratorChar;
vector<double>VectorIteratorDouble;
list<double>ListIteratorDouble;
for(int i=0;i<=n;i++){
    VectorIterator.push_back(i);
    ListIterator.push_back(i);
    VectorIteratorChar.push_back('0' + i);
    ListIteratorChar.push_back('0' + i);

    VectorIteratorDouble.push_back(i);
    ListIteratorDouble.push_back(i);
}

//     Vector Int
for (int i = 0; i < VectorIterator.size(); i++) {
    cout << "Vector Int \t" << VectorIterator[i]
         << " Address: " << &VectorIterator[i] << endl;
}

//     List Int
for (int& x : ListIterator) {
    cout << "List Int \t" << x
         << " Address: " << &x << endl;
}


//     Vector Char
for (int i = 0; i < VectorIteratorChar.size(); i++) {
    cout <<"Vector Char \t"<< VectorIteratorChar[i] << " Address: "
         << static_cast<void*>(&VectorIteratorChar[i]) << endl;
}

// List Char
for (char& x : ListIteratorChar) {
    cout <<"List Char \t"<< x << " Address: " << static_cast<void*>(&x) << endl;
}

//Vector Double
for (int i = 0; i < VectorIteratorDouble.size(); i++) {
    cout <<"Vector Double \t"<< VectorIteratorDouble[i] << " Address: "
         << &VectorIteratorDouble[i] << endl;
}

//    List Double
for (double& x : ListIteratorDouble) {
    cout<<"List Double \t" << x << " Address: " << &x << endl;
}
//   Question 2
int row,column;
cout<<"Please enter the row value:"<<"\n";
cin>>row;
cout<<"Please enter the column value:"<<"\n";
cin>>column;
int Array2D[row][column];
for(int i=0;i<row;i++){
    for(int j=0;j<column;j++){
        cout<<"&Array2D["<<i<<"]["<<j<<"]="<<&Array2D[i][j]<<"\n";



    }
}
cout<<"Total amount size:\t" << sizeof(Array2D) << "\n";



//  PART 2
vector<int>Inversenumbers = {0,1,2,3,4};

cout << "Size of vector is: " << Inversenumbers.size() << endl;

cout << "Vector elements are given below:" << endl;
for (int x : Inversenumbers) {
    cout << x << " ";
}
cout << endl << endl;

Inversenumbers.insert(Inversenumbers.begin(), 20);

cout << "Size of vector is: " << Inversenumbers.size() << endl;

cout << "Updated Vector elements are given below:" << endl;
for (int x : Inversenumbers) {
    cout << x << " ";
}
cout << endl << endl;

cout << "Output of reverse array: ";
for (vector<int>::iterator it = Inversenumbers.end(); it != Inversenumbers.begin();) {
    --it;
    cout << *it << " ";
}
cout << endl;

Inversenumbers.pop_back();

cout << "Output after remove last array element: ";
for (int x : Inversenumbers) {
    cout << x << " ";
}
cout << endl << endl;

// Question 1.a Test
cout << "\n--- Question 1.a: Ordered Union (Single Linked List) ---" << endl;
Node* L1 = new Node(1);
L1->next = new Node(3);
L1->next->next = new Node(5);
L1->next->next->next = new Node(7);

Node* L2 = new Node(2);
L2->next = new Node(3);
L2->next->next = new Node(6);
L2->next->next->next = new Node(8);

cout << "L1: "; printLinkedList(L1);
cout << "L2: "; printLinkedList(L2);
Node* unionResult = orderedUnion(L1, L2);
cout << "Result Union: "; printLinkedList(unionResult);


// Question 1.b Test
cout << "\n--- Question 1.b: Ordered Union (Double Linked List) ---" << endl;
DNode* A1 = new DNode(1);
A1->next = new DNode(3);
A1->next->prev = A1;
A1->next->next = new DNode(5);
A1->next->next->prev = A1->next;

DNode* A2 = new DNode(2);
A2->next = new DNode(3);
A2->next->prev = A2;
A2->next->next = new DNode(6);
A2->next->next->prev = A2->next;

cout << "A1: "; printDoubleLinkedList(A1);
cout << "A2: "; printDoubleLinkedList(A2);
DoubleListResult dRes = orderedUnionDouble(A1, A2);
cout << "Double List Result: "; printDoubleLinkedList(dRes.head);
cout << "Total Size: " << dRes.totalSize << " | Common Elements Count: " << dRes.commonCount << endl;


// Question 1.c Comparison (Printed as explanation)


//Vector bellekte ardışık olarak tutulduğu için elemanlara doğrudan ve hızlı bir şekilde erişilir O(1).
//Tek yönlü bağlı listeler, bellek boyutu dinamik olduğu için araya eleman ekleme ve silme işlemlerinde etkilidir.
//fakat aranan bir elemana ulaşmak için baştan başlayarak sırayla tarama yapmak gerekir O(n).
//Çift yönlü bağlı listeler ise hem ileri hem de geri yönde gezinebilme avantajı sağlar



// Question 2 Test
cout << "\n--- Question 2: Palindrome Linked List ---" << endl;
Node* palList1 = new Node(1);
palList1->next = new Node(2);
palList1->next->next = new Node(3);
palList1->next->next->next = new Node(2);
palList1->next->next->next->next = new Node(1);

cout << "List 1 (1->2->3->2->1): " << (isPalindrome(palList1) ? "Is Palindrome" : "Not Palindrome") << endl;

Node* palList2 = new Node(1);
palList2->next = new Node(2);
palList2->next->next = new Node(3);

cout << "List 2 (1->2->3): " << (isPalindrome(palList2) ? "Is Palindrome" : "Not Palindrome") << endl;

return 0;
}
