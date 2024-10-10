#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
    deque<int>scores;

    while(1) {
        cout << "1. show ranking & mean of scores" << "\n";
        cout << "2. Add scores" << "\n";
        cout << "3. Delete a score"  << "\n";
        cout << "4. Exit" << "\n";

        int choice;
        cout << "choice : ";
        cin >> choice;
        if(choice == 1) {
            double avg = 0;
            cout << "Score board" <<"\n" << "\n";
            cout << "=================" << "\n";
            for(int i = 0 ; i < scores.size(); i++) {
                avg += scores[i];
                cout << i+1 << "\t" << scores[i] << "\t" << "\n";
            }
            cout << "=================" << "\n";
            cout <<"Scores mean  :   " << avg / scores.size() << "\n";
        }
        else if(choice == 2) {
            while(1) {
                int num;
                cout <<"Enter score (0..100) (otherwise exit)" << "\n";
                cin >> num;
                if(num == -1) {
                    sort(scores.rbegin(),scores.rend());
                    break;
                }
                scores.push_back(num);
                cout << "[";
                for(int i = 0 ; i< scores.size(); i++) {
                    cout << scores[i];
                    if(i != scores.size()-1) {
                        cout << ", ";
                    }
                }
                cout << "]" << "\n";
            }
        }
        else if(choice == 3) {
            int delScore;
            cout << "Enter a score to delete : ";
            cin >> delScore;
            int index = -1;
            for(int i = 0 ; i < scores.size(); i++) {
                if(scores[i] == delScore) {
                    index = i;
                }
            }
            scores.erase(scores.begin()+index);
            if(index ==  -1) {
                cout << "\n"<< "Not Found!" << "\n" << "\n";
            }
        }
        else if(choice == 4) {
            break;
        }
    }
    return 0;
}
