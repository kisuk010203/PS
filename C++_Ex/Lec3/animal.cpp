#include <iostream>
using namespace std;
typedef struct Animal{
    char name[30];
    int age;
    int health;
    int food;
    int clean;
}Animal;
void create_animal(Animal *animal){
    cout << "name?";
    cin >> animal->name;
    cout << "age?";
    cin >> animal->age;
    animal->health = 100;
    animal ->food = 100;
    animal->clean = 100;
}
void play(Animal *animal){
    animal->health += 10;
    animal->food -= 20;
    animal->clean -= 30;
}
void one_day_pass(Animal *animal) {
  animal->health -= 10;
  animal->food -= 30;
  animal->clean -= 20;
}
void show_stat(Animal *animal){
    cout << animal->name <<endl;
    cout << "health : " << animal->health << endl;

}
int main(){
    Animal* list[30];
    for(int i=0; i<30; i++){
        list[i] = new Animal;

    }
}
