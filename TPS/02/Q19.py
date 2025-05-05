import random
import time
import copy
import matplotlib.pyplot as plt

# Classe para armazenar métricas
class SortMetrics:
    def __init__(self):
        self.comparisons = 0
        self.moves = 0

# Algoritmo: Selection Sort
def selection_sort(arr):
    metrics = SortMetrics()
    n = len(arr)
    for i in range(n):
        min_idx = i
        for j in range(i+1, n):
            metrics.comparisons += 1
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
        metrics.moves += 1
    return metrics

# Algoritmo: Insertion Sort
def insertion_sort(arr):
    metrics = SortMetrics()
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            metrics.comparisons += 1
            arr[j + 1] = arr[j]
            metrics.moves += 1
            j -= 1
        arr[j + 1] = key
        metrics.moves += 1
        if j >= 0:
            metrics.comparisons += 1
    return metrics

# Algoritmo: Bubble Sort
def bubble_sort(arr):
    metrics = SortMetrics()
    n = len(arr)
    for i in range(n):
        for j in range(0, n-i-1):
            metrics.comparisons += 1
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
                metrics.moves += 1
    return metrics

# Algoritmo: Quicksort
def quicksort(arr):
    metrics = SortMetrics()

    def _quicksort(items, low, high):
        if low < high:
            pi = partition(items, low, high)
            _quicksort(items, low, pi - 1)
            _quicksort(items, pi + 1, high)

    def partition(items, low, high):
        pivot = items[high]
        i = low - 1
        for j in range(low, high):
            metrics.comparisons += 1
            if items[j] < pivot:
                i += 1
                items[i], items[j] = items[j], items[i]
                metrics.moves += 1
        items[i + 1], items[high] = items[high], items[i + 1]
        metrics.moves += 1
        return i + 1

    _quicksort(arr, 0, len(arr) - 1)
    return metrics

# Configurações
sizes = [100, 1000, 10000, 100000]
algorithms = {
    "Selection Sort": selection_sort,
    "Insertion Sort": insertion_sort,
    "Bubble Sort": bubble_sort,
    "Quicksort": quicksort
}
results = {name: {"time": [], "comparisons": [], "moves": []} for name in algorithms}

# Execução dos testes
for size in sizes:
    print(f"\n🔍 Tamanho do vetor: {size}")
    original = [random.randint(0, 1000000) for _ in range(size)]

    for name, sort_func in algorithms.items():
        print(f"Executando {name}...")
        arr = copy.deepcopy(original)
        start = time.time()
        metrics = sort_func(arr)
        end = time.time()
        elapsed = (end - start) * 1000  # tempo em ms

        results[name]["time"].append(elapsed)
        results[name]["comparisons"].append(metrics.comparisons)
        results[name]["moves"].append(metrics.moves)

# Função para gerar gráficos
def plot_metric(metric_name, ylabel):
    for name in algorithms:
        plt.plot(sizes, results[name][metric_name], label=name, marker='o')
    plt.xlabel("Tamanho do vetor")
    plt.ylabel(ylabel)
    plt.title(f"{ylabel} x Tamanho do vetor")
    plt.legend()
    plt.xscale("log")
    plt.yscale("log")
    plt.grid(True)
    plt.savefig(f"{metric_name}.png")
    plt.clf()

# Geração dos gráficos
plot_metric("time", "Tempo de execução (ms)")
plot_metric("comparisons", "Número de comparações")
plot_metric("moves", "Número de movimentações")

print("\n✅ Análise finalizada. Gráficos salvos como 'time.png', 'comparisons.png' e 'moves.png'.")
