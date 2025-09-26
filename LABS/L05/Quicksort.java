package L05;

/**
 * Algoritmo de ordenacao Quicksort com diferentes estratégias de pivô
 * 
 * @author Max do Val Machado + adaptações Matheus de Almeida Moreira
 */
class Quicksort extends Geracao {

    /**
     * Construtor.
     */
    public Quicksort() {
        super();
    }

    /**
     * Construtor.
     * 
     * @param int tamanho do array de numeros inteiros.
     */
    public Quicksort(int tamanho) {
        super(tamanho);
    }

    /**
     * Algoritmo de ordenacao Quicksort.
     */
    // 1. Pivô: Primeiro elemento
    public void quicksortFirstPivot(int esq, int dir) {
        int i = esq, j = dir;
        int pivo = array[esq];
        while (i <= j) {
            while (array[i] < pivo)
                i++;
            while (array[j] > pivo)
                j--;
            if (i <= j) {
                swap(i, j);
                i++;
                j--;
            }
        }
        if (esq < j)
            quicksortFirstPivot(esq, j);
        if (i < dir)
            quicksortFirstPivot(i, dir);
    }

    // 2. Pivô: Último elemento
    public void quicksortLastPivot(int esq, int dir) {
        int i = esq, j = dir;
        int pivo = array[dir];
        while (i <= j) {
            while (array[i] < pivo)
                i++;
            while (array[j] > pivo)
                j--;
            if (i <= j) {
                swap(i, j);
                i++;
                j--;
            }
        }
        if (esq < j)
            quicksortLastPivot(esq, j);
        if (i < dir)
            quicksortLastPivot(i, dir);
    }

    // 3. Pivô: Aleatório
    public void quicksortRandomPivot(int esq, int dir) {
        int i = esq, j = dir;
        int randomIndex = esq + (int) (Math.random() * (dir - esq + 1));
        int pivo = array[randomIndex];
        while (i <= j) {
            while (array[i] < pivo)
                i++;
            while (array[j] > pivo)
                j--;
            if (i <= j) {
                swap(i, j);
                i++;
                j--;
            }
        }
        if (esq < j)
            quicksortRandomPivot(esq, j);
        if (i < dir)
            quicksortRandomPivot(i, dir);
    }

    // 4. Pivô: Mediana de três (início, meio, fim)
    public void quicksortMedianOfThree(int esq, int dir) {
        int i = esq, j = dir;
        int meio = (esq + dir) / 2;
        // Ordena esq, meio, dir
        if (array[esq] > array[meio])
            swap(esq, meio);
        if (array[esq] > array[dir])
            swap(esq, dir);
        if (array[meio] > array[dir])
            swap(meio, dir);
        int pivo = array[meio];
        while (i <= j) {
            while (array[i] < pivo)
                i++;
            while (array[j] > pivo)
                j--;
            if (i <= j) {
                swap(i, j);
                i++;
                j--;
            }
        }
        if (esq < j)
            quicksortMedianOfThree(esq, j);
        if (i < dir)
            quicksortMedianOfThree(i, dir);
    }

    // Extra: QuickSort com Insertion Sort para subarrays pequenos
    public void quicksortWithInsertion(int esq, int dir) {
        int LIMITE = 16; // Tamanho limite para usar Insertion Sort
        if (dir - esq + 1 <= LIMITE) {
            insertionSort(esq, dir);
        } else {
            int i = esq, j = dir;
            int pivo = array[(esq + dir) / 2];
            while (i <= j) {
                while (array[i] < pivo)
                    i++;
                while (array[j] > pivo)
                    j--;
                if (i <= j) {
                    swap(i, j);
                    i++;
                    j--;
                }
            }
            if (esq < j)
                quicksortWithInsertion(esq, j);
            if (i < dir)
                quicksortWithInsertion(i, dir);
        }
    }

    // Método auxiliar: Insertion Sort para um subarray
    private void insertionSort(int esq, int dir) {
        for (int i = esq + 1; i <= dir; i++) {
            int tmp = array[i];
            int j = i - 1;
            while (j >= esq && array[j] > tmp) {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = tmp;
        }
    }
}