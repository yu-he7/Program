#include <iostream>

using namespace std;

char arrayList[10];
int front = 0;
int end = 0;
void Push(char a) {
    ::end = (::end + 1) % 10;
    arrayList[::end] = a;
}
void Pop() {
    front = (front + 1) % 10;
}
int full() {
    if (front == (::end + 1) % 10) return 1;
    else return 0;
}
int empty() {
    if (::end  == front) return 1;
    else return 0;
}

int main() {
    int n = 0;
    while(n != 4) {
        cout << "********** Queue Program **********\n";
        cout << "1. Insert item to Queue\n";
        cout << "2. Delete item from Queue\n";
        cout << "3. Print Queue\n";
        cout << "4. Exit\n";
        cout << "\n\n";
        cout << "Enter menu : ";
        cin >> n;
        if (n == 1) {
            char str;
            cout << "# Enter item to insert : ";
            cin >> str;
            if (full())  cout << "# Queue is full." << "\n";
            else {
                Push(str);
                cout << "#'" << str << "' is inserted.\n";
                cout << "# State of Queue : ";
                cout << "[";
                for (int i = (front + 1) % 10; i < (::end + 1) % 10; i = (i + 1) % 10) {
                    if (i != ((::end + 1) % 10) - 1) {
                        cout << "'" << arrayList[i] << "', ";
                    }
                    else {
                        cout << "'" << arrayList[i] << "']\n\n\n";
                    }
                }
            }
        }
        else if (n == 2) {
            if (empty()) cout << "# Nothing to delete in queue.\n\n";
            else {
                Pop();
                cout << "# First item '" << arrayList[front] << "' was removed.\n";
                cout << "# State of Queue : ";
                cout << "[";
                for (int i = (front + 1) % 10; i < (::end + 1) % 10; i = (i + 1) % 10) {
                    if (i != ((::end + 1) % 10) - 1) {
                        cout << "'" << arrayList[i] << "', ";
                    }
                    else {
                        cout << "'" << arrayList[i] << "']\n\n\n";
                    }
                }
            }
        }
        else if (n == 3) {
            if (empty()) cout << "# Nothing to delete in queue.\n\n";
            else {
                cout << "# State of Queue : ";
                cout << "[";
                for (int i = (front + 1) % 10; i < (::end + 1) % 10; i = (i + 1) % 10) {
                    if (i != ((::end + 1) % 10) - 1) {
                        cout << "'" << arrayList[i] << "', ";
                    }
                    else {
                        cout << "'" << arrayList[i] << "']\n\n\n";
                    }
                }
            }   
        }
    } 
    return 0;
}
