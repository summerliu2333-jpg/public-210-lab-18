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