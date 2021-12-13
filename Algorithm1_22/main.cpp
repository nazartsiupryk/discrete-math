#include <iostream>

using namespace std;

int main() {
    int number;
    cout << "Enter number 'n': " << endl;
    cin >> number;

    int uniqueSummands[number + 1];
    int numberOfUniqueSummand[number + 1];
    int numberOfPartitions;

    uniqueSummands[1] = number;
    numberOfUniqueSummand[1] = 1;
    numberOfPartitions = 1;

    cout << "Partitions:" << endl;
    for (int element = 1; element <= numberOfPartitions; element++) {
        for (int repeatingNumber = 1; repeatingNumber <= numberOfUniqueSummand[element]; repeatingNumber++) {
            cout << uniqueSummands[element] << " ";
        }
    }
    cout << endl;

    while (uniqueSummands[1] > 1) {
        int sum = 0;
        if (uniqueSummands[numberOfPartitions] == 1) {
            sum += numberOfUniqueSummand[numberOfPartitions];
            numberOfPartitions--;
        }
        sum += uniqueSummands[numberOfPartitions];
        numberOfUniqueSummand[numberOfPartitions]--;
        int summand = uniqueSummands[numberOfPartitions] - 1;
        if (numberOfUniqueSummand[numberOfPartitions] > 0) {
            numberOfPartitions++;
        }
        uniqueSummands[numberOfPartitions] = summand;
        numberOfUniqueSummand[numberOfPartitions] = sum / summand;
        summand = sum % summand;
        if (summand != 0) {
            numberOfPartitions++;
            uniqueSummands[numberOfPartitions] = summand;
            numberOfUniqueSummand[numberOfPartitions] = 1;
        }

        for (int element = 1; element <= numberOfPartitions; element++) {
            for (int repeatingNumber = 1; repeatingNumber <= numberOfUniqueSummand[element]; repeatingNumber++) {
                cout << uniqueSummands[element] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
