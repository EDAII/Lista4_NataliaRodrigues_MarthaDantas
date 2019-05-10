#include <iostream>
#include <vector>
#include <algorithm>

#define COUNT 5
#define VECTOR 1
#define TREE 2

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

void print_vector(int size) {
	cout << "\n";
	for(int i = 1; i <= size; i++)
		cout << v[i] << " ";
	cout << "\n";
}

void swap(int i, int j) {
	int tmp = v[i];
	v[i] = v[j];
	v[j] = tmp;
}

void print(int op, int size) {
	if(op == VECTOR)
		print_vector(size);
	else
		print_tree(1, 0);
}

void heapify(int i, int size, int op) {
	cout << "\nHeapify(" << v.at(i) << "):\n"
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
		print(op, size);
		heapify(largest, size, op);
	}
	else {
		print(op, size);
	}
}

void build_heap(int op) {
	for(int i = n/2; i > 0; i--)
		heapify(i, n, op);
}

void heap_sort(int op) {
	int size = n;
	
	cout << "\n=======================================================\n";
	cout << "\t\t\tBUILD HEAP: ";
	build_heap(op);
	cout << "\n=======================================================\n";
	
	cout << "\t\t\t HEAP SORT: ";
	for(int i = n; i > 1; --i) {
		cout << "\n\nRemoving " << v.at(1) << endl;
		swap(1, i);
		size--;
		print(op, size);
		print_ordened_vector(i);
		cout << "\nRearranging tree to be a heap with heapify:\n";
		heapify(1, size, op);		
	}
	cout << "\n=======================================================\n";
}

void menu() {
	int option;
	
	cout << "\n1 - Ver passos do heap sort no vetor;\n";
	cout << "\n2 - Ver passos do heap sort na arvore;\n";
	
	cin >> option;

	if(option == VECTOR) cout << "\nVetor: ";
	else cout << "\nArvore: ";
	print(option, n);
	
	heap_sort(option);
}

int main() {
	
	cout << "\nInsira o tamanho do vetor: ";
	cin >> n;
	
	generate_vector();
	menu();
	
	return 0;
}
