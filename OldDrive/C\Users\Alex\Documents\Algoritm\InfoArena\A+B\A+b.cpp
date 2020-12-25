#include <fstream>
using namespace std;
int main(){
    int a,b;
    ofstream fout("adunare.out");
    ifstream fin("adunare.in");
    fin>>a>>b;
    fout<<(a+b);
    fin.close();
    fout.close();
}
