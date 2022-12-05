//Malvestio Andrea Mat:2032464
#include <iostream>
#include <vector>

//DICHIARAZIONE FUNZIONI
void print(std::string,std::vector<int>);
std::vector<int> fibonacci(int, int, std::vector<int>, int);
void call_counter(void);

//--------------------------------------------------------------------------------------------

//variabili globali
int var=106;
int f;
static int counter=0; 	//variabile statica che servira' a tenere conto del numero di chiamate a call_counter()

//--------------------------------------------------------------------------------------------

int main(){
	int j; 		//variabile che contiene il numero di volte che verra' chiamata call_counter()
	static int b=2;
	static int c;
	int n=200;
	int x=1; 	//primo valore della sequenza di Fibonacci
	int y=2; 	//secondo valore della sequenza di Fibonacci
	std::vector<int> v; //vector che conterra' il risultato della funzione fibonacci()
	std::string s="Valori nel vettore: \n[ ";
	std::cout << "Esercitazione di laboratorio 1: " << std::endl;
	//ciclo che permette all'utente di reinserire il valore di x qualora esso non sia considerato valido
	while(true){
		std::cout << "Inserire il primo numero della sequenza di Fibonacci --> ";
		std::cin >> x;
		if(std::cin.fail()){	//funzione che permette di verificare se si � verificato un errore in input
			std::cout <<"Valore non valido "<<std::endl;
			std::cin.clear();
			std::cin.ignore(1000,'\n');
		}
		else{
			break;
		}
	}
	//ciclo che permette all'utente di reinserire il valore di y qualora esso non sia considerato valido
	while(true){
		std::cout << "Inserire il secondo numero della sequenza di Fibonacci --> ";
		std::cin >> y;
		if(std::cin.fail()){
			std::cout <<"Valore non valido "<<std::endl;
			std::cin.clear();
			std::cin.ignore(1000,'\n');
		}
		else{
			break;
		}
	}
	print(s,fibonacci(x, y, v, n));
	//ciclo che permette all'utente di reinserire il valore di j qualora esso non sia considerato valido
	while(true){
		std::cout << "Quante volte vuoi chiamare la funzione call_counter --> ";
		std::cin >> j;
		if(std::cin.fail()){
			std::cout <<"Valore non valido "<<std::endl;
			std::cin.clear();
			std::cin.ignore(1000,'\n');
		}
		else{
			break;
		}
	}
	for(int i=0;i<j;i++){
		call_counter();
	}
	return 0;
} 

//--------------------------------------------------------------------------------------------

//DEFINIZIONE FUNZIONI

//funzione print che stampa sullo standard input i valori contenuti in un vector passato come argomento
void print(std::string s, std::vector<int>  v){
	std::cout << s;
	for(int i=0;i<v.size();i++){
		if(i==v.size()-1){
			std::cout << v[i] << " ]\n" << std::endl;
		}
		else{
			std::cout << v[i] << ", ";
		}
	}
}

/*funzione che calcola la sequenza di fibonacci a partire da due numeri x e y forniti in input e li inserisce in un vector. 
* la funzione si ferma quando il numero di valori raggiunge n oppure quando il valore in posizione v[v.size()-1] corrisponde 
* alla massima somma rappresentabile in un int prima del verificarsi di un overflow
*/
std::vector<int> fibonacci(int x, int y, std::vector<int> v, int n){
	v.push_back(x);
	v.push_back(y);
	for(int i=2; i<n; i++){
		if( ( v[i-2]>=0 && v[i-1]>=0 ) && v[i-2]+v[i-1]>=0 ){	//se gli addendi sono entrambi positivi e la somma � positiva inserisce il valore nel vector
			v.push_back(v[i-2]+v[i-1]);
		}
		else if( ( v[i-2]<=0 && v[i-1]<=0 ) && v[i-2]+v[i-1]<=0 ){	//se gli addendi sono entrambi negativi e la somma � negativa inserisce il valore nel vector
			v.push_back(v[i-2]+v[i-1]);
		}
		else if( ( v[i-2]<0 && v[i-1]>0 ) || ( v[i-2]>0 && v[i-1]<0 ) ){	//se gli addendi sono discordi inserisce la somma nel vector
			v.push_back(v[i-2]+v[i-1]);
		}
		else{	//altrimenti vuol dire che si � verificato un overflow quindi esce dal ciclo e scarta il valore
			break;
		}
	}
	return v;
}

//funzione che conta quante chiamate vengono effettuate a se stessa attraverso l'utilizzo di una variabile statica
void call_counter(){
	++counter;
	std::cout << "la funzione call_counter e' stata chiamata " << counter << " volte" << std::endl;
}
