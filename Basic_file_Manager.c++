#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

using namespace std;

// Function to list files and directories in the current directory
void listFiles(const string& directoryPath) {
    try {
        cout << "Files in directory: " << directoryPath << endl;
        for (const auto& entry : fs::directory_iterator(directoryPath)) {
            cout << entry.path().filename().string() << endl;
        }
    } catch (const fs::filesystem_error& e) {
        cout << "Error: " << e.what() << endl;
    }
}

// Function to create a new directory
void createDirectory(const string& directoryName) {
    try {
        if (fs::create_directory(directoryName)) {
            cout << "Directory created: " << directoryName << endl;
        } else {
            cout << "Directory creation failed!" << endl;
        }
    } catch (const fs::filesystem_error& e) {
        cout << "Error: " << e.what() << endl;
    }
}

// Function to copy a file from source to destination
void copyFile(const string& sourceFile, const string& destinationPath) {
    try {
        fs::copy(sourceFile, destinationPath);
        cout << "File copied from " << sourceFile << " to " << destinationPath << endl;
    } catch (const fs::filesystem_error& e) {
        cout << "Error: " << e.what() << endl;
    }
}

// Function to move a file from source to destination
void moveFile(const string& sourceFile, const string& destinationPath) {
    try {
        fs::rename(sourceFile, destinationPath);
        cout << "File moved from " << sourceFile << " to " << destinationPath << endl;
    } catch (const fs::filesystem_error& e) {
        cout << "Error: " << e.what() << endl;
    }
}

// Function to delete a file
void deleteFile(const string& filePath) {
    try {
        if (fs::remove(filePath)) {
            cout << "File deleted: " << filePath << endl;
        } else {
            cout << "File deletion failed or file doesn't exist!" << endl;
        }
    } catch (const fs::filesystem_error& e) {
        cout << "Error: " << e.what() << endl;
    }
}

// Function to change the current working directory
void changeDirectory(const string& newPath) {
    try {
        fs::current_path(newPath);
        cout << "Changed directory to: " << fs::current_path().string() << endl;
    } catch (const fs::filesystem_error& e) {
        cout << "Error: " << e.what() << endl;
    }
}

// Function to show the current working directory
void currentDirectory() {
    cout << "Current directory: " << fs::current_path().string() << endl;
}

int main() {
    int choice;
    string path, source, destination;

    cout << "Simple File Manager" << endl;

    while (true) {
        // Display menu
        cout << "\n1. List Files" << endl;
        cout << "2. Create Directory" << endl;
        cout << "3. Copy File" << endl;
        cout << "4. Move File" << endl;
        cout << "5. Delete File" << endl;
        cout << "6. Change Directory" << endl;
        cout << "7. Show Current Directory" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter directory path: ";
                cin >> path;
                listFiles(path);
                break;

            case 2:
                cout << "Enter directory name to create: ";
                cin >> path;
                if (path.find('.') == string::npos) {  // Simple check to avoid file-like names
                    createDirectory(path);
                } else {
                    cout << "Error: Please enter a valid directory name!" << endl;
                }
                break;

            case 3:
                cout << "Enter source file path: ";
                cin >> source;
                cout << "Enter destination path: ";
                cin >> destination;
                copyFile(source, destination);
                break;

            case 4:
                cout << "Enter source file path: ";
                cin >> source;
                cout << "Enter destination path: ";
                cin >> destination;
                moveFile(source, destination);
                break;

            case 5:
                cout << "Enter file path to delete: ";
                cin >> path;
                deleteFile(path);
                break;

            case 6:
                cout << "Enter path to change to: ";
                cin >> path;
                changeDirectory(path);
                break;

            case 7:
                currentDirectory();
                break;

            case 8:
                cout << "Exiting..." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
