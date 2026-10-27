// ============================================================================
//  Music Playlist Manager  (CCE Case Study)
//  Subject : Data Structures and Algorithms [R25-EC-PCC-202]
//  Aim     : Implement a Music Playlist Manager using a Doubly Linked List
//
//  Pointer naming convention (same as the reference implementation):
//      p       -> points to a newly allocated node OR the node to be deleted
//      q       -> navigation / traversal pointer used to move through the list
//      head    -> points to the first node (first song) of the playlist
//      current -> points to the currently selected / playing song
//      prev    -> link inside every node, points to the song BEFORE it
//      next    -> link inside every node, points to the song AFTER it
// ============================================================================

#include <iostream>
#include <string>
using namespace std;

// ----------------------------------------------------------------------------
// Node class : one node = one song
// ----------------------------------------------------------------------------
class Node {
public:
    string title;   // Song Title
    string artist;  // Artist Name
    Node* prev;     // prev : previous song (nullptr for the first song)
    Node* next;     // next : next song     (nullptr for the last song)

    Node(string t, string a) {
        title = t;
        artist = a;
        prev = nullptr;
        next = nullptr;
    }
};

// ----------------------------------------------------------------------------
// Doubly linked list class : Music Playlist
// ----------------------------------------------------------------------------
class MusicPlaylist {
private:
    Node* head;      // head    : first song of the playlist
    Node* current;   // current : currently selected / playing song

public:
    MusicPlaylist() {
        head = nullptr;      // empty playlist
        current = nullptr;
    }

    // Free all nodes. q travels the list, p is the node being deleted.
    ~MusicPlaylist() {
        Node *p, *q;
        q = head;
        while (q != nullptr) {
            p = q;
            q = q->next;
            delete p;
        }
    }

    // ---------------- 1. Add Song (insert at the end) ----------------
    void addSong(string title, string artist) {
        Node* p = new Node(title, artist);   // p : newly allocated node

        if (head == nullptr) {
            head = p;                        // first song of the playlist
            current = p;                     // and it becomes the current song
        } else {
            Node* q = head;                  // q : traversal pointer
            while (q->next != nullptr) {     // move q to the last song
                q = q->next;
            }
            q->next = p;                     // last song -> new song
            p->prev = q;                     // new song  -> last song
        }
        cout << "Song added: " << title << " - " << artist << "\n";
    }

    // ---------------- 2. Delete Song (by title) ----------------
    void deleteSong(string title) {
        Node *p, *q;                         // p : node to delete, q : traversal

        if (head == nullptr) {
            cout << "Playlist is empty. Nothing to delete.\n";
            return;
        }

        // Case 1 : delete the FIRST song
        if (head->title == title) {
            p = head;
            if (current == p) {
                current = p->next;           // current must not point to deleted node
            }
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;        // new first song has no previous song
            }
            delete p;
            cout << "Song deleted: " << title << "\n";
            return;
        }

        // Case 2 : delete a MIDDLE or LAST song
        q = head;
        while (q->next != nullptr) {
            if (q->next->title == title) {
                p = q->next;                 // p : node to be deleted
                if (current == p) {
                    if (p->next != nullptr)
                        current = p->next;
                    else
                        current = p->prev;   // last song deleted -> go back one
                }
                q->next = p->next;           // bypass p (forward link)
                if (p->next != nullptr) {    // p is a middle song
                    p->next->prev = q;       // bypass p (backward link)
                }
                delete p;
                cout << "Song deleted: " << title << "\n";
                return;
            }
            q = q->next;
        }

        // Case 3 : song not found
        cout << "Song " << title << " not found in the playlist.\n";
    }

    // ---------------- 3. Display Playlist (forward) ----------------
    void displayForward() {
        Node* q = head;                      // q : traversal pointer
        if (q == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }
        cout << "Playlist (Forward): ";
        while (q != nullptr) {
            cout << q->title << " <-> ";
            q = q->next;                     // move forward using next
        }
        cout << "NULL\n";
    }

    // ---------------- 4. Display Playlist in Reverse ----------------
    void displayReverse() {
        Node* q = head;                      // q : traversal pointer
        if (q == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }
        while (q->next != nullptr) {         // first move q to the last song
            q = q->next;
        }
        cout << "Playlist (Reverse): ";
        while (q != nullptr) {
            cout << q->title << " <-> ";
            q = q->prev;                     // move backward using prev
        }
        cout << "NULL\n";
    }

    // ---------------- 5. Play Current Song ----------------
    void playCurrent() {
        if (current == nullptr) {
            cout << "Playlist is empty. No song to play.\n";
            return;
        }
        cout << "Now Playing: " << current->title << " - " << current->artist << "\n";
    }

    // ---------------- 6. Play Next Song ----------------
    void playNext() {
        if (current == nullptr) {
            cout << "Playlist is empty.\n";
        } else if (current->next == nullptr) {
            cout << "This is the last song. There is no next song.\n";
        } else {
            current = current->next;         // move to the Next Song
            playCurrent();
        }
    }

    // ---------------- 7. Play Previous Song ----------------
    void playPrevious() {
        if (current == nullptr) {
            cout << "Playlist is empty.\n";
        } else if (current->prev == nullptr) {
            cout << "This is the first song. There is no previous song.\n";
        } else {
            current = current->prev;         // move to the Previous Song
            playCurrent();
        }
    }

    // ---------------- 8. Play Complete Playlist ----------------
    void playComplete() {
        Node* q = head;                      // start from the first song
        if (q == nullptr) {
            cout << "Playlist is empty. Nothing to play.\n";
            return;
        }
        while (q != nullptr) {
            current = q;                     // current follows the playing song
            playCurrent();
            q = q->next;
        }
    }

    // ---------------- 9. Repeat All ----------------
    void repeatAll(int times) {
        if (head == nullptr) {
            cout << "Playlist is empty. Nothing to repeat.\n";
            return;
        }
        for (int i = 1; i <= times; i++) {
            cout << "--- Repeat " << i << " ---\n";
            Node* q = head;                  // restart from the first song (head)
            while (q != nullptr) {
                current = q;
                playCurrent();
                q = q->next;
            }
        }
    }

    // ---------------- 10. Show Current Song ----------------
    void showCurrent() {
        if (current == nullptr) {
            cout << "No current song. Playlist is empty.\n";
            return;
        }
        cout << "Current Song: " << current->title << " - " << current->artist << "\n";
    }
};

// ----------------------------------------------------------------------------
// Menu
// ----------------------------------------------------------------------------
void showMenu() {
    cout << "\n========== MUSIC PLAYLIST MANAGER ==========\n";
    cout << " 1. Add Song\n";
    cout << " 2. Delete Song\n";
    cout << " 3. Display Playlist\n";
    cout << " 4. Display Playlist in Reverse\n";
    cout << " 5. Play Current Song\n";
    cout << " 6. Play Next Song\n";
    cout << " 7. Play Previous Song\n";
    cout << " 8. Play Complete Playlist\n";
    cout << " 9. Repeat All\n";
    cout << "10. Show Current Song\n";
    cout << "11. Exit\n";
    cout << "============================================\n";
    cout << "Enter your choice: ";
}

// ----------------------------------------------------------------------------
// Main function : shows the menu again and again until the user selects Exit
// ----------------------------------------------------------------------------
int main() {
    MusicPlaylist playlist;
    int choice, times;
    string title, artist;

    do {
        showMenu();
        cin >> choice;
        cin.ignore();                        // remove the Enter key left in input

        switch (choice) {
        case 1:
            cout << "Enter song title  : ";
            getline(cin, title);
            cout << "Enter artist name : ";
            getline(cin, artist);
            playlist.addSong(title, artist);
            break;
        case 2:
            cout << "Enter title of the song to delete: ";
            getline(cin, title);
            playlist.deleteSong(title);
            break;
        case 3:
            playlist.displayForward();
            break;
        case 4:
            playlist.displayReverse();
            break;
        case 5:
            playlist.playCurrent();
            break;
        case 6:
            playlist.playNext();
            break;
        case 7:
            playlist.playPrevious();
            break;
        case 8:
            playlist.playComplete();
            break;
        case 9:
            cout << "Enter number of repetitions: ";
            cin >> times;
            playlist.repeatAll(times);
            break;
        case 10:
            playlist.showCurrent();
            break;
        case 11:
            cout << "Exiting Music Playlist Manager.\n";
            break;
        default:
            cout << "Invalid choice. Enter a number from 1 to 11.\n";
        }
    } while (choice != 11);

    return 0;
}
