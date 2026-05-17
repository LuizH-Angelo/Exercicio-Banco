#include <iostream>

using namespace std;

void menuBanco() {
	
	cout << "---------- BANCO  ----------" << endl;
	cout << "	1. Visualizar Informações " << endl;
	cout << "	2. Fazer Saque	" << endl;
	cout << "	3. Fazer Depósito	" << endl;
	cout << "	4. Abrir Conta	" << endl;
	cout << "	5. Fechar Conta	" << endl;
	cout << "	6. Pagar Mensalidade	" << endl;
	cout << "			0. Sair		" << endl;
	cout << "----------       ----------"
}

class ContaBanco {
	
	public:
		
		ContaBanco() {
			
			numConta = new int(0);
			tipo = new string("");
			dono = new string("");
			saldo = new double(0.0);
			status = new bool(false);
		}
		
		~ContaBanco() {
			
			delete numConta;
			delete tipo;
			delete dono;
			delete saldo;
			delete status;
			
		}
		
		void abrirConta() {
			
			// ao abrir a conta, deve mostrar o tipo. Se for cc, va ter 50 reais na conta, se for cp, vai ter 150 reais na conta
		}
		
		void fecharConta() {
			
			// para fechar a conta, não pode ter saldo ou débito
		}
		
		void depositar() {
		
			// para fazer depósito em uma conta, ela deve estar aberta ( status verdadeiro ) 
		}
		
		void sacar() {
			
			// para fazer saque de uma conta, ela deve estar aberta ( status verdadeiro ) e também preciso ter saldo suficiente
		}
		
		void pagarMensal() {
			
			// quando o método for chamado, o cliente com cc vai pagar 12 reais de mensalidade, já o cliente com cp vai pagar 20
		}
		
		//Metodos Getters e Setters
		
		int get_numConta() const {
		
			return *numConta;
		}
		
		void set_numConta( int newNum ) {
			
			*numConta = newNum;
		}
		
		string get_tipo() const {
			
			return *tipo;
		}
		
		void set_tipo( char askTipo ) {
			
			if ( newTipo == "CC" || newTipo == "CP" ) {
				
				*tipo = newTipo
			}	
		}
		
		string get_Dono() const {
			
			return *nomeDono;
		}
		
		void set_Dono( char nomeDono ) {
			
			*dono = nomeDono;
		}
		
		double get_Saldo() const {
			
			return *saldo;
		}
		
		void set_Saldo( double novoSaldo) {
			
			*saldo = novoSaldo;
		}
		
		bool get_Status() const {
			
			return *status;
		}
		
		set_Status( bool novoStatus ) {
			
			*status = novoStatus
		}
		
	protected:
		*string tipo;
		
	private:
		int* numConta;
		string* dono;
		double* saldo;
		bool* status;
	
};

int main(int argc, char** argv) {
	
	int opcao;
	
	menuBanco();
	
	switch ( opcao ) {
		
		case 1: {
			break;
		}
		
		case 2: {
			
			break;
		}
		
		case 3: {
			
			break;
		}
		
		case 4:{
			
			break;
		}
		
		case 5: {
			
			break;
		}
		
		case 6: {
			
			break;
		}
		
		case 0: {
			
			break;
		}
	}
	
	return 0;
}
