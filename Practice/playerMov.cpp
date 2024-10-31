#include<iostream>
#include<thread>
#include<mutex>
#include<utility>
#include<chrono>
#include<conio.h>

static char arr[15][15];
static bool running = true;

struct pos {
    int y = 0;
    int x = 0;
} plyr;

void initArr();
void display();
void getDir(char& ch);

int main() {
    initArr();
    char dir = ' ';
    std::thread disp(display);
    std::thread move(getDir,std::ref(dir));
    while(dir!='l') {
        std::this_thread::sleep_for(std::chrono::milliseconds(70));
        if(dir == 'w' && plyr.y>0) {
            arr[plyr.y][plyr.x] = ' ';
            arr[--plyr.y][plyr.x] = '@';
        } else if(dir == 's' && plyr.y<14) {
            arr[plyr.y][plyr.x] = ' ';
            arr[++plyr.y][plyr.x] = '@';
        } else if(dir == 'a' && plyr.x>0) {
            arr[plyr.y][plyr.x] = ' ';
            arr[plyr.y][--plyr.x] = '@';
        } else if(dir == 'd' && plyr.x<14) {
            arr[plyr.y][plyr.x] = ' ';
            arr[plyr.y][++plyr.x] = '@';
        }
    }
    running = false;
    move.join();
    disp.join();
    return 0;
}

void initArr() {
    for(int i=0; i<15; i++) {
        for(int j=0; j<15; j++) {
            arr[i][j] = '-';
        }
    }
    arr[plyr.y][plyr.x] = '@';
}

void display() {
    while(running) {
        system("cls");
        std::this_thread::sleep_for(std::chrono::milliseconds(17));
        for(int i=0; i<15; i++) {
            for(int j=0; j<15; j++) {
                std::cout<<arr[i][j]<<' ';
            }
            std::cout<<"\n";
        }
    }
}

void getDir(char& ch) {
    while(running) {
        ch = _getch();
    }
}