#include<iostream>
#include<functional>
#include<thread>
#if defined(_WIN32) || defined(_WIN64)
#include <conio.h>  // For Windows
#else
#include <termios.h>
#include <unistd.h>

#define yellow "\x1b[33m"
#define reset "\x1b[00m"

// Function to simulate getch() on Linux
char getch() {
    char buf = 0;
    struct termios old = {0};
    if (tcgetattr(0, &old) < 0) {
        perror("tcgetattr");
    }
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0) {
        perror("tcsetattr");
    }
    if (read(0, &buf, 1) < 0) {
        perror("read");
    }
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0) {
        perror("tcsetattr");
    }
    return buf;
}
#endif

static bool running = true;

struct ball{
  int y=29;
  int x=0;
}pos;

void move(char (&arr)[30][30]){
  char ch = getch();
  if(ch == 'l' && pos.x > 0){ //left
    arr[pos.y][--pos.x] = '^';
    arr[pos.y][pos.x+1] = '+';
  } else if(ch == 'a' && pos.x < 28){ //right
    arr[pos.y][++pos.x] = '^';
    arr[pos.y][pos.x-1] = '+';
  }
}

int main(){
  system("clear");
  char arr[30][30];
  for(int i=0;i<30;i++){
    for(int j=0;j<30;j++){
      arr[i][j]='+';
    }
  }

  arr[pos.y][pos.x] = '^';
  std::thread mv(move,std::ref(arr));

  while(running){
    system("clear");
  for(int i=0;i<30;i++){
    std::cout<<'\n';
    for(int j=0;j<30;j++){
      if(arr[i][j]=='^'){
      std::cout<<yellow;
      printf("%2c",arr[i][j]);
      std::cout<<reset;
      } else {
        printf("%2c",arr[i][j]);
      }
    }
  }
}

  mv.join();
  std::cout<<std::endl;
  return 0;
  }
