#include<iostream>
#include<random>

int r1,r2;
int Points{};

void continue_or_not();
void Game();
void MainGame(int r1,int r2);

void IntroPage(){
  char choice;
  std::cout<<"\nHilo!\n\n";

  std::cout<<"\nPlay(P)\nQuit(Q)\n\nEnter: ";
  std::cin>>choice;

  if(choice == 'P' || choice == 'p')
    Game();
}

int GenRandomNum(int r1,int r2){
  std::random_device rd;
  std::seed_seq ss{rd(),rd(),rd(),rd(),rd(),rd(),rd(),rd()};
  std::mt19937 mt{ss};
  std::uniform_int_distribution range{r1,r2};
  return range(mt);
}

void MainGame(int r1,int r2){

  int flag{};
  int random_num{GenRandomNum(r1,r2)};

  for(int i=1;i<=7;i++){
    int guess{0};

    std::cout<<"\n\n#"<<i<<" Guess: ";
    std::cin>>guess;

    if(guess>random_num){
      std::cout<<"\nGuess is Higher!";
      std::cout<<"\nPoints: "<<Points<<'\n';
    } else if(guess<random_num){
      std::cout<<"\nGuess is Lower!";
      std::cout<<"\nPoints: "<<Points<<'\n';
    } else {
      std::cout<<"\n\nYou Won!";
      Points+=5;
      flag=1;
      std::cout<<"\nPoints: "<<Points<<"\n\n";
      break;
    }
    if(i==7 && flag==0 && Points!=0){
      Points-=3;
      std::cout<<"\nPoints: "<<Points;
    }
  }
}

void Game(){

  std::cout<<"\nEnter Range(r1 & r2): ";
  std::cin>>r1>>r2;

  MainGame(r1,r2);

  continue_or_not();
}

void continue_or_not(){
  int choice{1};
  while(choice){
    char i_choice;
    std::cout<<"\n\nQuit(Q)\nContinue(C)\n\nEnter: ";
    std::cin>>i_choice;
    switch(i_choice){
      case 'q' :
      case 'Q' : choice=0;
                 break;
      case 'c' :
      case 'C' : MainGame(r1,r2);
                 break;
      default  : std::cout<<"Invalid Choice\n";
                 break;
    }
  }
}

int main(){

  IntroPage();

  return 0;
}
