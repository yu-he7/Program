#include <iostream>

using namespace std;

typedef struct Cafe {
    string name;
    double score;
    int count;
    double sum;
}Cafe;

int hash_(string store) {
    int hash = 0;
    int len = store.length();
    for (char c : store) {
        hash += c ^ len;
        len--;
    }
    return hash % 23;
}

double avg(int idx, Cafe list[]) {
    return list[idx].sum / list[idx].count;
}

int equals(Cafe list[], int hash) {
    if (list[hash].count > 0) {
        return 1;
    }
    return 0;
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
    Cafe  a[23];
    for (int i = 0; i < 23; i++) {
        a[i].count = 0;
    }
    while (n != 5) {
        print();
        cin >> n;
        if (n == 1) {
            cout << "\nCafe Review\n";
            cout << "store   Grade\n";
            cout << "==============\n";
            for (int i = 0; i < 23; i++) {
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
            int hash = hash_(store);
            if (equals(a,hash)) {
                cout << "Grade (1..5) : \n";
                double grade;
                cin >> grade;
                a[hash].count++;
                a[hash].sum += grade;
                a[hash].score = avg(hash, a);
            }
            else {
                a[hash].count++;
                a[hash].name = store;
                cout << "Grade (1..5) : \n";
                double grade;
                cin >> grade;
                a[hash].score = grade;
                a[hash].sum = grade;
            }
        }
        else if (n == 3) {
            cout << "Delete store : \n";
            string store;
            cin >> store;
            int hash = hash_(store);
            a[hash].name = "";
            a[hash].score = 0;
            a[hash].count = 0;
            a[hash].sum = 0;
            cout << "Delete is completed.\n\n";
        }
        else if (n == 4) {
            cout << "Search store : ";
            string store;
            cin >> store;
            int hash = hash_(store);
            cout << a[hash].name << "  :  ";
            printf("%.1f\n\n", a[hash].score);
        }
    }
    return 0;
}
