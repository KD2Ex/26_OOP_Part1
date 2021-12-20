#include <iostream>
#include <map>
#include <vector>
#include <ctime>
#include <iomanip>
using namespace std;

#define PLAY_NAME "play"
#define PAUSE_NAME "pause"
#define NEXT_NAME "next"
#define STOP_NAME "stop"
#define EXIT_NAME "exit"

enum Commands {
    PLAY = 1,
    PAUSE,
    NEXT,
    STOP,
    EXIT
};

class Track {
    string name;
    tm creationDate;
    int duration = 0;

public:
    string getName() {
        return name;
    }

    tm getCreationDate() {
        return creationDate;
    }

    int getDuration() {
        return duration;
    }

    void setName(string name) {
        Track::name = name;
    }

    void setCreationDate(tm date) {
        creationDate.tm_year = date.tm_year;
        creationDate.tm_mon = date.tm_mon;
        creationDate.tm_mday = date.tm_mday;
    }

    void setDuration(int duration) {
        Track::duration = duration;
    }
};

class Player {
    
    map<string, Track> tracks;
    Track* currentTrack;
    bool isSongPlaying = false;
    bool isSongPaused = false;

    

public:

    void addTrack(Track track) {
        tracks[track.getName()] = track;
    }

    void play() {
        
        if (!isSongPlaying) {
            cout << "Enter the track name\n";
            string name;
            getline(cin, name);
            auto song = tracks.find(name);
            tm date = song->second.getCreationDate();
            cout << "Now playing: " << name << endl << 
                song->second.getDuration() / 60 << ":" << song->second.getDuration() % 60 << endl 
                << date.tm_year << "/" << date.tm_mon + 1 << "/" << date.tm_mday << endl;

            isSongPlaying = true;
            currentTrack = &song->second;
        }
    } 

    void pause() {
        if (isSongPlaying && !isSongPaused) {
            isSongPaused = true;
            isSongPlaying = false;
            cout << currentTrack->getName() << " is paused\n";
        }
    }

    void next() {
        vector<string> songsNames;
        for (auto & i : tracks) {
            songsNames.push_back(i.first);
        }

        int randTrackNumber = rand() % songsNames.size();
        auto nextTrack = tracks.find(songsNames[randTrackNumber]);
        currentTrack = &nextTrack->second;

        cout << "Now playing: " << currentTrack->getName() << endl;
    }

    void stop() {
        if (isSongPlaying || isSongPaused) {
            delete currentTrack;
            currentTrack = nullptr;

        }
    }

};

int main() {
    srand(time(nullptr));

    map<string, int> commands;
    commands[PLAY_NAME] = Commands::PLAY;
    commands[PAUSE_NAME] = Commands::PAUSE;
    commands[NEXT_NAME] = Commands::NEXT;
    commands[STOP_NAME] = Commands::STOP;
    commands[EXIT_NAME] = Commands::EXIT;

    Player player;

    //vector<Track> tracks;
    string trackNames[3] = { "Master of Puppets", "No Reflection", "Wait and bleed" };
    int durations[3] = { 500, 300, 186 };
    int years[3] = { 1986, 2001, 1999 };
    int mons[3] = { 6, 8, 7 };
    int mday[3] = { 23, 14, 17 };

    for (int i = 0; i < 3; i++) {
        Track newTrack;
        newTrack.setName(trackNames[i]);
        newTrack.setDuration(durations[i]);

        time_t t = time(nullptr);
        tm date1 = *localtime(&t);

        date1.tm_year = years[i];
        date1.tm_mon = mons[i];
        date1.tm_mday = mday[i];

        newTrack.setCreationDate(date1);
        player.addTrack(newTrack);
    }
    


    while (true) {
        cout << "Enter the command\n";
        string command;
        getline(cin, command);

        switch (commands[command]) {
            case Commands::PLAY: {
                
                // cout << "Enter the track name\n";
                // string trackName;
                // getline(cin, trackName);
                player.play();
                break;
            }
            case Commands::PAUSE: {
                player.pause();
                break;
            }
            case Commands::NEXT: {
                player.next();
                break;
            }
            case Commands::STOP: {
                player.stop();
                break;
            }
            case Commands::EXIT: {
                return 0;
            }
            default: 
                cout << "Wrong command\n";
                break;
        }
    }
}