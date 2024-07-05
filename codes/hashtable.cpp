#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// Define a structure for UserHashTable
class UserHashTable {
private:
    unordered_map<string, unordered_map<string, string>> table;

public:
    void addUser(const string& userId, const unordered_map<string, string>& userInfo) {
        table[userId] = userInfo;
    }

    unordered_map<string, string> getUser(const string& userId) {
        if (table.find(userId) != table.end()) {
            return table[userId];
        }
        return {}; // Return empty map if user not found
    }

    void deleteUser(const string& userId) {
        if (table.find(userId) != table.end()) {
            table.erase(userId);
        }
    }
};

int main() {
    UserHashTable users;

    // Example usage
    unordered_map<string, string> userInfo = {{"name", "Prakash"}, {"rides", ""}};
    users.addUser("user1", userInfo);

    unordered_map<string, string> user = users.getUser("user1");
    if (!user.empty()) {
        cout << "User found:" << endl;
        for (const auto& entry : user) {
            cout << entry.first << ": " << entry.second << endl;
        }
    } else {
        cout << "User not found." << endl;
    }

    users.deleteUser("user1");

    return 0;
}
