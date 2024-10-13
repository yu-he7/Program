
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> deokList;
vector<string> orderList;

void Print() {
    cout << "[";
    for (int i = 0; i < orderList.size(); i++) {
        if (i == orderList.size() - 1) {
            cout << orderList[i] << "]\n";
        }
        else {
            cout << orderList[i] << ", ";
        }
    }
}
void Order(string order) {
    int check = 0;
    for (int i = 0; i < 10; i++) {
        if (order == deokList[i]) {
            check = 1;
            break;
        }
    }
    
    if (check = 1) {
        orderList.push_back(order);
        Print();
    }
    else {
        cout << "죄송합니다. 이름이 " << order << "인 떡은 없습니다.\n";
    }
}
void Cancel(int num) {
    string order = orderList[num];
    for (int i = num; i < orderList.size(); i++) {
        if (i + 1 >= orderList.size()) {
            break;
        }
        string tmp;
        tmp = orderList[i];
        orderList[i] = orderList[i + 1];
        orderList[i + 1] = tmp;
    }
    orderList.pop_back();
    cout << num+1 << "번째 떡인 " << order << "이 주문 취소 되었습니다.\n";
}

int main()
{
    deokList.push_back("가래떡");
    deokList.push_back("시루떡");
    deokList.push_back("백설기");
    deokList.push_back("송편");
    deokList.push_back("꿀떡");
    deokList.push_back("찹쌀떡");
    deokList.push_back("쑥떡");
    deokList.push_back("술떡");
    deokList.push_back("무지개떡");
    deokList.push_back("바람떡");
    int n = 0;
    while (n != 4) {
        cout << "---------- 떡대감 ----------\n";
        cout << "1. 떡 주문\n";
        cout << "2. 떡 주문취소\n";
        cout << "3. 떡 주문리스트 조회\n";
        cout << "4. 종료\n";
        cin >> n;
        if (n == 1) {
            string order;
            cout << "[";
            for (int i = 0; i < 10; i++) {
                if (i == 9) {
                    cout << deokList[i] << "]";
                }
                else {
                    cout << deokList[i] << ", ";
                }

            }
            cout << "주문 하실 떡을 입력주세요\n";
            cin >> order;
            Order(order);
        }
        else if (n == 2) {
            int num;
            if (orderList.empty()) {
                cout << "취소할 떡이 없습니다.\n";
            }
            else {
                Print();
                cout << "취소 하실 떡의 순서를 입력 해주세요. \n";
                cin >> num;
                Cancel(num - 1);
            }
        }
        else if (n == 3) {
            if (orderList.empty()) {
                cout << "주문한 떡이 없습니다.\n";
            }
            else {
                Print();
            }
        }
    }
}
