import matplotlib.pyplot as plt

# Dados dos seus testes
tamanhos = [100, 1000, 10000]
cenarios = ["Ordenado", "Quase Ordenado", "Aleatorio"]
estrategias = ["FirstPivot", "LastPivot", "RandomPivot", "MedianOfThree", "QuickWithInsertion"]

tempos = {
    "Ordenado": {
        "FirstPivot":    [0.064, 1.455, 28.695],
        "LastPivot":     [0.054, 1.250, 23.484],
        "RandomPivot":   [0.183, 0.108, 0.317],
        "MedianOfThree": [0.020, 0.147, 0.094],
        "QuickWithInsertion": [0.014, 0.099, 0.518],
    },
    "Quase Ordenado": {
        "FirstPivot":    [0.040, 0.081, 0.322],
        "LastPivot":     [0.056, 0.074, 0.599],
        "RandomPivot":   [0.082, 0.076, 0.435],
        "MedianOfThree": [0.029, 0.072, 0.299],
        "QuickWithInsertion": [0.011, 0.101, 0.628],
    },
    "Aleatorio": {
        "FirstPivot":    [0.021, 0.105, 0.635],
        "LastPivot":     [0.026, 0.102, 0.638],
        "RandomPivot":   [0.084, 0.128, 0.876],
        "MedianOfThree": [0.046, 0.110, 0.673],
        "QuickWithInsertion": [0.020, 0.122, 0.918],
    }
}

for cenario in cenarios:
    plt.figure(figsize=(8,5))
    for estrategia in estrategias:
        plt.plot(tamanhos, tempos[cenario][estrategia], marker='o', label=estrategia)
    plt.title(f"Tempo de execução - {cenario}")
    plt.xlabel("Tamanho do array")
    plt.ylabel("Tempo (ms)")
    plt.xscale("log")
    plt.yscale("log")
    plt.legend()
    plt.grid(True, which="both", ls="--")
    plt.tight_layout()
    nome_arquivo = f"quicksort_{cenario.lower().replace(' ', '_')}.png"
    plt.savefig(nome_arquivo)
    plt.close()
