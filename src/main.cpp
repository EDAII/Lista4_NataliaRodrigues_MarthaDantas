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

int log2(int a) {
	int i = 1;

	while(a / 2 != 0) {
		a = a/2;
		i++;
	}

	return i;
}

void print_tree(int size) {
	int space = log2(size) * 8;
	int level = 0;
	int elements;
	int pos;

	for(int i = 1; i <= size; i++) {

		if(log2(i) > level) {
			cout << endl;
			level++;
			space /= 2;
			pos = space;
		}

		for(int j = 0; j < space; j++)
			cout << " ";

		cout << v.at(i);

		if(level == log2(size))
			pos = space/2;

		for(int j = 0; j < pos; j++)
			cout << " ";
	}

	cout << endl;
}

void print_vector(int size) {
	for(int i = 1; i <= size; i++)
		cout << v[i] << " ";
	cout << "\n";
}

void print(int op, int size) {
	if(op == VECTOR){
		cout << "\n";	
		print_vector(size);
	}
	else
		print_tree(size);
}

void print_ordened_vector(int pos) {
	cout << "Ordened vector: ";
	for(int i = 1; i <= n; i++) {
		if(i < pos)
			cout << " _ ";
		else
			cout << " " << v.at(i) << " ";
	}
}

void swap(int i, int j) {
	int tmp = v[i];
	v[i] = v[j];
	v[j] = tmp;
}

void heapify(int i, int size, int op) {
	cout << "\nHeapify(" << v.at(i) << "):\n";
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
		cout << "\n* swap " << v.at(i) << " with " << v.at(largest) << " *\n";
		print(op, size);
		heapify(largest, size, op);
	}
	else {
		cout << "\n* no swap *\n"; 
		print(op, size);
	}
}

void build_heap(int op) {
	for(int i = n/2; i > 0; i--) {
		system("read -p '\nPress Enter to continue...' var");
		heapify(i, n, op);
	}
}

void heap_sort(int op) {
	int size = n;
	
	cout << "\t\t\t BUILD HEAP: ";
	print(op, n);
	build_heap(op);
	cout << "\n=======================================================\n";
	
	cout << "\t\t\t HEAP SORT: ";
	for(int i = n; i > 1; --i) {
		system("read -p '\nPress Enter to continue...' var");
		cout << "\n\nRemoving " << v.at(1) << endl;
		swap(1, i);
		print_ordened_vector(i);
		size--;
		cout << endl;
		print(op, size);
		system("read -p '\nPress Enter to continue...' var");
		cout << "\n\nRearranging structure to be a heap with heapify:\n";
		heapify(1, size, op);	
	}

	system("read -p '\nPress Enter to continue...' var");
	cout << "\n\nRemoving " << v.at(1) << endl;
	print_ordened_vector(1);

	cout << "\n=======================================================\n";
}

void menu() {
	int option;
	
	cout << "\n1 - Ver passos do heap sort no vetor;\n";
	cout << "\n2 - Ver passos do heap sort na arvore;\n";
	cout << "\nDigite sua opcao: ";
	    
	cin >> option;

	cout << "\n=======================================================\n";
	cout << "\nVetor Desordenado: ";
	print_vector(n);
	cout << "\n=======================================================\n";

	system("read -p '\nPress Enter to continue...\n' var");

	heap_sort(option);
}

int main() {
	
	cout << "\nInsira o tamanho do vetor: ";
	cin >> n;
	
	generate_vector();
	menu();
	
	return 0;
}
