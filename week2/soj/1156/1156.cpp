#include <iostream>
#include <set>
using namespace std;
struct Node {
		int id;
		char letter;
		int lb;  // left branch
		int rb;	// right branch
		int pre;	// parent node id
		bool visited;
		
		Node () {
		}
		
		Node(int _id, char _letter, int _lb, int _rb, int _pre = 0) {
				id = _id;
				letter = _letter;
				lb = _lb;
				rb = _rb;
				pre = _pre;
		}
};

Node *nodes; 
int n;

void printFrom(int cur) {
		Node &curNode = nodes[cur];
		cout << curNode.letter;
		if (curNode.lb == 0 && curNode.rb == 0) {
				return;
		}
		if (curNode.lb != 0) {
				printFrom(curNode.lb);
		}
		if (curNode.rb != 0) {
				printFrom(curNode.rb);
		}
}


int main() {
		while (cin >> n) {
				int root;
				set<int> ids;
				set<int> not_roots;
				nodes = new Node[1005];
				for (int i = 0; i < n; i++) {
						int id, lb, rb;
						char letter;
						cin >> id >> letter >> lb >> rb;
						ids.insert(id);
						if (lb != 0) {
								not_roots.insert(lb);
						}
						if (rb != 0) {
								not_roots.insert(rb);
						}
						nodes[id] = Node(id, letter, lb, rb);
						//cout << nodes[id].id << endl;
				}
				
				for (set<int>::iterator it = ids.begin(); it != ids.end(); it++) {
						if (not_roots.find(*it) == not_roots.end()) {
								root = *it;
								break;
						}
				}
				
				printFrom(root);
				cout << endl;
		}
}