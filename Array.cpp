#include <iostream>

class Array
{
private:
    int *A; // Dynamically creating an array instead of a static one.
    int size; // size of the array
    int capacity; // Actual capacity of the array 
    void swap(int *a, int *b);
public:
    Array();
    Array(int capacity);
    void display();
    void append(int data);
    void insert(int index, int data);
    int remove(int index);
    int search(int key);
    int get(int index);
    void set(int index, int data);
    int maximum();
    int minimum();
    void reverse();
    Array Union(Array &arr);
    Array Intersection(Array &arr);
    Array Difference(Array &arr);
    ~Array();
};

Array::Array(){
    capacity = 20;
    size = 0;
    A = new int[capacity];
}

Array::Array(int capacity)
{
    this->capacity = capacity;
    size = 0;
    A = new int[capacity];
}

void Array::display(){
    for(int i = 0; i < size; i++){
        std::cout<<A[i]<<" ";
    }
    std::cout<<std::endl;
}

void Array::append(int data){
    if(size < capacity){
        A[size++] = data;
    }else{
        std::cout<<"Overflow "<<std::endl;
    }
}

void Array::insert(int index, int data){
    if(index >= 0 && index <= size){
        for (int i = size; i > index; i--)
        {
            A[i] = A[i - 1];
        }
        A[index] = data;
        size++;
    }else{
        std::cout<<"Index out of bounds !!! " << std::endl;
    }
}

int Array::remove(int index){
    if(index >= 0 && index < size){
        int rm = A[index];
        for (int i = index; i < size - 1; i++)
        {
            A[i] = A[i + 1];
        }
        size--;
        return rm;
    }
    return -1;
}

int Array::search(int key){
    int low = 0, high = size - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if(A[mid] == key){
            return mid;
        }else if(A[mid < key]){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return -1;
}

int Array::get(int index){
    if(index >= 0 && index < size){
        return A[index];
    }
    return -1;
}

void Array::set(int index, int data){
    if(index >= 0 && index < size){
        A[index] = data;
    }
}

int Array::maximum(){
    int maxx = A[0];
    for(int i = 1; i < size; i++){
        if(A[i] > maxx){
            maxx = A[i];
        }
    }
    return maxx;
}

int Array::minimum(){
    int minn = A[0];
    for(int i = 1; i < size; i++){
        if(A[i] < minn){
            minn = A[i];
        }
    }
    return minn;
}

void Array::swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Array::reverse(){
    int i = 0, j = size - 1;
    while (i < j)
    {
        swap(&A[i], &A[j]);
        i++;
        j--;
    }
}

Array Array::Union(Array &arr){
    int i = 0, j = 0, k = 0;
    Array arrUnion = Array(size + arr.size);

    while (i < size && j < arr.size)
    {
        if(A[i] < arr.A[j]){
            arrUnion.A[k++] = A[i++];
        }else if(arr.A[j] < A[i]){
            arrUnion.A[k++] = arr.A[j++];
        }else{
            arrUnion.A[k++] = A[i++];
            j++;
        }
    }

    while (i < size)
    {
        arrUnion.A[k++] = A[i++];
    }
    
    while (j < arr.size)
    {
        arrUnion.A[k++] = arr.A[j++];
    }
    arrUnion.size = k;
    return arrUnion;
}

Array Array::Intersection(Array &arr){
    int i = 0, j = 0, k = 0;
    Array arrInter = Array(size + arr.size);

    while (i < size && j < arr.size)
    {
        if(A[i] < arr.A[j]){
            i++;
        }else if(arr.A[j] < A[i]){
            j++;
        }else{
            arrInter.A[k++] = A[i++];
            j++;
        }
    }

    arrInter.size = k;
    return arrInter;
}

Array Array::Difference(Array &arr){
    int i = 0, j = 0, k = 0;
    Array arrDiff = Array(size + arr.size);

    while (i < size && j < arr.size)
    {
        if(A[i] < arr.A[j]){
            arrDiff.A[k++] = A[i++];
        }else if(arr.A[j] < A[i]){
            j++;
        }else{
            i++;
            j++;
        }
    }

    while (i < size)
    {
        arrDiff.A[k++] = A[i++];
    }
    

    arrDiff.size = k;
    return arrDiff;
}


Array::~Array()
{
    delete []A;
}

int main(){
    int cap; // capacity of an array
    std::cout << "Please enter the capacity of the array "<<std::endl;
    std::cin >> cap;
    Array *arr = new Array(cap); // An array is created dynamically

    // Insert some elements
    arr->insert(0, 2);
    arr->insert(1, 3);
    arr->insert(2, 5);
    arr->insert(3, 6);
    arr->insert(4, 7);

    // Display Elements of the array
    arr->display();

    // Delete an element at an index
    int idx;
    std::cout << "Enter the index to be removed " << std::endl;
    std::cin >> idx; 
    arr->remove(idx);
    arr->display();

    // Search for an element
    int ele_idx = arr->search(6);
    std::cout << "Element found at index: " << ele_idx << std::endl;

    // Append an element
    arr->append(9);
    arr->display();

    Array arr2 = Array(); 

    // Insert some elements
    arr2.insert(0, 3);
    arr2.insert(1, 5);
    arr2.insert(2, 6);
    arr2.insert(3, 7);
    arr2.insert(4, 8);

    arr2.display();

    // Union of Arrays
    Array arr3 = arr->Union(arr2);
    arr3.display();

    // Intersection of arrays
    Array arr4 = arr->Intersection(arr2);
    arr4.display();

    // Difference of arrays
    Array arr5 = arr->Difference(arr2);
    arr5.display();
}