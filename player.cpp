#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    string data;
    Node* next;
    Node* prev;
};

Node* head = NULL;
Node* curr = NULL;

//INSERT A NODE
void insert(){
    cout<<"Enter the Title of Video to be uploaded"<<endl;
    getline(cin, curr->data);

    Node* added = curr;  //added is node which is just inserted
    if(head == NULL){
        head = curr = added;
        head->next = head->prev = added;
        return;
    }
    Node* last = head->prev;
    added->prev = last;
    last->next = added;
    head->prev = added;
    added->next = head;

}

//DELETE A NODE

void delete_Node(){
    cout<<"Enter the Title of video to be deleted"<<endl;
    string temp ;
    getline(cin,temp);

    Node* ele = head;
    //if library has only one video
    do {
        if (ele->next == ele && ele->data == temp) {
            cout << "One file deleted! Playlist is Empty Now!\n";
            head = nullptr;
            delete ele;
            return;
        } else if (ele->data == temp) {
            Node* prev = ele->prev;
            Node* next = ele->next;
            prev->next = next;
            next->prev = prev;
            if (ele == curr) {
                curr = next; // Update current_node if deleting current song
            }
            head = next;
            delete ele;
            cout << "Music deleted!\n";
            return;
        }
        ele = ele->next;
    } while (ele != head);
    
    cout<<"No video of this name is present is there"<<endl;
}

void show(){
    if(head == NULL){
        cout<<"Library is empty"<<endl;
        return ;
    }
    int i=0;
    Node* show_ele = head;
    do{
        cout<<i<<" "<<show_ele->data<<endl;
        show_ele = show_ele->next;
        i++;

    }while(show_ele != head);
}

void next_ele(){
    if(head == NULL){
        cout<<"library is empty"<<endl;
        return;
    }
    Node* nextNode = curr->next;
    if(nextNode != head){
        cout<<"Next Video is "<<nextNode->data<<endl;
    }
    else{
        cout<<"You have reached at last video of library"<<endl;
    }

}

void prev_node() {
    if (curr == NULL) {
        cout << "No video in library!\n";
        return;
    } else {
        curr = curr->prev;
        if (curr != NULL) { // Check if not reaching the beginning
            cout << "Previous video is : " << curr->data << endl;
        } else {
            cout << "Reached the beginning of the library\n";
        }
    }
}

void first_node() {
    if (head == nullptr) {
        cout << "library is Empty!\n";
    } else {
        curr = head;
        cout << "Playing First video : " << curr->data << endl;
    }
}

void last_node() {
    if (head == nullptr) {
        cout << "library is Empty!\n";
    } else {
        curr = head->prev;
        cout << "Playing Last video : " << curr->data << endl;
    }
}

void specific_data() {
    if (head == nullptr) {
        cout << "No music is there to be searched!\n";
        return;
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
