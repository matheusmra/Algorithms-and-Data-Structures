
a,b,c = input().split()
pi = 3.14159
a_triangulo = (float(a) * float(c)) / 2
a_circ = pi * (float(c)*float(c))
a_trapezio = ((float(a)+float(b)) * float(c)) / 2
a_quadrado = float(b)*float(b)
a_retangulo = (float(a)*float(b))
print(f"TRIANGULO: {a_triangulo:.3f}")
print(f"CIRCULO: {a_circ:.3f}")
print(f"TRAPEZIO: {a_trapezio:.3f}")
print(f"QUADRADO: {a_quadrado:.3f}")
print(f"RETANGULO: {a_retangulo:.3f}")