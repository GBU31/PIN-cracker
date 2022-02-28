#include "adb/adb.cpp"


int main(){
    ADB adb;
    string pl; 
    adb.start_adb();
    cout << "pin list:";
    cin >> pl;
    system("clear");
    adb.cracker(pl);
}
