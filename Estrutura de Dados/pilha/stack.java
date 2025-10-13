
class Celula {
	public int elemento; // Elemento inserido na celula.
	public Celula prox; // Aponta a celula prox.

	/**
	 * Construtor da classe.
	 */
	public Celula() {
		this(0);
	}

	/**
	 * Construtor da classe.
	 * 
	 * @param elemento int inserido na celula.
	 */
	public Celula(int elemento) {
		this.elemento = elemento;
		this.prox = null;
	}
}

class Pilha {
	private Celula topo;

	public Pilha() {
		topo = null;
	}

	public void push(int x) {
		Celula tmp = new Celula(x);
		tmp.prox = topo;
		topo = tmp;
		tmp = null;

	}

	public int pop() throws Exception {
		if (topo == null) {
			throw new Exception("Erro ao remover!");
		}
		int resp = topo.elemento;
		Celula tmp = topo;
		topo = topo.prox;
		tmp.prox = null;
		tmp = null;
		return resp;
	}

	public void show() {
		System.out.print("[ ");
		for (Celula i = topo; i != null; i = i.prox) {
			System.out.print(i.elemento + " ");
		}
		System.out.println("] ");
	}

	public int soma_elementos() {
		int soma = 0;
		for (Celula i = topo; i != null; i = i.prox) {
			soma += i.elemento;
		}
		return soma;
	}

	public int soma_recursiva(Celula i) {
		if (i.prox == null) {
			return 0;
		}
		return i.elemento + soma_recursiva(i.prox);

	}

	public int maior_elemento() {
		int maior = topo.elemento;
		for (Celula i = topo; i != null; i = i.prox) {
			if (i.elemento > maior) {
				maior = i.elemento;
			}
		}
		return maior;
	}

	public int maior_recursivo(Celula i) {
		if (i == null) {
			return 0;
		}
		int maiorRestante = maior_recursivo(i.prox);

		return (i.elemento > maiorRestante) ? i.elemento : maiorRestante;

	}


	public void mostrar_ordem_insercao(){
		Pilha aux = new Pilha();
		for(Celula i = topo; i !=null; i = i.prox){
			aux.push(i.elemento);
		}
		for(Celula j = aux.topo; j != null; j = j.prox){
			System.out.println(j.elemento);
		}
	}

}

public class stack {
	public static void main(String[] args) {
		Pilha p = new Pilha();
		p.push(10);
		p.push(1);
		p.push(50);
		p.show();

		p.show();
	}
}
