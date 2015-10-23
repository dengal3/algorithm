#include <iostream>
#include <cmath>
using namespace std;

int target;
int appro;
bool flag;

void solve(int nums[], int size) {
    for (int i = 0; i < size; i++) {
        if (nums[i] == target) {
            flag = true;
            return;
        } else if (nums[i] < target && nums[i] > appro) {
            appro = nums[i];
        }
    }
        
    if (size == 1) {
        if (nums[0] <= target && nums[0] > appro) {
            appro = nums[0];
            return;
        }
    }
    int b[5] = {0};
    for (int i = 0; i < size; i++) {
        for (int j = 0; j< size; j++) {
			if (j == i) {
					continue;
			}
            b[0] = nums[i]+nums[j];
            for (int k1 = 1, k = 0; k < size; k++) {
                if (k != i && k != j) {
                    b[k1++] = nums[k];
                }
            }
            solve(b, size-1);
			if (flag) {
				return;
			}
            
            b[0] = nums[i]-nums[j];
            for (int k1 = 1, k = 0; k < size; k++) {
                if (k != i && k != j) {
                    b[k1++] = nums[k];
                }
            }
            solve(b, size-1);
			if (flag) {
					return;
			}
            
            b[0] = nums[i]*nums[j];
            for (int k1 = 1, k = 0; k < size; k++) {
                if (k != i && k != j) {
                    b[k1++] = nums[k];
                }
            }
            solve(b, size-1);
			if (flag) {
					return;
			}
            
            if (nums[j] != 0 && nums[i]%nums[j] == 0) {
                b[0] = nums[i]/nums[j];
                for (int k1 = 1, k = 0; k < size; k++) {
                    if (k != i && k != j) {
                        b[k1++] = nums[k];
                    }
                }
                solve(b, size-1);
				if (flag) {
					return;
				}
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    while(n--) {
        int nums[5];
        for (int i = 0; i < 5; i++) {
            cin >> nums[i];
        }
        cin >> target;

		appro = -9999;
        flag = false;
        solve(nums, 5);
        
        if (flag) {
            cout << target << endl;
        } else {
            cout << appro << endl;
        }
    }
}
