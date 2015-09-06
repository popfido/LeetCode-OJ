#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int N,M;
double sum_of_elem;
vector<vector<double> > x;
vector<double> y;
bool flag, manySolutionsFlag;

// Test Printer
void printVector(std::vector<double>& vec)
{
    for (int a : vec)
        std::cout << a << " ";
}

int main(){
    cin >> N >> M;
    y = vector<double>(M);
    x = vector<vector<double> >(M,vector<double>(N,0));
    for(int i=0;i<M;i++){
        for (int j=0;j<N;j++){
            cin >> x[i][j];
        }
        cin >> y[i];
    }

    manySolutionsFlag = false;

    for(int i=0;i<N;i++){
        bool flag = false;
        for(int j=i;j<M;j++){
            if(x[j][i] != 0){
                x[j].swap(x[i]);
                flag = true;
                break;
            }
        }
        if(not flag){
            manySolutionsFlag = true;
            continue;
        }
        for(int j=i+1;j<M;j++){
            for(int t=0;t<N;t++)
                x[j][t] -= 1.0 * x[i][t]*(x[j][i]/x[i][i]);
            y[j] -= 1.0 * y[i]*(x[j][i]/x[i][i]);
        }
    }

    for(int i=0; i<M;i++){
        sum_of_elem = 0;
        for(auto j: x[i])
            sum_of_elem += j;
        if(!sum_of_elem && (y[i] != 0)){
            cout << "No solutions" << endl;
            return 0;
        }
    }

    if(manySolutionsFlag){
        cout << "Many solutions" << endl;
        return 0;
    }

    for(int i=N-1;i>=0; i--)
    {
        for(int j=i+1;j<N;j++){
            y[i] -= 1.0 * x[i][j] * y[j]/x[j][j];
            x[i][j] = 0;
        }
        cout << y[i]/x[i][i] << endl;
    }
    return 0;
}
