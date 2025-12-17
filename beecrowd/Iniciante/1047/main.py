hi, mi, hf, mf = map(int, input().split())
inicio = hi * 60 + mi
fim = hf * 60 + mf
duracao = fim - inicio
if duracao <= 0:
    duracao += 24 * 60
horas = duracao // 60
minutos = duracao % 60
print(f"O JOGO DUROU {horas} HORA(S) E {minutos} MINUTO(S)")
