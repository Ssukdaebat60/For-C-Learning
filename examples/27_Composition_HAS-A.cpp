#include <iostream>

using namespace std;

class Gun{
    private:
        int bullet;
    public:
        Gun(int bNum) : bullet(bNum){
        }
        void shot(){
            if(bullet){
                cout<<"Bang!"<<endl;
                bullet--;
            }
            else{
                cout<<"no bullet"<<endl;
            }
        }
};

class Police{
    private:
        int handcuffs;
        Gun * pistol;
    public:
        Police(int bNum, int cuff) : handcuffs(cuff){
            pistol = new Gun(bNum);
        }
        //Police(int bNum, int cuff) : pistol(bNum), handcuffs(cuff){} why??
        void putHandcuff(){
            if (handcuffs){
                cout<<"SNAP"<<endl;
                handcuffs--;
            }
            else{
                cout<<"no handcuff"<<endl;
            }
        }
        void shot(){
            pistol->shot();
        }
        ~Police(){
            delete pistol;
        }
};

int main() {
    Police P1(1,1);
    P1.putHandcuff();
    P1.shot();
    P1.putHandcuff();
    P1.shot();

    return 0;
}
