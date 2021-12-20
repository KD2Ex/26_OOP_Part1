#include <iostream>
#include <map>

using namespace std;

#define MOVE_NAME "move"
#define RESIZE_NAME "resize"
#define DISPLAY_NAME "display"
#define CLOSE_NAME "close"

const int SCREEN_WIDTH = 80;
const int SCREEN_HEIGHT = 50;

enum Commands {
    MOVE = 1,
    RESIZE,
    DISPLAY,
    CLOSE
};

struct Coordinates {
        int x = 0;
        int y = 0;
    };

class Window {
    
    
    Coordinates coordinates;
    int width;
    int height; 

public:
    
    Coordinates getCoordinates() {
        return coordinates;
    }
    
    int getWidth() {
        return width;
    }

    int getHeight() {
        return height;
    }

    void resize() {
        cout << "hi\n";
        do {
            cout << "Enter the width and heigh\n";
            cin >> width >> height;
        } while (width < 0 && height < 0);
    }

    void move() {
        cout << "hihi\n";
        int x;
        int y;
        int newX;
        int newY;
        while (true) {
            cout << "Enter the coordinates\n";
            cin >> x >> y;
            newX = coordinates.x + x;
            newY = coordinates.y + y;
            if (!((newX < 0 || newX > SCREEN_WIDTH - 1) ||
                (newY < 0 || newY > SCREEN_HEIGHT - 1)) ) {
                break;
            } else {
                cout << "Wrong coordinates!\n";
            }
        }
        coordinates.x = newX;
        coordinates.y = newY;
    }

        
};



class Screen {

    char screen[80][50];
    const int screenWidth = SCREEN_WIDTH;
    const int screenHeight = SCREEN_HEIGHT;
    
public:

    
    void print(Window window) {
        for (int i = 0; i < screenHeight; i++) {
            for (int j = 0; j < screenWidth; j++) {
                if ((i >= window.getCoordinates().y &&  i <= window.getCoordinates().y + window.getHeight() - 1)
                && (j >= window.getCoordinates().x && j <= window.getCoordinates().x + window.getWidth() - 1)) {
                    cout << "1";
                } else cout << "0";
            }
            cout << endl;
        }
    }


};



int main() {
    Screen screen;
    Window window;

    map<string, int> commands;
    commands[MOVE_NAME] = Commands::MOVE;
    commands[RESIZE_NAME] = Commands::RESIZE;
    commands[DISPLAY_NAME] = Commands::DISPLAY;
    commands[CLOSE_NAME] = Commands::CLOSE;


    while (true) {
        string command;

        cout << "Enter the command\n";
        cin >> command; 
        
        switch (commands[command]) {
            case MOVE: 
                window.move();
                break;
            case RESIZE:
                window.resize();
                break;
            case DISPLAY:
                screen.print(window);
                break;
            case CLOSE:
                return 0;
            default:
                cout << "Wrong command\n";
                break;
        }
    }
}