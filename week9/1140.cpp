#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int gold;
	int id;
	int idSum;
	vector<Node*> sub;
	
	Node() {
		gold = 1; // itself
		idSum = 0;	// invalid
		id = 0;	//invalid
	}
};

int n, k;
Node *nodes;
int limit;
int cut_id = 0;

bool isLeaf(Node* node) {
		return node->sub.empty();
}

void countSubGold(Node *root) {
	//后序遍历
	if ( isLeaf(root) ) {	// leaf
		return;
	} else {
		for (vector<Node*>::iterator it = root->sub.begin(); it != root->sub.end(); it++) {
			countSubGold(*it);
			root->gold += (*it)->gold;
			root->idSum += (*it)->idSum;
		}
	}
}

void greedyChoose(Node *root) {
		if ( isLeaf(root) ) {
				return;
		} else {
				for (vector<Node*>::iterator it = root->sub.begin(); it != root->sub.end(); it++) {
						if ((*it)->gold <= limit) {
								if (!cut_id || ((*it)->gold > nodes[cut_id].gold) || ((*it)->gold == nodes[cut_id].gold && (*it)->idSum < nodes[cut_id].idSum)) {
										cut_id = (*it)->id;
								}
								continue;
						} else {
								greedyChoose(*it);
						}
				}
		}
}

void cut(Node *root, int id) {
	if ( isLeaf(root) ) {
			return;
	} else {
			for (vector<Node*>::iterator it = root->sub.begin(); it != root->sub.end(); it++) {
					if ((*it)->id == id) {
							root->sub.erase(it);
							return;
					} else {
							cut(*it, id);
					}
			}
	}
}

int main() {
	cin >> n >> k;
	
	nodes = new Node[n+1]; // start from 1
	for (int i = 0; i < n+1; i ++) {
			nodes[i].idSum = i;
			nodes[i].id = i;		// search by id in greedyCut
	}
	for (int i = 0; i < n-1; i++) {
		int x, y;
		cin >> x >> y;
		int sum = x+y;
		x = x<y? x: y;
		y = sum-x;
		nodes[x].sub.push_back(&nodes[y]);	// build tree
	}
	// set the glod[1] as the root
	Node *root = &nodes[1];
	countSubGold(root);
	
	for (int i = 0; i < k-1; i++) {
		limit = root->gold/2;
		greedyChoose(root);
		cout << nodes[cut_id].gold << " ";
		cut(root, cut_id);	// cut the branch
		for (int i = 0; i < n+1; i++) {
				nodes[i].gold = 1;
		}
		countSubGold(root);	// rebuild the tree
		cut_id = 0;	// reset cut_id
	}
	
	cout << root->gold << endl;	// the left gold
	
	// testing ok
	//cout <<nodes[3].gold << endl;
	//cout << nodes[3].idSum << endl;
	
}