#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;



void reading(const int N, double* p, const string noisy);
void filter(const int N, double* p, const string noisy);
void output(const int N, double* p);

int main(){
 const int N = 237;
 int n;
 double* p = new double [n];
 const string noisy = "noisy.txt";
 
 reading(N,p,noisy);
 filter(N,p,noisy);
 output(N,p);
delete[] p; 
return 0;
}

void reading(const int N, double* p, const string noisy){
  
  ifstream in(noisy.c_str());
  
  for (int i = 0; i < N; i++){ 
  in >> p[i];
  }
  in.close();
}
void filter(const int N, double* p, const string noisy){
  
  double altp, neup = p[N-1];
 for(int j = 0; j<4; j++){
  for(int i = 0; i<N; i++){
    altp = p[i];
    p[i] = (neup + p[i] + p[i+1])/3.0;
    neup = altp;
  }
 }
   
}
  
void output(const int N, double* p){
ofstream out("filtered.txt");

for(int i = 0; i < N; i++) out << p[i] << endl;

out.close();
}



