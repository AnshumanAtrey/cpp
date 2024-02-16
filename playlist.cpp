#include <iostream>
#include <string>
using namespace std;

struct Song {
    string name;
    string producer;
    string singer;
    string genre;
};

class Node {
public:
    Song data;
    Node* prev;
    Node* next;
};

class Playlist {
public:
    Node* head;
    Node* tail;
    Node* currentSong;

    Playlist() : head(nullptr), tail(nullptr), currentSong(nullptr) {}

    void addSong(const Song& song) {
        Node* newNode = new Node{song, nullptr, nullptr};
        if (!head) {
            head = newNode;
            tail = newNode;
            currentSong = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void displayCurrentSong() const {
        if (currentSong) {
            cout << "Current Song: " << currentSong->data.name << endl;
            cout << "Producer: " << currentSong->data.producer << endl;
            cout << "Singer: " << currentSong->data.singer << endl;
            cout << "Genre: " << currentSong->data.genre << endl;
        } else {
            cout << "No song is currently playing." << endl;
        }
    }

    void nextSong() {
        if (currentSong && currentSong->next) {
            currentSong = currentSong->next;
            displayCurrentSong();
        } else {
            cout << "No next song available." << endl;
        }
    }

    void prevSong() {
        if (currentSong && currentSong->prev) {
            currentSong = currentSong->prev;
            displayCurrentSong();
        } else {
            cout << "No previous song available." << endl;
        }
    }
};

int main() {
    Playlist playlist;

    // Adding songs to the playlist
    playlist.addSong({"Baadshah", "Speed Records", "Billy X", "Rap"});
    playlist.addSong({"Jamal Kudu", "T-Series", "Traditional", "Party"});
    playlist.addSong({"If The World Was Ending", "FINNEAS", "JP Saxe", "Romantic"});
    playlist.addSong({"Tera Zikr", "Sony Music", "Darshan Raval", "Sad"});
    playlist.addSong({"One Shot 2 Shot", "Luis Resto", "Eminem", "Hip Hop"});
    playlist.addSong({"Sunday", "Ronit Vinta", "Aditya A", "Chill"});

    // Displaying current song and navigating through the playlist
    playlist.displayCurrentSong();
    playlist.nextSong();
    playlist.nextSong();
    playlist.prevSong();
    playlist.nextSong();
    playlist.nextSong();
    playlist.nextSong();
    playlist.nextSong();
    playlist.nextSong();
    playlist.prevSong();
    playlist.prevSong();
    playlist.prevSong();

    return 0;
}
