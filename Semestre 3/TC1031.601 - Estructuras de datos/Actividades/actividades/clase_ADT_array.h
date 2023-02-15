#include <iostream>
#include <fstream> // for file I/O
#include <chrono>
using namespace std::chrono;

using namespace std; // for standard I/O



#define MAX 50 // define a constant

class Array { // class Array
    private: 
        int data[MAX]; // data array
        int size  = 0; // size of the array
    public:
        void intercambio(int i, int j){ // swap two elements
            int aux = data[i];
            data[i] = data[j];
            data[j] = aux;
        }
        void insert (int datas) { // insert data into the array
            if (size < MAX) { 
                data[size] = datas; 
                size++;
            } 
            else {
                cout << "Array is full" << endl;
            }
        } // end of insert function
        int erase () { // erase data from the array
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

        void print () { // print the array
            for (int i = 0; i < size; i++) {
                cout << data[i] << " ";
            }
            cout << endl;
        } // print the array    
    
        void read (string filename) { // read the array from a file
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
        } // end of read function

        void selectionSort () { // selection sort algorithm
            int i, j, min;
            for (i = 0; i < size - 1; i++) {
                min = i;
                for (j = i + 1; j < size; j++) {
                    if (data[j] < data[min]) {
                        min = j;
                    }
                }
                intercambio(i, min);
            }
        } // end of selection sort algorithm

        void bubbleSort() { // bubble sort the array
            for (int i = 0; i < size-1; i++) {
                for (int j = 0; j < size-1; j++) {
                    if (data[j] > data[j+1]) {
                        intercambio(j, j+1);
                    }
                }
            }
        } // end of bubble sort function

        void bubbleSortBandera() { // bubble sort the array
            bool bandera;
            for (int i = 0; i < size-1; i++) {
                bandera = false;
                for (int j = 0; j < size-1; j++) {
                    if (data[j] > data[j+1]) {
                        bandera = true;
                        intercambio(j, j+1);
                    }
                }
                if (!bandera) {
                    cout << i << endl;
                    break;
                }
            }
        } // end of bubble sort function

        void insertionSort() { // insertion sort the array
            int i, j, aux;
            for (i = 1; i < size; i++) {
                aux = data[i];
                j = i;
                while (j > 0 && data[j-1] > aux) {
                    data[j] = data[j-1];
                    j--;
                }
                data[j] = aux;
            }
        } // end of insertion sort function
        void mergeSort(int low, int high) { // merge sort the array
            if (low < high) {
                int mid = (low + high) / 2;
                mergeSort(low, mid);
                mergeSort(mid + 1, high);
                merge(low, mid, high);
            }
        } // end of merge sort function

        void merge(int low, int mid, int high) { // merge the array
            int i, j, k;
            int n1 = mid - low + 1;
            int n2 = high - mid;
            int L[n1], R[n2];
            for (i = 0; i < n1; i++) {
                L[i] = data[low + i];
            }
            for (j = 0; j < n2; j++) {
                R[j] = data[mid + 1 + j];
            }
            i = 0;
            j = 0;
            k = low;
            while (i < n1 && j < n2) {
                if (L[i] <= R[j]) {
                    data[k] = L[i];
                    i++;
                }
                else {
                    data[k] = R[j];
                    j++;
                }
                k++;
            }
            while (i < n1) {
                data[k] = L[i];
                i++;
                k++;
            }
            while (j < n2) {
                data[k] = R[j];
                j++;
                k++;
            }
        } // end of merge function

        int particionar(int first, int last) {
            int pivot = data[first];
            int i = first + 1;
            for (int j=i; j <= last; j++) {
                if (data[j] < pivot) {
                    intercambio(i, j);
                    i++;
                }
            }
            intercambio(first, i-1);
            return i-1;
        }

        void quickSort(int first, int last) {
            if (first < last) {
                int pivot = particionar(first, last);
                quickSort(first, pivot-1);
                quickSort(pivot+1, last);
            }
        }

        int getSize() { // get the size of the array
            return size;
        } // end of getSize function

        int sequentialSearch(int key) { // sequential search
            int i = 0;
            while (i < size && data[i] != key) {
                i++;
            }
            if (i < size) {
                return i;
            }
            else {
                return -1;
            }
        } // end of sequential search

        int binarySearch(int key) { // binary search
            int low = 0;
            int high = size - 1;
            int mid;
            while (low <= high) {
                mid = (low + high) / 2;
                if (key == data[mid]) {
                    return mid;
                }
                else if (key < data[mid]) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            return -1;
        } // end of binary search
}; // end of class Array

