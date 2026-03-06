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