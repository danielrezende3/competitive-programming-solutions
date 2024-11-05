from typing import List, Tuple

Point = Tuple[int, int]
Square = Tuple[Point, Point]


def parser():
    data = List(input().split(" "))
    for number in data:
        if len(number) > 0:
            yield (number)


input_parser = parser()


def get_word():
    global input_parser
    return next(input_parser)


def get_number():
    data = get_word()
    try:
        return int(data)
    except ValueError:
        return float(data)


Point = tuple[int, int]
Square = tuple[Point, Point]


def criar_pontos(N: int, K: int, L: int) -> List[Square]:
    return [((i * K - L, i * K - L), (i * K + L, i * K + L)) for i in range(N)]


def ponto_esta_no_quadrado(ponto: Point, quadrado: Square) -> bool:
    (x_min, y_min), (x_max, y_max) = quadrado
    x, y = ponto
    return x_min <= x <= x_max and y_min <= y <= y_max


def calcular_area_quadrado(quadrado: Square) -> int:
    (ponto1, ponto2) = quadrado
    largura = ponto2[0] - ponto1[0]
    altura = ponto2[1] - ponto1[1]
    return largura * altura


def obter_limites(quadrados: List[Square]) -> Square:
    menor_x = min(x1 for (x1, _), _ in quadrados)
    maior_x = max(x2 for _, (x2, _) in quadrados)
    menor_y = min(y1 for (_, y1), _ in quadrados)
    maior_y = max(y2 for _, (_, y2) in quadrados)
    return (menor_x, menor_y), (maior_x, maior_y)


def calcular_area_quadrados_livre(quadrados: List[Square]) -> int:
    return sum(calcular_area_quadrado(quadrado) for quadrado in quadrados)


def soma_de_n_pra_1(n: int) -> int:
    return n * (n + 1) // 2


def calcular_area_quadrados_coincidem(
    quadrados: List[Square],
) -> int:
    menor_ponto, maior_ponto = obter_limites(quadrados)
    area_total = calcular_area_quadrado((menor_ponto, maior_ponto))
    squares = soma_de_n_pra_1(len(quadrados) - 1) * 2  # above and below
    return area_total - squares


def apply_formula(N: int, K: int, L: int) -> int:
    quadrados = criar_pontos(N, K, L)
    if len(quadrados) == 1:
        return calcular_area_quadrado(quadrados[0])
    elif ponto_esta_no_quadrado(quadrados[1][0], quadrados[0]):
        return calcular_area_quadrados_coincidem(quadrados)
    else:
        return calcular_area_quadrados_livre(quadrados)


assert apply_formula(4, 1, 2) == 37
assert apply_formula(3, 3, 1) == 12
assert apply_formula(1, 1, 50000) == 10000000000

N = get_number()
K = get_number()
L = get_number()

print(apply_formula(N, K, L))
