#include <iostream>

using namespace std;

typedef struct Cafe {
    string name;
    double score;
    int count;
    double sum;
}Cafe;

double avg(int idx, Cafe list[]) {
    return list[idx].sum / list[idx].count;
}

int equals(Cafe list[], string name) {
    for (int i = 0; i < 10; i++) {
        if (list[i].name == name) {
            return i;
        }
    }
    return -1;
}

void print() {
    cout << "1.Show all reviews\n";
    cout << "2. Add cafe reviews\n";
    cout << "3.Delete cafe review\n";
    cout << "4.Search cafe\n";
    cout << "5. Exit\n";
    cout << "menu : ";
}

int main() {
    int n = 0;
    Cafe  a[10]; 
    for (int i = 0; i < 10; i++) {
        a[i].count = 0;
    }
    int cnt = 0;
    while (n != 5) {
        print();
        cin >> n;
        if (n == 1) {
            cout << "\nCafe Review\n";
            cout << "store   Grade\n";
            cout << "==============\n";
            for (int i = 0; i < 10; i++) {
                if (a[i].name != "") {
                    cout << a[i].name << "        ";
                    printf("%.1f\n", a[i].score);
                }
            }
            cout << "==============\n";
        }
        else if (n == 2) {
            string store;
            cout << "Add store : \n";
            cin >> store;
            int index = equals(a, store);
            if (index != -1) {
                cout << "Grade (1..5) : \n";
                double grade;
                cin >> grade;
                a[index].count++;
                a[index].sum += grade;
                a[index].score = avg(index, a);
            }
            else {
                a[cnt].count++;
                a[cnt].name = store;
                cout << "Grade (1..5) : \n";
                double grade;
                cin >> grade;
                a[cnt].score = grade;
                a[cnt].sum = grade;
            }
            cnt++;
        }
        else if (n == 3) {
            cout << "Delete store : \n";
            string store;
            cin >> store;
            for (int i = 0; i < 10;i++) {
                if (a[i].name == store) {
                    a[i].name = "";
                    a[i].score = 0;
                    a[i].count = 0;
                    a[i].sum = 0;
                    cout << "Delete is completed.\n\n";
                }
            }
        }
        else if (n == 4) {
            cout << "Search store : ";
            string store;
            cin >> store;
            for (int i = 0; i < 10;i++) {
                if (a[i].name == store) cout<< a[i].name << "  :  " << a[i].score;
            }
            cout << "\n\n";
        }
    }
    return 0;
}
