#include <iostream>
#include <fstream> // for file I/O

using namespace std; // for standard I/O

#define MAX 50 // define a constant

class Array {
    private:
        int data[MAX]; // data array
        int size = 0; // size of the array
    public:
        void insert (int datas);
        int erase ();
        void print ();
        void read (string filename);
};

void Array::insert (int datas) { // insert data into the array
    if (size < MAX) {
        data[size] = datas;
        size++;
    }
    else {
        cout << "Array is full" << endl;
    }
} // end of insert function

int Array::erase () { // erase data from the array
    int datas;
    if (size > 0) {
        datas = data[size - 1];
        size--;
    }
    else{
        cout << "Array is empty, cant delete the item" << endl;
        datas --;
    }
    return datas;
} // end of erase function

void Array::print () { // print the array
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
} // print the array

void Array::read (string filename) { // read the array from a file
    int n, num;

    ifstream myFile(filename);
    if(myFile.is_open()) {
        myFile >> n;
        for(int i = 0; i < n; i++) {
            myFile >> num;
            insert(num);
        }
        myFile.close();
    }
    else {
        cout << "Unable to open file" << endl;
    }
}

int main(){
    Array myArray; // create an object of class Array
    int data;

    myArray.read("input.txt");
    cout << "Read numbers: "<< endl;
    myArray.print();
    data = myArray.erase();
    cout << "Deleted number: " << data << endl;
    cout << "New array: " << endl;
    myArray.print();
    return 0;
}
