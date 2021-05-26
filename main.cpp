#include <iostream>

using namespace std;

class Element{
public:
    char Data;
    Element *Next;
    Element(char data){
        Data = data;
        Next = nullptr;
    }

};

class Listt{
private:
    Element *_head;
    Element *_tail;

public:
    Listt(){
        _head = nullptr;
        _tail = nullptr;
    }

    void Add(char data){
        Element* add = new Element(data);

        if (_head == nullptr){
            _head = add;
            _tail = _head;
        }
        else{
            _tail->Next = add;
            _tail = _tail->Next;
        }
    }

    void RemoveAfter(int index){
        Element* current = _head;
        for (int i = 0; i < index; ++i) {
            current = current->Next;
        }

        _tail = current;
        _tail->Next = nullptr;
    }

    int FindCount(char symbol){
        Element* current = _head;
        int count = 0;
        while ( current != NULL){
            if (current->Data == symbol){
                count++;
            }
        current = current->Next;
        }
        return count;
    }

    void ListOut(){
        Element* current = _head;
        while ( current != NULL) {
            cout << current->Data;
            current = current->Next;
        }
        cout << endl;
    }
};

int main() {
    Listt naming;
    naming.Add('o');
    naming.Add('n');
    naming.Add('e');
    naming.Add(',');
    naming.Add(' ');
    naming.Add('t');
    naming.Add('w');
    naming.Add('o');
    naming.Add(',');
    naming.ListOut();
    cout << naming.FindCount('o')<<endl;
    naming.RemoveAfter(3);
    naming.ListOut();
}
