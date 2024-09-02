#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, H, P;
    // cout << "Enter the number of students (N): ";
    cin >> N;
    // cout << "Enter the number of hostels (H): ";
    cin >> H;
    // cout << "Enter the number of vacancies per hostel (P): ";
    cin >> P;

    // Check for feasibility
    if (H > N || N > H * P) {
        cout << "Allocation is not feasible with the given inputs." << endl;
        return 1;
    }

    vector<vector<int>> allocation(H);

    // Allocate at least one student to each hostel
    for (int i = 0; i < H; ++i) {
        allocation[i].push_back(i + 1);
        --N;
    }

    // Distribute the remaining students
    int hostel_index = 0;
    int student_id = H + 1;
    while (N > 0) {
        if (allocation[hostel_index].size() < P) {
            allocation[hostel_index].push_back(student_id++);
            --N;
        }
        hostel_index = (hostel_index + 1) % H;
    }

    // Output the allocation
    cout << "Student allocation to hostels:" << endl;
    for (int i = 0; i < H; ++i) {
        cout << "Hostel " << i + 1 << ": ";
        for (int student : allocation[i]) {
            cout << student << " ";
        }
        cout << endl;
    }

    return 0;
}
