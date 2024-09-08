#include <iostream>
#include <cstring>

using namespace std;

class food{
    private:
        int foodPrice;
        char * foodName;
    public:
        food(){}
        food(char * name, int price) : foodPrice(price){
            foodName = new char[strlen(name)+1];
            strcpy(foodName, name);
        }
        food(const food &copy) : foodPrice(copy.foodPrice){
            foodName = new char[strlen(copy.foodName)+1];
            strcpy(foodName, copy.foodName);
        }
        int getPrice() const{
            return foodPrice;
        }
        char* getName() const{
            return foodName;
        }
        //~food(){                      //whydouble free or corruption (out) Aborted althoigh deepcopy
        //    delete []foodName;
        //}
};
class menu{
    private:
        int foodNum;
        char * menuName;
        food * Food;
    public:
        menu(char * name) : foodNum(0){
            menuName = new char[strlen(name)+1];
            strcpy(menuName, name);
            Food = new food;
        }
        int getPrice() {
            int sum=0;
            for(int i=0;i<foodNum;i++){
                sum += Food[i].getPrice();
            }
            return sum;
        }
        void addFood(food withFood){
            Food[foodNum] = withFood;
            cout<<Food[0].getName()<<Food[0].getPrice()<<endl; // why error?
            foodNum++;
        }
        void showInfo(){ // can you make it getInfo()?
            int sum=0;
            for(int i=0;i<foodNum;i++){
                cout<<Food[i].getName()<<endl;
                cout<<Food[i].getPrice()<<endl;
            }
        }
        ~menu(){
            delete []menuName;
        }
};

int main() {
    food steak("steak", 10000);
    food pasta("pasta", 15000);
    food pizza("pizza", 20000);
    menu WesternSet("WesternSet");
    WesternSet.addFood(steak);
    WesternSet.addFood(pasta);
    WesternSet.addFood(pizza);
    cout<<WesternSet.getPrice()<<endl;
    WesternSet.showInfo();
    return 0;
}
