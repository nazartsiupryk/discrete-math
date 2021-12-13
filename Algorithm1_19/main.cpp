#include <iostream>
#include <string>

using namespace std;

void printPartitionUsingBlock(const int block[], int length);
ostream& operator<<(ostream& os, const int numbers[]);
int maxNumberInArray(const int array[], int firstIndex, int lastIndex);

// for overloading <<
int arrayOfNumbersLength;

int main() {
    int maxNumber;
    cout << "Enter number 'n' of {1,2,..n}: " << endl;
    cin >> maxNumber;

    int block[maxNumber + 1];
    int previousBlock[maxNumber + 1];
    int nextBlock[maxNumber + 1];
    bool forward[maxNumber + 1];
    int activeElement;

    for (int number = 1; number <= maxNumber; number++) {
        block[number] = 1;
        forward[number] = true;
    }
    nextBlock[1] = 0;

    cout << "\nPartitions: " << endl;
    printPartitionUsingBlock(block, maxNumber + 1);

    activeElement = maxNumber;
    while (activeElement > 1) {
        int numberOfActiveElementBlock = block[activeElement];
        if (forward[activeElement]) {
            if (nextBlock[numberOfActiveElementBlock] == 0) {
                nextBlock[numberOfActiveElementBlock] = activeElement;
                previousBlock[activeElement] = numberOfActiveElementBlock;
                nextBlock[activeElement] = 0;
            }
            if (nextBlock[numberOfActiveElementBlock] > activeElement) {
                previousBlock[activeElement] = numberOfActiveElementBlock;
                nextBlock[activeElement] = nextBlock[numberOfActiveElementBlock];
                previousBlock[nextBlock[activeElement]] = activeElement;
                nextBlock[numberOfActiveElementBlock] = activeElement;
            }
            block[activeElement] = nextBlock[numberOfActiveElementBlock];
        } else {
            block[activeElement] = previousBlock[numberOfActiveElementBlock];
            if (numberOfActiveElementBlock == activeElement) {
                if (nextBlock[numberOfActiveElementBlock] == 0) {
                    nextBlock[previousBlock[numberOfActiveElementBlock]] = 0;
                } else {
                    nextBlock[previousBlock[numberOfActiveElementBlock]] = nextBlock[numberOfActiveElementBlock];
                    previousBlock[nextBlock[numberOfActiveElementBlock]] = previousBlock[numberOfActiveElementBlock];
                }
            }
        }
        printPartitionUsingBlock(block, maxNumber + 1);
        activeElement = maxNumber;
        while (activeElement > 1 && ((forward[activeElement] && block[activeElement] == activeElement)
                         || (!forward[activeElement] && block[activeElement] == 1))) {
            forward[activeElement] = !forward[activeElement];
            activeElement--;
        }
    }

    return 0;
}

void printPartitionUsingBlock(const int block[], int length) {
    int numberOfBlock;
    int thisBlock;
    int maxBlock = maxNumberInArray(block, 0, length - 1);

    for (thisBlock = 1; thisBlock <= maxBlock; thisBlock++) {
        int numbers[length];
        int index = -1;

        for (int number = 1; number < length; number++) {
            numberOfBlock = block[number];
            if (numberOfBlock == thisBlock) {
                numbers[++index] = number;
            }
        }

        arrayOfNumbersLength = index + 1;
        cout << numbers;
    }
    cout << endl;
}

ostream& operator<<(ostream& os, const int numbers[]) {
    os << "";
    if (arrayOfNumbersLength == 0) {
        return os;
    }

    os << "( ";
    for (int numberIndex = 0; numberIndex < arrayOfNumbersLength; numberIndex++) {
        os << numbers[numberIndex] << " ";
    }
    os << ")";

    return os;
}

int maxNumberInArray(const int array[], int firstIndex, int lastIndex) {
    int highNumber = array[firstIndex];

    for (int index = firstIndex + 1; index <= lastIndex; index++) {
        if (array[index] > highNumber)
            highNumber = array[index];
    }

    return highNumber;
}
