#include "../include/posfixa.hpp"

int posfixa(Fila<char>& entrada) {

    Pilha<int> pilha(entrada.capacidade);
    
    while (!entrada.esta_vazia()) {
      char token = entrada.desenfileirar();
  
      if (isdigit(token)) {
        pilha.empilhar(token - '0');

      } else if (token == '+' || token == '-' || token == '*' || token == '/') {
        
        if (pilha.esta_vazia()) throw std::runtime_error("Faltam operandos");
        int b = pilha.desempilhar();
        
        if (pilha.esta_vazia()) throw std::runtime_error("Faltam operandos");
        int a = pilha.desempilhar();
  
        int resultado;
        switch (token) {

          case '+': 
          resultado = a + b; 
          break;

          case '-': 
          resultado = a - b; 
          break;

          case '*': 
          resultado = a * b; 
          break;

          case '/':
            if (b == 0) throw std::runtime_error("Divisão por zero");
            resultado = a / b;
            break;
            
          default:
            throw std::runtime_error("Operador inválido");
        }
  
        pilha.empilhar(resultado);
      } else {
        throw std::runtime_error("Token inválido");
      }
    }
  
    if (pilha.esta_vazia()) throw std::runtime_error("Expressão inválida");
  
    int resultado = pilha.desempilhar();
  
    if (!pilha.esta_vazia()) throw std::runtime_error("Operandos em excesso");
  
    return resultado;
  }
  