
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


	public void push(int x){
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

	public int maior_elemento(){
		int maior = topo.elemento;
		for(Celula i = topo; i != null; i = i.prox){
			if(i.elemento > maior){
				maior = i.elemento;
			}
		}
		return maior;
	}

	public void inverter() {
    Pilha aux = new Pilha();

    while (topo != null) {
        try {
            aux.push(pop());
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    topo = aux.topo;
}

 }

public class stack {
	public static void main(String[] args){
		Pilha p = new Pilha();
		p.push(10);
		p.push(1);
		p.push(50);
		p.show();
		
		p.inverter();
		p.show();
	}
}
