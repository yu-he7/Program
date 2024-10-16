#include <iostream>

#define SIZE 10

using namespace std;


int front = 0;
int end = 0;
void Push(char arr[],char a) {
    arr[::end] = a;
    ::end = (::end + 1) % SIZE;
}
char Pop_(char arr[]) {
    char tmp = arr[front];
    front++;
    front = front % SIZE;
    return tmp;
}
int full() {
    if (front == (::end + 1) % SIZE) return 1;
    else return 0;
}
int empty() {
    if (::end == front) return 1;
    else return 0;
}

void print_queue(char arr[]) {
    int range = (SIZE + (::end - front)) % SIZE;
    cout << "f " << front << " e " << ::end << " range " << range << endl;
    cout << "# State of Queue : ";
    cout << "[";
   
    for (int i = front; i < range + front;) {
		if (i != range+front - 1) {
			cout << "'" << arr[i] << "', ";
		}
		else {
			cout << "'" << arr[i];
		}
        i++;
        i %= SIZE;
    }
    if (empty()) {
        cout << "]\n\n\n";
    }
    else {
        cout << "']\n\n\n";
    }

}

int main() {
    char arrayList[SIZE];
    int n = 0;
    while (n != 4) {
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
                Push(arrayList, str);
                cout << "#'" << str << "' is inserted.\n";
                print_queue(arrayList);
            }
        }
        else if (n == 2) {
            if (empty()) cout << "# Nothing to delete in queue.\n\n";
            else {
                cout << "# First item '" << Pop_(arrayList) << "' was removed.\n";
                print_queue(arrayList);
                

            }
        }
        else if (n == 3) {
            if (empty()) cout << "# Nothing to delete in queue.\n\n";
            else {
                print_queue(arrayList);
            }
        }
    }
    return 0;
}
