#include <iostream>
using namespace std;
#define TAM 20
template <class T>
class Lista{
    private:
        T *Vet;
        int Tamanho, Fim;
    public: 
        Lista(const int &tam){
            Tamanho = tam;
            Vet = new T[Tamanho];
            Fim = -1;
        }
        ~Lista(){
            delete [] Vet;
        }
        bool AdicionarNoFim(const T &valor){
            if(Fim<Tamanho-1){
                ++Fim;
                Vet[Fim]=valor;
                return true;
            }else{
                return false;
            }
        }
        bool AdicionarNoComeco(const T &valor){
            if(Fim<Tamanho-1){
                int aj = Fim;
                while(aj >= 0){
                    Vet[aj+1] = Vet[aj];
                    aj--;
                }
                Vet[0] = valor;
                Fim++;
                return true;
            }else{
                return false;
            }
        }
        bool AdicionarNoMeio(const T &valor, const int &pos){
            if(Fim<Tamanho-1){
                int aj = Fim;
                while(aj >= pos){
                    Vet[aj+1] = Vet[aj];
                    aj--;
                }
                Vet[pos] = valor;
                Fim++;
                return true;
            }else{
                return false;
            }
        }
        bool RemoverDoFim(){
            if(Fim == -1){
                return false;
            }else{
                Fim--;
                return true;
            }
        }
        bool RemoverDoInicio(){
           if(Fim<Tamanho-1){
                for(int i = 0; i < Fim; i++){
                    Vet[i] = Vet[i+1];
                }
                Fim--;
                return true;
            }else{
                return false;
            }            
        }
        bool RemoverDoMeio(int const &pos){
            if(Fim>pos){
                for(int i = pos; i < Fim; i++){
                    Vet[i] = Vet[i+1];
                }
                Fim--;
                return true;                
            }else{
                return false;
            }
        }        
        void Mostrar(){
            cout<<"[";
            for(int i = 0; i <= Fim; i++){
                cout<<" "<<Vet[i];
            }
            cout<<" ]"<<endl;
        }
        T MostrarDoMeio(int const &pos){
            if(pos<Fim){
                return Vet[pos];
            }else{
                cout<<"Essa posição não existe no Vetor"<<endl;
            }
            
        }
        int RetornarTamanho(){
            return Fim;
        }
};


int main(){
    Lista<int> L(20);
    for(int i = 0; i<100; i++){
        L.AdicionarNoFim(i);
    }
    cout<<L.RetornarTamanho()<<endl;
    L.Mostrar();
    L.RemoverDoMeio(69);
    L.RemoverDoInicio();
    L.MostrarDoMeio(0);
    L.Mostrar();
    return 0;
}