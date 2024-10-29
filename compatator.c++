#include <bits/stdc++.h>
using namespace std;

struct person {
    private:
        int age;
        float height;
    public:
        person(int age, float height) : age(age), height(height) {}

        // Provide a way to print `person` object for the output
        friend ostream& operator<<(ostream &os, const person &p) {
            os << "Age: " << p.age << ", Height: " << p.height;
            return os;
        }

        // Getter for height to use in comparison
        float getHeight() const {
            return height;
        }
};

// Comparator for the priority_queue to order by height
struct mycomp {
    bool operator()(const person &p1, const person &p2) {
        return p1.getHeight() < p2.getHeight();  // For max-heap based on height
    }
};

int main() {
    priority_queue<person, vector<person>, mycomp> pq;

    // Insert elements into the priority_queue
    pq.emplace(14, 5.4);
    pq.emplace(20, 6.0);
    pq.emplace(18, 5.9);
    pq.emplace(17, 5.7);

    // Print and remove elements from the priority_queue
    while (!pq.empty()) {
        cout << pq.top() << endl;
        pq.pop();
    }

//     while (!pq.empty()) {
//     person topPerson = pq.top();
//     cout << "Age: " << topPerson.getAge() << ", Height: " << topPerson.getHeight() << endl;
//     pq.pop();
// }


    return 0;
}
