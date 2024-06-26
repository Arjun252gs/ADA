#include <iostream>
using namespace std;
const int MAX = 100;	// Constant definitions
class SubSet	// class definitions
{
	int stk[MAX], set[MAX];
	int size, top, count;
	public:
	SubSet() {
		top = -1;
		count = 0;
	}
	void getInfo(void);
	void push(int data);
	void pop(void);
	void display(void);
	int fnFindSubset(int pos, int sum);
};
void SubSet :: getInfo(void) {
	int i;
	cout << "Enter the number of elements : ";
	cin >> size;
	cout << "Enter the values of the elements (in ascending order) : \n";
	for (i=1; i<=size; i++)
	cin >> set[i];
}
void SubSet :: push(int data) {
	stk[++top] = data;
}
void SubSet :: pop(void) {
	top--;
}
void SubSet :: display() {
	int i;
	cout << "\nSOLUTION #"<< ++count <<" IS\n{ ";
	for (i=0; i<=top; i++)
		cout << stk[i] << " ";
	cout << "}" << endl;
}
int SubSet :: fnFindSubset(int pos, int sum) {
	int i;
	static int foundSoln = 0;
	if (sum>0) {
		for (i=pos; i<=size; i++) {
			push(set[i]);
			fnFindSubset(i+1, sum - set[i]);
			pop();
		}
	}
	if (sum == 0) {
		display();
		foundSoln = 1;
	}
	return foundSoln;
}
int main(void) {
	int sum;
	SubSet set1;
	set1.getInfo();
	cout << "Enter the sum value : ";
	cin >> sum;
	cout << endl;
	if (!set1.fnFindSubset(1, sum))
		cout << "\nThe problem instance doesnt have any solution." << endl;
	else
		cout << "\nThe above-mentioned sets are the required solution to the given instance." << endl;
	return 0;
}
