//COMSC-210-5068, Lab 18, Yang Liu
#include <iostream>
#include <cstring>
using namespace std;

struct ReviewNode {
    double rating;
    char comment[300];
    ReviewNode* next;
};

ReviewNode* addToHead(ReviewNode* head, double rating, const char* comment); 
ReviewNode* addToTail(ReviewNode* head, double rating, const char* comment); 
double printReviews(ReviewNode* head);                                       
void freeList(ReviewNode*& head);  

int main() {
    cout << "Which linked list method should we use?" << endl;
    cout << "    [1] New nodes are added at the head of the linked list" << endl;
    cout << "    [2] New nodes are added at the tail of the linked list" << endl;
    cout << "Choice: ";

    int choice;
    cin >> choice;
    cin.ignore();

    ReviewNode* head = nullptr;
    char addAnother;

    do {
        double rating;
        cout << "Enter review rating 0-5: ";
        cin >> rating;
        cin.ignore();

        char comment[300];
        cout << "Enter review comments: ";
        cin.getline(comment, sizeof(comment));

        if (choice == 1) {
            head = addToHead(head, rating, comment);
        } else {
            head = addToTail(head, rating, comment);
        }

        cout << "Enter another review? Y/N: ";
        cin >> addAnother;
        cin.ignore();
    } while (addAnother == 'y' || addAnother == 'Y');

    printReviews(head);
    freeList(head);

    return 0;
}

ReviewNode* addToHead(ReviewNode* head, double rating, const char* comment) {
    ReviewNode* newNode = new ReviewNode();
    newNode->rating = rating;
    strcpy(newNode->comment, comment);
    newNode->next = head;
    return newNode;
}

ReviewNode* addToTail(ReviewNode* head, double rating, const char* comment) {
    ReviewNode* newNode = new ReviewNode();
    newNode->rating = rating;
    strcpy(newNode->comment, comment);
    newNode->next = nullptr;

    if (head == nullptr) {
        return newNode;
    }

    ReviewNode* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

double printReviews(ReviewNode* head) {
    if (head == nullptr) {
        cout << "No reviews to output." << endl;
        return 0.0;
    }

    cout << "Outputting all reviews:" << endl;
    ReviewNode* current = head;
    int count = 0;
    double total = 0.0;

    while (current != nullptr) {
        count++;
        total += current->rating;
        cout << "    > Review #" << count << ": " << current->rating << ": " << current->comment << endl;
        current = current->next;
    }

    double average = total / count;
    cout << "    > Average: " << average << endl;
    return average;
}

void freeList(ReviewNode*& head) {
    ReviewNode* current = head;
    while (current != nullptr) {
        ReviewNode* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}