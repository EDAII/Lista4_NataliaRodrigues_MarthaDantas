#include <iostream>
#include <vector>
#include <algorithm>

#define COUNT 5

using namespace std;

vector<int> v;
int n;

int parent(int i) {
	return i/2;
}

int left(int i) {
	return 2*i;
}

int right(int i) {
	return (2*i) + 1;
}

void generate_vector() {	
	for(int i = 0; i <= n; i++)
		v.push_back(i);
		
	random_shuffle(++v.begin(), v.end());
}

void print_tree(int root, int space){ 
    if (root > n)  
        return;  
  
    space += COUNT;  
  
    print_tree(right(root), space);  
    
    cout<<endl;  
    for (int i = COUNT; i < space; i++)  
        cout<<" ";  
    cout << v[root] << "\n";  
  
    print_tree(left(root), space);
}

void print_vector() {
	cout << "\n";
	for(int i = 1; i <= n; i++)
		cout << v[i] << " ";
	cout << "\n";
}

void swap(int i, int j) {
	int tmp = v[i];
	v[i] = v[j];
	v[j] = tmp;
}

void heapify(int i, int size) {
	int largest;
	
	int l = left(i);
	int r = right(i);
	
	if(l <= size && v[l] > v[i])
		largest = l;
	else
		largest = i;
	
	if(r <= size && v[r] > v[largest])
		largest = r;
		
	if(largest != i) {
		swap(i, largest);	
		heapify(largest, size);
	}
}

void build_heap() {
	for(int i = n/2; i > 0; i--)
		heapify(i, n);
}

void heap_sort() {
	int size = n;
	build_heap();
	
	print_vector();
	
	for(int i = n; i > 1; --i) {
		swap(1, i);
		size--;
		heapify(1, size);		
	}
}

int main() {
	
	cout << "\nInsira o tamanho do vetor: ";
	cin >> n;
	
	generate_vector();
	cout << "\nVetor Desordenado:"
	print_vector();
	//print_tree(1, 0);
	
	heap_sort();
	print_vector();
	//print_tree(1, 0);
	
	return 0;
}
