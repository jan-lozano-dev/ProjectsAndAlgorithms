#include <iostream>
#include <list>
#include <cstring>
using namespace std;

//Hashtable to implement 905, Jimmy

class HashTable{
    private:
        static const int hashGroups = 10; //hashtable size
        list<pair<int, string>> table[hashGroups]; //List1, Index 0; List 2, Index 2
    public:
        bool isEmpty() const;
        int hashFunction(int key);
        void insertItem(int key, string value);
        void removeItem(int key);
        string searchTable(int key);
        void printTable();
};

bool HashTable::isEmpty() const {
    int sum{};
    for(int i{}; i < hashGroups; i++){
        sum += table[i].size();
    }

    if(!sum) {
        return true;
    }
    return false;
}

int HashTable::hashFunction(int key){
    return key % hashGroups; //905, in return, function returns 5 as in 6th bucket (0 based hashtable)
}

void HashTable::insertItem(int key, string value) {
    int hashValue = hashFunction(key);   //gets hash table bucket with hashfunction!
    auto& cell = table[hashValue];       //reference to bucket [hashvalue]  
    auto bltr = begin(cell);             //we have to iterate through list to check if key exists
    bool keyExists = false;
    for(; bltr != end(cell); bltr++){
        if(bltr->first == key){
            keyExists = true;
            bltr->second = value;
            cout << "[WARNING] Key exists. Value replaced." << endl;
            break;
        }
    }

    if(!keyExists) {
        cell.emplace_back(key, value);
    }

    //auto copies the table data type cause we are referencing to the table(bucket) with index 5
    //cell is the name of this reference.
    //now cell (reference of the bucket 5) can modify the bucket 5 without copying it.
    

    return;
}

void HashTable::removeItem(int key) {
    int hashValue = hashFunction(key);   //gets hash table bucket with hashfunction!
    auto& cell = table[hashValue];       //reference to bucket [hashvalue]  
    auto bltr = begin(cell);             //we have to iterate through list to check if key exists
    bool keyExists = false;
    for(; bltr != end(cell); bltr++){
        if(bltr->first == key){
            keyExists = true;
            bltr = cell.erase(bltr);
            cout << "[INFO] Item removed." << endl;
            break;
        }
    }

    if(!keyExists) {
        cout << "[WARNING] Key not found. Pair not removed.";
    }

    return;
}

void HashTable::printTable() {
    for(int i{}; i < hashGroups; i++) {
        if(table[i].size() == 0) continue;
        auto bltr = table[i].begin();
        
        for(; bltr != table[i].end(); bltr++) {
            cout << "[INFO] Key: " << bltr->first << " Value: " << bltr->second << endl;
        }

        
    }

    return;

}

int main(){
    HashTable HT;

    if(HT.isEmpty()){
        cout << "Correct answer. Good job." << endl;
    } else {
        cout << "Oh oh. We need to check out code!" << endl;
    }

    HT.insertItem(905, "Jim");
    HT.insertItem(201, "Tom");
    HT.insertItem(332, "Bob");
    HT.insertItem(124, "Sally");
    HT.insertItem(107, "Barb");
    HT.insertItem(929, "Rob");
    HT.insertItem(928, "Bob");
    HT.insertItem(928, "Rick");

    HT.printTable();

    HT.removeItem(332);
    HT.removeItem(100);

    if(HT.isEmpty()) {
        cout << "Oh oh. We need to check out code!"<< endl;
    } else {
        cout <<  "Correct answer. Good job." << endl;
    }

    return 0;

}