#include <iostream>
#include <string>

using namespace std;

void menuBanco() {
	
	cout << "---------- BANCO  ----------" << endl;
	cout << "	1. Visualizar Informacoes " << endl;
	cout << "	2. Fazer Saque	" << endl;
	cout << "	3. Fazer Deposito	" << endl;
	cout << "	4. Abrir Conta	" << endl;
	cout << "	5. Fechar Conta	" << endl;
	cout << "	6. Pagar Mensalidade	" << endl;
	cout << "			0. Sair		" << endl;
	cout << "----------       ----------" << endl;
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
		
		void mostrarInfos () {
			
			cout << "Nome do Titular: " << *dono << endl;
			cout << "Numero da Conta: " << *numConta << endl;
			cout << "Tipo da Conta: " << *tipo << endl;
			cout << "Saldo Atual: " << *saldo << endl;
			cout << "Status da Conta ( Aberta ou Fechada ): " << endl;
			
			if ( *status == true ) {
				
				cout << "Aberta" << endl;
			}
			else if ( *status == false ) {
				
				cout << "Fechada" << endl;
			}
			
		}
		
		void abrirConta( string novoTipo, string novoDono ) {
			
			if ( *status == true ) {
				
				cout << "Você já possui uma conta aberta." << endl;
				
				return;
			}
			
			if ( novoTipo == "CC" || novoTipo == "CP" ) {
			
				*dono = novoDono;
					
				*tipo = novoTipo;
				*status = true;
				
				if ( *tipo == "CC" ) {
					
					*saldo = 50;
				}
				
				if ( *tipo == "CP" ) {
					
					*saldo = 150;
				}
			}
			
			else {
				
				cout << "Tipo de conta Inválido, utilize apenas as siglas CC ou CP." << endl;
				
				*tipo = "Indefinido.";
				
				return;
			}
			// ao abrir a conta, deve mostrar o tipo. Se for cc, va ter 50 reais na conta, se for cp, vai ter 150 reais na conta
		}
		
		void fecharConta() {
			
			if ( *status == false ) {
				
				cout << "Você não tem uma conta aberta." << endl;
				
				return;
			}
			
			if ( *tipo == "CC" || *tipo == "CP" ) {
				
				if( *saldo > 0 ) {
					
					cout << "Não é possível fechar a conta, pois ainda há saldo." << endl;
					
					return;
				}
				
				if ( *saldo < 0 ) {
					
					cout << "Não é possível fechar a conta, pois há dívidas pendentes." << endl;
					
					return;
				}
				
				else{
					
					*status = false;
										
					cout << "Fechando conta." << endl;
				}
			}
			// para fechar a conta, não pode ter saldo ou débito
		}
		
		void depositar( double deposito ) {
		
			if ( *status == false ) {
				
				cout << "Você não tem uma conta aberta." << endl;
				
				return;
			}
			
			if ( deposito > 0 ) {
				
				*saldo = *saldo + deposito;
			}
			else{ 
			
				cout << "O valor zero não pode ser adicionado." << endl;
				
				return;
			}
			// para fazer depósito em uma conta, ela deve estar aberta ( status verdadeiro ) 
		}
		
		void sacar( double saque ) {
			
			if ( *status == false ) {
				
				cout << "Você não tem uma conta aberta." << endl;
				
				return;
			}
			
			if ( *saldo < saque ) {
				
				cout << "Não há saldo suficiente." << endl;
				
				return;
			}
			
			*saldo = *saldo - saque;
			cout << "Saque de R$" << saque << " efetuado com sucesso." << endl << endl;
				
			// para fazer saque de uma conta, ela deve estar aberta ( status verdadeiro ) e também preciso ter saldo suficiente
		}
		
		void pagarMensal() {
			
			if ( *status == false ) {
				
				cout << "Você não tem uma conta aberta." << endl;
				
				return;
			}
			
			if ( *status == true && *tipo == "CC" ) {
				
				if ( *saldo < 12 ) {
					
					cout << "Não há saldo suficiente para pagar a mensalidade." << endl;
					
					return;
				}
				else{
					
					*saldo = *saldo - 12;
					
					cout << "O pagamento mensal de R$12,00 foi efetuado com sucesso!" << endl;
				}
			}
			
			if ( *status == true && *tipo == "CP" ) {
				
				if ( *saldo < 20 ) {
					
					cout << "Não há saldo suficiente para pagar a mensalidade." << endl;
					
					return;
				}
				else{ 
				
					*saldo = *saldo - 20;
					
					cout << "O pagamento mensal de R$20,00 foi efetuado com sucesso!" << endl;
				}
			}	
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
		
		void set_tipo( string askTipo ) {
			
			if ( askTipo == "CC" || askTipo == "CP" ) {
				
				*tipo = askTipo;
			}	
		}
		
		string get_Dono() const {
			
			return *dono;
		}
		
		void set_Dono( string nomeDono ) {
			
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
		
		void set_Status( bool novoStatus ) {
			
			*status = novoStatus;
		}
		
	protected:
		string* tipo;
		
	private:
		int* numConta;
		string* dono;
		double* saldo;
		bool* status;
	
};

int main(int argc, char** argv) {
	
	ContaBanco minhaConta;
	
	int opcao;
	
	do{
		
		menuBanco();
	
		cout << "Selecione uma opcao: ";
		cin >> opcao;
		
		cout << endl;
		
		switch ( opcao ) {
			
			case 1: {
				
				minhaConta.mostrarInfos();
					
				break;
			}
			
			case 2: {
				
				double saque;
				
				cout << "Digite o valor que deseja sacar: ";
				cin >> saque;
				
				minhaConta.sacar(saque);
				
				cout << "Saldo atual de R$ " <<minhaConta.get_Saldo() << " " << endl;
				
				break;
			}
			
			case 3: {
				
				double deposito;
				
				cout << "Digite o valor que deseja depositar: ";
				cin >> deposito;
				
				minhaConta.depositar(deposito);
				
				cout << "Saldo atual de R$ " <<minhaConta.get_Saldo() << " " << endl;
				
				break;
			}
			
			case 4:{
				
				string novoDono;
				string novoTipo;
		
				cout << "Digite o tipo da conta: ";
				cin >> novoTipo;
				
				cin.ignore();
				
				cout << "Digite o seu nome completo (sem ascentos): ";
				getline(cin, novoDono);
				
				minhaConta.abrirConta(novoTipo, novoDono);
				
				cout << minhaConta.get_tipo();
				cout << minhaConta.get_Dono();
				
				break;
			}
			
			case 5: {
				
				cout << "Verificando..." << endl;
				
				minhaConta.fecharConta();
				
				break;
			}
			
			case 6: {
				
				cout << "Verificando...";
				
				minhaConta.pagarMensal();
				
				break;
			}
			
			case 0: {
				
				cout << "Saindo..." << endl;
				
				break;
			}
			
			default: {
				
				cout << "Opcao Invalida." << endl;
				
			}
			
		} 
			
	} while ( opcao != 0 );
	
	return 0;
}
