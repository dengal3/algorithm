#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct Employee {
		int id;
		int sal;
		int height;
		
		Employee() {}
		
		Employee(int _id, int _sal, int _height) {
				id = _id;
				sal = _sal;
				height = _height;
		}
};

Employee *all = new Employee[30005]();
int m, q;

bool cmp_fun(Employee a, Employee b) {
		return a.sal < b.sal;
}

void find(int pos, int front, int back) {
		while (pos-front >= 0) {
				if (all[pos-front].height >= all[pos].height) {
						break;
				}
				front++;
		}
		if (pos-front < 0) {
				cout << "0" << " ";
		} else {
				cout << all[pos-front].id << " ";
		}
		
		while (pos+back < m) {
				if (all[pos+back].height <= all[pos].height ) {
						break;
				}
				back++;
		}
		if (pos+back >= m) {
				cout << "0" << endl;
		} else {
				cout << m-(pos+back) << endl;
		}
}

int main() {
		int n;
		cin >> n;
		while (n--) {
				cin >> m >> q;
				for (int i = 0; i < m; i++) {
						int id, sal, height;
						cin >> id >> sal >> height;
						all[i] = *(new Employee(id, sal, height));
				}
				sort(all, all+m, cmp_fun);
				
				int boss[30005] = {-1}, sub[30005] = {0};
				
				for (int i = 0; i < m; i++) {
						for (int j = i+1; j < m; j++) {
								if (all[i].height <= all[j].height) {
										boss[i] = all[j].id;
										sub[j] += sub[i]+1;
										break;
								}
						}
				}
				
				map<int ,int> id_map;
				for (int i = 0; i < m; i++) {
						id_map.insert(pair<int, int>(all[i].id, i));
				}
				
				for (int i = 0; i < q; i++) {
						int query_id;
						cin >> query_id;
						int pos = id_map.find(query_id)->second;
						//find(pos, 1, 1);
						cout << ((boss[pos] == -1)? 0: boss[pos] ) << " " << sub[pos] << endl;
				}
		}
		return 0;
}